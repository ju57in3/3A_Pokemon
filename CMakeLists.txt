cmake_minimum_required(VERSION 3.26)
project(3A_Pokemon)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(3A_Pokemon
        Pokemon.cpp
        Pokemon.h
        main.cpp)
