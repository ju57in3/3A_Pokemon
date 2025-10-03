//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_PAUSESTATE_H
#define PROJECT_PAUSESTATE_H

#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <memory>

class PauseState : public GameState {
public:
    explicit PauseState(std::unique_ptr<GameState> stored)
    : stored_(std::move(stored)) {}
    void enter(Game&) override;
    void handleEvent(Game&, const sf::Event&) override;
    void update(Game&, float) override {}
    void render(Game&) override;
    void exit(Game&) override {}
private:
    std::unique_ptr<GameState> stored_;
    sf::Font font;
};

#endif //PROJECT_PAUSESTATE_H