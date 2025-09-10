//
// Created by justi on 10/09/2025.
//

#include "Pokemon.h"
#include <iostream>

using namespace std;

Pokemon::~Pokemon() {
    cout<<"Destruction"<<endl;
}

Pokemon::Pokemon(const int id, const string &name, const string &evolution,
                 const double hitPoint, const double hitPointMax, const double attack,
                 const double defense)
        : id(id),name(name),evolution(evolution),hitPoint(hitPoint), hitPointMax(hitPointMax),
          attack(attack),defense(defense){
    cout<<"ID:"<<id<<endl;
    cout<<"Name:"<<name<<endl;
    cout<<"Evolution:"<<evolution<<endl;
    cout<<"Hit Point:"<<hitPoint<<endl;
    cout<<"Hit Point Max:"<<hitPointMax<<endl;
    cout<<"Attack:"<<attack<<endl;
    cout<<"Defense:"<<defense<<endl;

}

double Pokemon::fight() const {

}