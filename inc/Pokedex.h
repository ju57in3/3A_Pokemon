//
// Created by justi on 10/09/2025.
//

#ifndef INC_3A_POKEMON_POKEDEX_H
#define INC_3A_POKEMON_POKEDEX_H

#include <string>
#include "../Pokemon_Vector.h"

using namespace std;

class Pokedex : public Pokemon_Vector {
private:
    Pokedex(const string &filename);
    Pokedex(const Pokedex&) = delete;
    Pokedex& operator=(const Pokedex&) = delete;

public:
    static Pokedex& getInstance(const string &filename = "pokedex.csv");
    Pokemon getPokemonById(int id) const;
    Pokemon getPokemonByName(const string &name) const;
};


#endif //INC_3A_POKEMON_POKEDEX_H
