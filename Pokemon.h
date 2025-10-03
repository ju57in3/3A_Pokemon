//
// Created by justine on 03/10/2025.
//

#ifndef PROJECT_POKEMON_H
#define PROJECT_POKEMON_H


#pragma once
#include <memory>
#include <string>
#include <algorithm>
#include <random>

class Pokemon {
public:
    int id{};
    std::string name;
    std::string type1, type2;
    int maxHP{}, hp{};
    int atk{}, def_{}, spAtk{}, spDef{}, speed{};
    int generation{};
    bool legendary{};
    int evolutionId{0};

    Pokemon() = default;
    Pokemon(int id, std::string name,
            std::string t1, std::string t2,
            int hp, int attack, int defense, int spA, int spD, int speed,
            int gen, bool leg, int evoId=0);

    ~Pokemon() = default;

    void healFull() { hp = maxHP; }
    bool isFainted() const { return hp <= 0; }

    int attack(Pokemon& target) const;

    std::unique_ptr<Pokemon> clone() const {
        return std::make_unique<Pokemon>(*this);
    }
};


#endif //PROJECT_POKEMON_H