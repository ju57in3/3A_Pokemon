//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_GAMESTATE_H
#define PROJECT_GAMESTATE_H

#pragma once
#include <SFML/Graphics.hpp>
class Game;
struct GameState {
    virtual ~GameState() = default;
    virtual void enter(Game&) = 0;
    virtual void handleEvent(Game&, const sf::Event&) = 0;
    virtual void update(Game&, float dt) = 0;
    virtual void render(Game&) = 0;
    virtual void exit(Game&) = 0;
};

#endif //PROJECT_GAMESTATE_H