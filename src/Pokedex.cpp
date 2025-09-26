//
// Created by justi on 10/09/2025.
//

#include <iostream>
#include "Pokedex.h"

#include <stdexcept>

#include <fstream>

Pokedex &Pokedex::getInstance(const string &filename) {
    static Pokedex instance(filename);
    return instance;
}

Pokedex::Pokedex(const string &filename) {
    loadFromCSV(filename);
}

Pokemon Pokedex::getPokemonById(int id) const {
    for (const auto &p : getPokemons()) {
        if (p.getID() == id) {
            return p;
        }
    }
    throw runtime_error("Pokemon ID not found");
}

Pokemon Pokedex::getPokemonByName(const string &name) const {
    for (const auto &p : getPokemons()) {
        if (p.getName() == name) {
            return p;
        }
    }
    throw runtime_error("Pokemon name not found");
}
