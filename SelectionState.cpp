//
// Created by justine on 03/10/2025.
//

#include "SelectionState.h"
#include "Game.h"
#include "BattleState.h"
#include "MainMenuState.h"
#include <algorithm>
#include <memory>

void SelectionState::enter(Game& g) {
    font.loadFromFile("/home/justine/CLionProjects/project/OpenSans-Regular.ttf");

    if (g.party.size() == 0) {
        ids = g.pokedex.allIds();
        int take = std::min<int>(60, ids.size());
        for (int i=0;i<take;i++) {
            if (auto p = g.pokedex.cloneById(ids[i])) g.party.add(std::move(p));
        }
    } else {
        ids.clear();
        for (size_t i=0;i<g.party.size();++i) ids.push_back(g.party.at(i).id);
    }
    cursor = 0;
    while (g.team.size() > 0) g.team.remove(0);
}

void SelectionState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Escape) {
            extern std::unique_ptr<GameState> makeMainMenu();
            g.changeState(std::make_unique<MainMenuState>());
        }
        if (e.key.code == sf::Keyboard::Up)   cursor = (cursor + (int)ids.size()-1) % (int)ids.size();
        if (e.key.code == sf::Keyboard::Down) cursor = (cursor + 1) % (int)ids.size();

        if (e.key.code == sf::Keyboard::Space) {
            int id = ids[cursor];
            int idxInParty = -1;
            for (size_t i=0;i<g.party.size();++i) if (g.party.at(i).id == id) { idxInParty = (int)i; break; }

            int idxInTeam = -1;
            for (size_t i=0;i<g.team.size();++i) if (g.team.at(i).id == id) { idxInTeam = (int)i; break; }

            if (idxInTeam >= 0) {
                auto p = g.team.remove(idxInTeam);
                if (p) g.party.add(std::move(p));
            } else if (g.team.size() < g.team.MaxSize && idxInParty >= 0) {
                auto p = g.party.remove((size_t)idxInParty);
                if (p) g.team.add(std::move(p));
            }
        }

        if (e.key.code == sf::Keyboard::Enter) {
            if (g.team.size() == g.team.MaxSize) {
                g.changeState(std::make_unique<BattleState>());
            }
        }
    }
}

void SelectionState::render(Game& g) {
    sf::Text title("Select your team (6 max). Space=toggle, Enter=Start", font, 24);
    title.setPosition(20, 20);
    g.window.draw(title);

    const float leftX = 20.f, topY = 70.f;
    for (size_t i=0;i<ids.size();++i) {
        const bool selected = (int)i == cursor;
        std::string name = g.pokedex.cloneById(ids[i])->name;
        sf::Text t(name, font, 20);
        t.setPosition(leftX, topY + i*22.f);
        if (selected) t.setStyle(sf::Text::Underlined);
        bool inTeam=false;
        for (size_t k=0;k<g.team.size();++k) if (g.team.at(k).id == ids[i]) { inTeam=true; break; }
        if (inTeam) t.setString("★ " + name);
        g.window.draw(t);
        if (i>40) break;
    }

    sf::Text t2("TEAM:", font, 24);
    t2.setPosition(600, 70);
    g.window.draw(t2);
    for (size_t i=0;i<g.team.size();++i) {
        sf::Text tt(g.team.at(i).name, font, 20);
        tt.setPosition(600, 110 + i*24);
        g.window.draw(tt);
    }
    sf::Text count("Count: " + std::to_string(g.team.size()) + "/6", font, 20);
    count.setPosition(600, 110 + 7*24);
    g.window.draw(count);
}