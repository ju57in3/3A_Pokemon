//
// Created by justine on 03/10/2025.
//

#include "PokemonAttack.h"
#include <stdexcept>

void PokemonAttack::add(std::unique_ptr<Pokemon> p) {
    if (items.size() >= MaxSize) throw std::runtime_error("Team full (max 6)");
    items.emplace_back(std::move(p));
}
std::unique_ptr<Pokemon> PokemonAttack::remove(size_t i) {
    if (i >= items.size()) return nullptr;
    auto ptr = std::move(items[i]);
    items.erase(items.begin() + i);
    return ptr;
}
void PokemonAttack::fillFromParty(PokemonParty& party, const std::vector<size_t>& idx) {
    if (idx.size() > MaxSize) throw std::runtime_error("Too many indices");
    // attention: enlever en partant du plus grand index
    auto sorted = idx; std::sort(sorted.rbegin(), sorted.rend());
    for (auto i : sorted) {
        auto p = party.remove(i);
        if (p) add(std::move(p));
    }
}
void PokemonAttack::reintegrateToParty(PokemonParty& party, const std::vector<size_t>& idx) {
    auto sorted = idx; std::sort(sorted.rbegin(), sorted.rend());
    for (auto i : sorted) {
        auto p = remove(i);
        if (p) party.add(std::move(p));
    }
}