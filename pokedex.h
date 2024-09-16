//
// Created by matthieu on 09/09/24.
//

#ifndef POKEDEX_H
#define POKEDEX_H

#include <fstream>
#include "SetOfPokemon.h"
#include<random>


using std::string;

class Pokedex: public SetOfPokemon {
private:
    static Pokedex* instance;

    explicit Pokedex(const string &fileName);
    ~Pokedex() override;

protected:

public:
    static Pokedex *GetInstance(const std::string& value);
    Pokemon* getPokemon(int id) override;
    Pokemon* getPokemon(const string &name) override;
    Pokemon* getOneRandomPokemon();
    int getNumberOfPokemon() override;

};

#endif //POKEDEX_H