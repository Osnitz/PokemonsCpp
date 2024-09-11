//
// Created by matthieu on 09/09/24.
//

#include "SetOfPokemon.h"

void SetOfPokemon::displayPokemonList() const {
    std::cout << "Liste des Pokémon dans le Set:" << std::endl;
    for (size_t i = 0; i < pokemonList.size(); ++i) {
        std::cout << i << " : " << pokemonList[i]->getName() << std::endl;
    }
}

SetOfPokemon::SetOfPokemon() {
    std::cout << "Ici le constructeur de SetOfPokemon" << std::endl;
}

SetOfPokemon::~SetOfPokemon() {
    std::cout << "Ici le destructeur de SetOfPokemon" << std::endl;
}

int SetOfPokemon::findByName(const string &name) {
    for (size_t i = 0; i < pokemonList.size(); ++i) {
        if (pokemonList[i]->getName() == name) {
            return i;
        }
    }
    return -1;
}

int SetOfPokemon::findById(int id) {
    for (size_t i = 0; i < pokemonList.size(); ++i) {
        if (pokemonList[i]->getId() == id) {
            return i;
        }
    }
    return -1;
}



