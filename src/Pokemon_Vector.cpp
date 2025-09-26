//
// Created by justi on 10/09/2025.
//

#include "Pokemon_Vector.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

void Pokemon_Vector::loadFromCSV(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "[ERROR] IMPOSSIBLE TO OPEN FILE :" << filename << endl;
        return;
    }
    string line;
    getline(file, line);
    while (getline(file, line)) {
        istringstream iss(line);
        int id;
        string name, evolution;
        double hp, hpMax, attack, defense;
        char sep;
        iss >> id >> sep >> name >> sep >> evolution >> sep >> hp
        >> sep >> hpMax >> sep >> attack >> sep >> defense;

        Pokemon p(id, name, evolution, hp, hpMax, attack, defense);
        pokemons.push_back(p);
    }
}

void Pokemon_Vector::addPokemon(const Pokemon &p) {
    pokemons.push_back(p);
}

void Pokemon_Vector::removePokemon(int id) {
    pokemons.erase(
        remove_if(pokemons.begin(), pokemons.end(),
            [id](const Pokemon &p) {return p.getID()==id;}),
            pokemons.end());
}

void Pokemon_Vector::printAll() const {
    for (const auto &p : pokemons) {
        cout << "ID : " << p.getID()
             << " | Name : " << p.getName()
             << " | HP   : " << p.getHP()
             << " | ATK  : " << p.getAttack()
             << " | DEF  : " << p.getDefense()
             << endl;
    }
}

