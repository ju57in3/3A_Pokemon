//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_SELECTIONSTATE_H
#define PROJECT_SELECTIONSTATE_H

#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>

class SelectionState : public GameState {
public:
    void enter(Game&) override;
    void handleEvent(Game&, const sf::Event&) override;
    void update(Game&, float) override {}
    void render(Game&) override;
    void exit(Game&) override {}
private:
    sf::Font font;
    std::vector<int> ids;
    int cursor = 0;
};


#endif //PROJECT_SELECTIONSTATE_H