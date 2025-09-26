//
// Created by justi on 10/09/2025.
//

#ifndef INC_3A_POKEMON_POKEMON_VECTOR_H
#define INC_3A_POKEMON_POKEMON_VECTOR_H

#include <vector>
#include <string>
#include <SFML/Window/Keyboard.hpp>

#include "Pokemon.h"

class Pokemon_Vector {
private:
    std::vector<Pokemon> pokemons;

public:
    void loadFromCSV(const std::string &filename);

    virtual void addPokemon(const Pokemon &p);

    virtual void removePokemon(int id);

    virtual void printAll() const;
    const std::vector<Pokemon> &getPokemons() const {return pokemons;}

};


#endif //INC_3A_POKEMON_POKEMON_VECTOR_H
