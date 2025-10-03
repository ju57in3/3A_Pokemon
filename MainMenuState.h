//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_MAINMENUSTATE_H
#define PROJECT_MAINMENUSTATE_H

#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class MainMenuState : public GameState {
public:
    void enter(Game&) override;
    void handleEvent(Game&, const sf::Event&) override;
    void update(Game&, float) override {}
    void render(Game&) override;
    void exit(Game&) override {}
private:
    sf::Font font;
    std::vector<std::string> items = {"Start", "Quit"};
    int selected = 0;
};

#endif //PROJECT_MAINMENUSTATE_H