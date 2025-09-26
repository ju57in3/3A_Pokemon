//
// Created by justine on 26/09/2025.
//

#include "Pokemon_Party.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

void Pokemon_Party::addPokemon(const Pokemon &p) {
    pokemons.push_back(p);
    cout << p.getName() << "been added to the Party !" << endl;
}

void Pokemon_Party::removePokemon(int id) {
    auto it = remove_if(pokemons.begin(), pokemons.end,
        [id](const Pokemon &p) {return p.getID() == id;});
    if (it == pokemons.end()) {
        cout << "Pokemon with ID " << id << " have been removed from the Party." << endl;
        pokemons.erase(it, pokemons.end());
    } else {
        cout << "No Pokemon with ID " << id << " found in the Party." << endl;
    }

}

Pokemon Pokemon_Party::getPokemon(int id) const {
    for (const auto &p : pokemons) {
        if (p.getID() == id) {
            return p;
        }
    }
    throw runtime_error("Pokemon not found in the Party !");
}

void Pokemon_Party::printAll() const {
    cout << "----------- Pokemon Party ! -----------" << endl;
    if (pokemons.empty()) {
        cout << "Pokemon Party is empty." << endl;
    } else {
        for (const auto &p : pokemons) {
            cout << "ID : " << p.getID()
                 << " | Name : " << p.getName()
                 << " | HP   : " << p.getHP() << "/" << p.getHPMax()
                 << " | ATK  : " << p.getAttack()
                 << " | DEF : " << p.getDefense()
                 << endl;
        }
    }
}