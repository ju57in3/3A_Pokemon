//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_POKEMONVECTOR_H
#define PROJECT_POKEMONVECTOR_H

#pragma once
#include <vector>
#include <memory>
#include <stdexcept>
#include "Pokemon.h"

class PokemonVector {
protected:
    std::vector<std::unique_ptr<Pokemon>> items;
public:
    virtual ~PokemonVector() = default;
    size_t size() const { return items.size(); }
    const Pokemon& at(size_t i) const { return *items.at(i); }
    Pokemon& at(size_t i) { return *items.at(i); }

    virtual void add(std::unique_ptr<Pokemon> p) = 0;
    virtual std::unique_ptr<Pokemon> remove(size_t i) = 0;

    // itération simple
    const std::vector<std::unique_ptr<Pokemon>>& data() const { return items; }
};


#endif //PROJECT_POKEMONVECTOR_H