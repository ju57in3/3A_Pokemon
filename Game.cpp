//
// Created by justine on 03/10/2025.
//

#include "Game.h"
#include "GameState.h"
#include "PauseState.h"
#include <chrono>

Game::Game()
: window(sf::VideoMode(1200, 720), "Pokemon Selector"),
  pokedex(Pokedex::instance()) {}

void Game::changeState(std::unique_ptr<GameState> s) {
    if (state) state->exit(*this);
    state = std::move(s);
    if (state) state->enter(*this);
}
void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event e{};
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
            if (state) state->handleEvent(*this, e);
        }
        float dt = clock.restart().asSeconds();
        if (state) state->update(*this, dt);
        window.clear();
        if (state) state->render(*this);
        window.display();
    }
}
void Game::pause() {
    if (!state) return;
    auto captured = std::move(state);
    changeState(std::make_unique<PauseState>(std::move(captured)));
}