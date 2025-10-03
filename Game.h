//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Pokedex.h"
#include "PokemonParty.h"
#include "PokemonAttack.h"

class GameState;

class Game {
public:
    Game();
    void run();
    void changeState(std::unique_ptr<GameState> s);
    void pause();

    sf::RenderWindow window;
    Pokedex& pokedex;
    PokemonParty party;
    PokemonAttack team;
private:
    std::unique_ptr<GameState> state;
};

#endif //PROJECT_GAME_H