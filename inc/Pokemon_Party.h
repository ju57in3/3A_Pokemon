//
// Created by justine on 26/09/2025.
//

#ifndef INC_3A_POKEMON_POKEMON_PARTY_H
#define INC_3A_POKEMON_POKEMON_PARTY_H

#include "../Pokemon_Vector.h"

class Pokemon_Party : public Pokemon_Vector{
    public:
    Pokemon_Party() = default;

    void addPokemon(const Pokemon &p) override;
    void removePokemon(int id) override;
    Pokemon getPokemon(int id) const;
    void printAll() const override;
};


#endif //INC_3A_POKEMON_POKEMON_PARTY_H