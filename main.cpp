//
// Created by justine on 03/10/2025.
//
#include "Game.h"
#include "SelectionState.h"
int main() {
    auto& dex = Pokedex::instance();
    dex.loadFromCSV("/home/justine/CLionProjects/project/pokedex.csv");
    Game game;
    game.changeState(std::make_unique<SelectionState>());
    game.run();
}