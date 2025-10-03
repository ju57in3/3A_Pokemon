//
// Created by justine on 03/10/2025.
//

#include "BattleState.h"
#include "Game.h"
#include "ResultsState.h"
#include "PauseState.h"
#include <random>
#include <cstdio>
#include <stdexcept>

static std::mt19937& rng() { static std::mt19937 r{std::random_device{}()}; return r; }

static std::string id3(int id) {
    char buf[8];
    std::snprintf(buf, sizeof(buf), "%03d", id);
    return std::string(buf);
}

static std::string pathFromId(int id) {
    return "/home/justine/CLionProjects/project/pokemon/" + id3(id) + ".png";
}

void BattleState::enter(Game& g) {
    font.loadFromFile("/home/justine/CLionProjects/project/OpenSans-Regular.ttf");
    gaugeTex.loadFromFile("/home/justine/CLionProjects/project/healthGauge.png");
    versusTex.loadFromFile("/home/justine/CLionProjects/project/versusSmall.png");

    auto ids = g.pokedex.allIds();
    std::uniform_int_distribution<int> pick(0, (int)ids.size()-1);
    enemyTeam.clear();
    while (enemyTeam.size() < 6) {
        if (auto p = g.pokedex.cloneById(ids[pick(rng())])) enemyTeam.push_back(std::move(p));
    }

    hbAlly = std::make_unique<HealthBar>(gaugeTex);
    hbEnemy = std::make_unique<HealthBar>(gaugeTex);
    hbAlly->setPosition(80, 520);
    hbEnemy->setPosition(760, 120);

    iAlly = iEnemy = 0;
    finished = false;
    nextAliveIndices(g);
    loadCurrentSprites(g);
}

void BattleState::nextAliveIndices(Game& g) {
    while (iAlly < (int)g.team.size()  && g.team.at(iAlly).isFainted())  ++iAlly;
    while (iEnemy < (int)enemyTeam.size() && enemyTeam[iEnemy]->isFainted()) ++iEnemy;

    if (iAlly >= (int)g.team.size()) { endBattle(g, false); return; }
    if (iEnemy >= (int)enemyTeam.size()) { endBattle(g, true); return; }

    hbAlly->setMax(g.team.at(iAlly).maxHP);
    hbAlly->setValue(g.team.at(iAlly).hp);
    hbEnemy->setMax(enemyTeam[iEnemy]->maxHP);
    hbEnemy->setValue(enemyTeam[iEnemy]->hp);
}

void BattleState::loadCurrentSprites(Game& g) {
    const Pokemon& A = g.team.at(iAlly);
    if (!allyTex.loadFromFile(pathFromId(A.id))) {
        throw std::runtime_error("Sprite missing: " + pathFromId(A.id));
    }
    allySpr.setTexture(allyTex);
    allySpr.setScale(2.f, 2.f);      // zoom x2
    allySpr.setPosition(120.f, 340.f);

    const Pokemon& B = *enemyTeam[iEnemy];
    if (!enemyTex.loadFromFile(pathFromId(B.id))) {
        throw std::runtime_error("Sprite missing: " + pathFromId(B.id));
    }
    enemySpr.setTexture(enemyTex);
    enemySpr.setScale(-2.f, 2.f);
    enemySpr.setOrigin((float)enemyTex.getSize().x, 0.f);
    enemySpr.setPosition(980.f, 120.f);

    lastLog = "Press A to attack | P: Pause | Esc: Quit";
}

void BattleState::endBattle(Game& g, bool allyWon) {
    if (finished) return;
    finished = true;
    g.changeState(std::make_unique<ResultsState>(allyWon));
}

void BattleState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::P) {
            g.pause();
            return;
        }
        if (e.key.code == sf::Keyboard::Escape) {
            endBattle(g, false);
            return;
        }
        if (e.key.code == sf::Keyboard::A && !finished) {
            auto& A = g.team.at(iAlly);
            auto& B = *enemyTeam[iEnemy];
            if (A.speed >= B.speed) {
                int d1 = A.attack(B);
                lastLog = A.name + " hits " + B.name + " for " + std::to_string(d1);
                hbEnemy->setValue(B.hp);
                if (B.isFainted()) { lastLog += " (KO)"; nextAliveIndices(g); return; }
                int d2 = B.attack(A);
                lastLog += " | " + B.name + " hits back " + std::to_string(d2);
                hbAlly->setValue(A.hp);
                if (A.isFainted()) { lastLog += " (KO)"; nextAliveIndices(g); return; }
            } else {
                int d1 = B.attack(A);
                lastLog = B.name + " hits " + A.name + " for " + std::to_string(d1);
                hbAlly->setValue(A.hp);
                if (A.isFainted()) { lastLog += " (KO)"; nextAliveIndices(g); return; }
                int d2 = A.attack(B);
                lastLog += " | " + A.name + " hits back " + std::to_string(d2);
                hbEnemy->setValue(B.hp);
                if (B.isFainted()) { lastLog += " (KO)"; nextAliveIndices(g); return; }
            }
        }
    }
}

void BattleState::render(Game& g) {
    // Noms
    if (iAlly < (int)g.team.size()) {
        sf::Text ta(g.team.at(iAlly).name, font, 24);
        ta.setPosition(80, 480);
        g.window.draw(ta);
    }
    if (iEnemy < (int)enemyTeam.size()) {
        sf::Text tb(enemyTeam[iEnemy]->name, font, 24);
        tb.setPosition(760, 80);
        g.window.draw(tb);
    }

    g.window.draw(allySpr);
    g.window.draw(enemySpr);

    if (hbAlly) hbAlly->draw(g.window);
    if (hbEnemy) hbEnemy->draw(g.window);

    sf::Sprite vs(versusTex);
    vs.setPosition(560, 300);
    g.window.draw(vs);

    sf::Text log(lastLog, font, 18);
    log.setPosition(40, 660);
    g.window.draw(log);
}