//
// Created by justine on 03/10/2025.
//

#include "MainMenuState.h"
#include "Game.h"
#include "SelectionState.h"
#include <memory>

void MainMenuState::enter(Game& g) {
    font.loadFromFile("/home/justine/CLionProjects/project/OpenSans-Semibold.ttf");
}

void MainMenuState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Up)    selected = (selected + items.size()-1) % items.size();
        if (e.key.code == sf::Keyboard::Down)  selected = (selected + 1) % items.size();
        if (e.key.code == sf::Keyboard::Enter) {
            if (selected == 0) g.changeState(std::make_unique<SelectionState>());
            if (selected == 1) g.window.close();
        }
    }
}

void MainMenuState::render(Game& g) {
    sf::Text title("POKEMON SELECTOR", font, 48);
    title.setPosition(60, 60);
    g.window.draw(title);

    for (size_t i=0;i<items.size();++i) {
        sf::Text t(items[i], font, 36);
        t.setPosition(80, 160 + i*50);
        if ((int)i == selected) t.setStyle(sf::Text::Underlined | sf::Text::Bold);
        g.window.draw(t);
    }
}