//
// Created by justine on 03/10/2025.
//

#include "PauseState.h"
#include "Game.h"
#include "MainMenuState.h"
#include <memory>

void PauseState::enter(Game& g) { font.loadFromFile("/home/justine/CLionProjects/project/OpenSans-Semibold.ttf"); }

void PauseState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::R) { // resume
            g.changeState(std::move(stored_));
        }
        if (e.key.code == sf::Keyboard::M) { // go to menu (abandon)
            stored_.reset();
            g.changeState(std::make_unique<MainMenuState>());
        }
    }
}

void PauseState::render(Game& g) {
    // On affiche un overlay sombre
    sf::RectangleShape overlay({(float)g.window.getSize().x, (float)g.window.getSize().y});
    overlay.setFillColor({0,0,0,150});
    g.window.draw(overlay);

    sf::Text t("PAUSED\nR: Resume  M: Menu", font, 36);
    t.setPosition(380, 280);
    g.window.draw(t);
}