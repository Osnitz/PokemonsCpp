//
// Created by matthieu on 11/09/24.
//

#ifndef POKEBALL_H
#define POKEBALL_H
#include "SetOfPokemon.h"
#include <vector>
#include <sstream>


#include "SetOfPokemon.h"


class Pokeball: SetOfPokemon {
private:
    std::vector<Pokemon *> pokemonInPokeball;
public:
    Pokeball();
    ~Pokeball();
    Pokemon getPokemonById(int id) override;
    Pokemon getPokemonByName(const string &name) override;
    void removeFromPokeballByName(const string &name);
};
#endif //POKEBALL_H

