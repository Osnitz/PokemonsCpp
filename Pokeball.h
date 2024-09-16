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
public:
    Pokeball();
    ~Pokeball() override;
    Pokemon* getPokemon(int id) override;
    Pokemon* getPokemon(const string &name) override;
    void removeAllFromPokeball();
    void displayPokeballList()const;
    void removeOneFromPokeball(const string& name);
    void removeOneFromPokeball(int id);
    std::vector<std::string> selectInPokeball();
    void addPokemon(const string& name);
    void addPokemon(int id);
    void addPokemon(Pokemon* pokemon);
    int getNumberOfPokemon() override;
};
#endif //POKEBALL_H

