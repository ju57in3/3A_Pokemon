//
// Created by justi on 10/09/2025.
//

#ifndef INC_3A_POKEMON_POKEMON_H
#define INC_3A_POKEMON_POKEMON_H

#include <string>

using std::string;

class Pokemon {
private:
    int id;
    string name;
    string evolution;
    double hitPoint;
    double hitPointMax;
    double attack;
    double defense;

public:
    //Constructor
    Pokemon() = delete;

    Pokemon(const int id, const string &name, const string &evolution, const double hitPoint,
            const double hitPointMax, const double attack, const double defense);

    //Destructor
    ~Pokemon();

    //Getters
    double getHP() const;
    double getHPMax() const;
    double getAttack() const;
    double getDefense() const;
    int getID() const;
    string getName() const;

    //Setters
    void setHP(double);
    void setHPMax(double);
    void setAttack(double);
    void setDefense(double);

    //Fighting method
    void fight(Pokemon &target) const;

    //Constructor de recopie
    //Pokemon(const Pokemon& anotherPokemon);

};

#endif //INC_3A_POKEMON_POKEMON_H
