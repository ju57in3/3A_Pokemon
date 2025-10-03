//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_BATTLESTATE_H
#define PROJECT_BATTLESTATE_H

#pragma once
#include "GameState.h"
#include "HealthBar.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Pokemon.h"

class BattleState : public GameState {
public:
    void enter(Game&) override;
    void handleEvent(Game&, const sf::Event&) override;
    void update(Game&, float) override {}
    void render(Game&) override;
    void exit(Game&) override {}

private:
    sf::Font font;
    std::vector<std::unique_ptr<Pokemon>> enemyTeam;
    int iAlly = 0, iEnemy = 0;
    std::unique_ptr<HealthBar> hbAlly, hbEnemy;
    sf::Texture gaugeTex, versusTex;
    sf::Texture allyTex, enemyTex;
    sf::Sprite  allySpr, enemySpr;
    std::string lastLog = "Press A to attack";
    bool finished = false;

    void nextAliveIndices(Game& g);
    void endBattle(Game& g, bool allyWon);
    void loadCurrentSprites(Game& g);
};


#endif //PROJECT_BATTLESTATE_H