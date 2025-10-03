# Pokemon
Projet de TP en C++ : implémentation d’un petit jeu de sélection et de combat de Pokémon avec SFML.

Fonctionnalités demandées

Classe Pokemon : attributs issus du CSV (nom, types, stats, etc.), clonable.

PokemonVector (abstraite) et ses dérivées :

PokemonParty (nombre illimité),

PokemonAttack (équipe de 6 maximum).

Pokedex (Singleton) : charge les données depuis pokedex.csv et fournit des clones (pas d’accès direct aux données internes).

Pattern State avec au moins 5 états :

MainMenuState,

SelectionState (choisir son équipe de 6),

BattleState (combat simple avec jauges de vie, sprites Pokémon, image versus),

PauseState,

ResultsState.

Interface graphique (SFML) : affichage du menu, sélection avec clavier, sprites des Pokémon (assets/pokemon/xxx.png), barre de vie (healthGauge.png), police TTF, etc.

Objectif

Créer un programme structuré et modulaire qui illustre :

la gestion de collections et le clonage,

l’application d’un pattern de conception (State, Singleton),

l’utilisation d’assets externes (CSV, images, polices),

et l’intégration de SFML pour l’interface graphique.
