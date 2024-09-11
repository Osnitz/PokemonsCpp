//
// Created by matthieu on 11/09/24.
//

#ifndef POKEBALL_H
#define POKEBALL_H
#include "SetOfPokemon.h"
#include <vector>
#include <sstream>

class Pokeball: SetOfPokemon {
private:
    std::vector<Pokemon *> pokemonInPokeball;
public:
    Pokeball();
    ~Pokeball() override;
    Pokemon getPokemonById(int id) override;
    Pokemon getPokemonByName(const string &name) override;
    void removeAllFromPokeball();
    void displayPokeballList()const;
};
#endif //POKEBALL_H

