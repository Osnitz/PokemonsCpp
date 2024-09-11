//
// Created by matthieu on 09/09/24.
//

#ifndef POKEDEX_H
#define POKEDEX_H

#include <fstream>
#include <sstream>

#include "SetOfPokemon.h"


using std::string;

class Pokedex: public SetOfPokemon {
private:
    static Pokedex* instance;
    Pokedex(const string &fileName);
    ~Pokedex();

protected:

public:
    static Pokedex *GetInstance(const std::string& value);
    Pokemon getPokemonById(int id) override;
    Pokemon getPokemonByName(const string &name) override;
};

#endif //POKEDEX_H