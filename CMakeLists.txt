cmake_minimum_required(VERSION 3.29)
project(Exercices)

set(CMAKE_CXX_STANDARD 20)

add_executable(Exercices main.cpp pokemon.cpp pokemon.h SetOfPokemon.cpp SetOfPokemon.h pokedex.cpp pokedex.h Pokeball.cpp
        Pokeball.h PokemonParty.cpp PokemonParty.h Player.cpp Player.h States.cpp States.h)
