//
// Created by justine on 03/10/2025.
//

#include "ResultsState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "SelectionState.h"
#include <memory>

void ResultsState::enter(Game& g) { font.loadFromFile("/home/justine/CLionProjects/project/OpenSans-Semibold.ttf"); }

void ResultsState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Enter) {
            g.changeState(std::make_unique<MainMenuState>());
        }
        if (e.key.code == sf::Keyboard::S) {
            g.changeState(std::make_unique<SelectionState>());
        }
    }
}

void ResultsState::render(Game& g) {
    sf::Text t(win ? "YOU WIN!" : "YOU LOSE!", font, 64);
    t.setPosition(420, 250);
    g.window.draw(t);

    sf::Text info("Enter: Menu   S: Select again", font, 24);
    info.setPosition(430, 350);
    g.window.draw(info);
}
