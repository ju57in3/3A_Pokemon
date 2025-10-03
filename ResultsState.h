//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_RESULTSSTATE_H
#define PROJECT_RESULTSSTATE_H

#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>

class ResultsState : public GameState {
public:
    explicit ResultsState(bool allyWon) : win(allyWon) {}
    void enter(Game&) override;
    void handleEvent(Game&, const sf::Event&) override;
    void update(Game&, float) override {}
    void render(Game&) override;
    void exit(Game&) override {}
private:
    bool win;
    sf::Font font;
};

#endif //PROJECT_RESULTSSTATE_H