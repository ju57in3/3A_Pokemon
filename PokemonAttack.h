//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_POKEMONATTACK_H
#define PROJECT_POKEMONATTACK_H

#pragma once
#include "PokemonVector.h"
#include "PokemonParty.h"

class PokemonAttack : public PokemonVector {
public:
    void add(std::unique_ptr<Pokemon> p) override;
    std::unique_ptr<Pokemon> remove(size_t i) override;
    void fillFromParty(PokemonParty& party, const std::vector<size_t>& indices);
    void reintegrateToParty(PokemonParty& party, const std::vector<size_t>& indices);
    static constexpr size_t MaxSize = 6;
};


#endif //PROJECT_POKEMONATTACK_H