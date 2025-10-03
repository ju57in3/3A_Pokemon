//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_POKEMONPARTY_H
#define PROJECT_POKEMONPARTY_H

#pragma once
#include "PokemonVector.h"

class PokemonParty : public PokemonVector {
public:
    void add(std::unique_ptr<Pokemon> p) override { items.emplace_back(std::move(p)); }
    std::unique_ptr<Pokemon> remove(size_t i) override {
        if (i >= items.size()) return nullptr;
        auto ptr = std::move(items[i]);
        items.erase(items.begin() + i);
        return ptr;
    }
};

#endif //PROJECT_POKEMONPARTY_H