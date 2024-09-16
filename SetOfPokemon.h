//
// Created by matthieu on 09/09/24.
//

#ifndef SETOFPOKEMON_H

#define SETOFPOKEMON_H
#include "pokemon.h"

#include <vector>
#include <string>
#include <iostream>

class SetOfPokemon {
protected:
    std::vector<Pokemon *> pokemonList;// Vecteur de Pokemon
    int findPokemon(const string& name) const;
    int findPokemon(int id) const;
public:
    SetOfPokemon();

    // Destructeur virtuel
    virtual ~SetOfPokemon();

    // Méthode abstraite pour récuperer un pokéon via son index
    virtual Pokemon* getPokemon(int id) = 0;

    // Méthode abstraite pour récupérer un Pokémon par son nom
    virtual Pokemon* getPokemon(const string &name) = 0;

    virtual int getNumberOfPokemon()=0;


    // Méthode concrète d'affichage de la liste des Pokémon
    void displayPokemonList() const;

};
#endif //SETOFPOKEMON_H
