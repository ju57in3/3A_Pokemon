#include <iostream>
#include "Pokemon.h"

int main() {

    Pokemon pikachu(25,"Pikachu","Raichu",35,35,
                    55,40);
    Pokemon bulbizarre(1,"Bulbizarre","Herbizarre",45,45,
                       50,50);
    pikachu.fight(bulbizarre);
    return 0;
}