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
//Getters
double Pokemon::getHP() const {
    return hitPoint;
}
double Pokemon::getHPMax() const {
    return hitPointMax;
}
double Pokemon::getAttack() const {
    return attack;
}
double Pokemon::getDefense() const {
    return defense;
}
int Pokemon::getID() const {
    return id;
}

string Pokemon::getName() const {
    return name;
}



//Setters
void Pokemon::setHP(double hp) {
    hitPoint=hp;
}
void Pokemon::setHPMax(double hpMax) {
    hitPointMax=hpMax;
}
void Pokemon::setAttack(double att) {
    attack=att;
}
void Pokemon::setDefense(double def) {
    defense=def;
}

//Fighting method
void Pokemon::fight(Pokemon &target) const {
    cout<<"----------- LET'S FIGHT ! -----------"<<endl;
    if(getAttack()>target.getDefense()){
        double damage=getAttack()-target.getDefense();
        double newHP=target.getHP()-damage;

        if(newHP<0)newHP=0;
        target.setHP(newHP);
        cout<<name<<" attack "<<target.name<<endl;
        cout<<"He inflicts "<<damage<<" damages "<<endl;
        if(target.getHP()==0){
            cout<<target.name<<" is KO"<<endl;
            cout<<"----------- GAME OVER -----------"<<endl;
        }else{
            cout<<target.name<<" has now "<<target.getHP()<<" HP"<<endl;
        }
    }else{
        cout<<name<<" attack "<<target.name<<" but his defense is too high !"<<endl;
        cout<<"----------- BETTER LUCK NEXT TIME ! -----------"<<endl;
    }
}