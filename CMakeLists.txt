cmake_minimum_required(VERSION 3.26)
project(3A_Pokemon)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(.)

add_executable(3A_Pokemon
        inc/Pokemon.h
        inc/Pokemon_Vector.h
        inc/Pokedex.h
        inc/Pokemon_Party.h
        inc/Pokemon_Attack.h
)

target_link_libraries(3A_Pokemon
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        )