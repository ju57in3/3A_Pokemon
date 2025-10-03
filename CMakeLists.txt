cmake_minimum_required(VERSION 4.0)
project(project)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

add_executable(project
        main.cpp
        Pokemon.cpp
        Pokemon.h
        PokemonVector.h
        Pokedex.cpp
        Pokedex.h
        PokemonParty.h
        PokemonAttack.cpp
        PokemonAttack.h
        GameState.h
        Game.cpp
        Game.h
        MainMenuState.cpp
        MainMenuState.h
        SelectionState.cpp
        SelectionState.h
        BattleState.cpp
        BattleState.h
        PauseState.cpp
        PauseState.h
        ResultsState.cpp
        ResultsState.h
        HealthBar.h)

target_link_libraries(project PRIVATE sfml-graphics sfml-window sfml-system)