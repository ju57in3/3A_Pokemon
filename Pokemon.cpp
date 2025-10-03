//
// Created by justine on 03/10/2025.
//

#include "Pokemon.h"

Pokemon::Pokemon(int id_, std::string name_, std::string t1, std::string t2,
                 int hp_, int attack, int defense, int spA, int spD, int spd,
                 int gen, bool leg, int evoId)
: id(id_), name(std::move(name_)), type1(std::move(t1)), type2(std::move(t2)),
  maxHP(hp_), hp(hp_), atk(attack), def_(defense), spAtk(spA), spDef(spD), speed(spd),
  generation(gen), legendary(leg), evolutionId(evoId) {}

int Pokemon::attack(Pokemon& target) const {
    static thread_local std::mt19937 rng{std::random_device{}()};
    std::uniform_real_distribution<float> dist(0.85f, 1.0f);
    float mod = dist(rng);
    int raw = std::max(1, atk - target.def_/2);
    int dmg = std::max(1, static_cast<int>(raw * mod));
    target.hp = std::max(0, target.hp - dmg);
    return dmg;
}