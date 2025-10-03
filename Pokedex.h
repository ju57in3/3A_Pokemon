//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_POKEDEX_H
#define PROJECT_POKEDEX_H

#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include "Pokemon.h"

class Pokedex {
public:
    static Pokedex& instance();
    void loadFromCSV(const std::string& path);
    std::unique_ptr<Pokemon> cloneById(int id) const;
    std::unique_ptr<Pokemon> cloneByName(const std::string& name) const;
    const std::vector<int>& allIds() const { return ids; }
    std::vector<int> ids;
private:
    Pokedex() = default;
    std::unordered_map<int, std::unique_ptr<Pokemon>> baseById;
    std::unordered_map<std::string,int> idByName;
    static std::vector<int> emptyVec;
};

#endif //PROJECT_POKEDEX_H