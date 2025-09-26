//
// Created by justi on 10/09/2025.
//

#include <iostream>
#include "Pokemon.h"
#include <SFML/Graphics.hpp>

#include "Pokedex.h"
#include "Pokemon_Party.h"
#include "Pokemon_Vector.h"

int main() {
    /*
    Pokemon pikachu(25,"Pikachu","Raichu",35,35,
                    55,40);
    Pokemon bulbizarre(1,"Bulbizarre","Herbizarre",45,45,
                       50,50);
    pikachu.fight(bulbizarre);
    */

    /*
    Pokemon_Vector pokedex;
    pokedex.loadFromCSV("/home/justine/CLionProjects/3A_Pokemon/pokedex.csv");

    pokedex.printAll();
    */

    /*
    try {
        Pokedex &pokedex = Pokedex::getInstance("/home/justine/CLionProjects/3A_Pokemon/pokedex.csv");

        Pokemon pikachu = pokedex.getPokemonByName("Pikachu");
        Pokemon bulbizarre = pokedex.getPokemonById(1);

        std::cout << "Cloned " << pikachu.getName() << "with" << pikachu.getHP() << "HP" << std::endl;
        std::cout << "Cloned " << bulbizarre.getName() << "with" << bulbizarre.getHP() << "HP" << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "[ERROR] : " << e.what() << std::endl;
    }
    */

    Pokedex &pokedex = Pokedex::getInstance("/home/justine/CLionProjects/3A_Pokemon/pokedex.csv");
    Pokemon_Party myParty;

    myParty.addPokemon(pokedex.getPokemonByName("Pikachu"));
    myParty.addPokemon(pokedex.getPokemonById(1));

    myParty.printAll();

    myParty.removePokemon(25);

    myParty.printAll();

    /*sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        while (window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(shape);
            window.display();
        }*/



    return 0;

}
