//
// Created by matthieu on 11/09/24.
//

#ifndef POKEMONPARTY_H
#define POKEMONPARTY_H
#include "SetOfPokemon.h"
#include "pokedex.h"
#include "Pokeball.h"
using std::string;

class PokemonParty:SetOfPokemon{
public:
    PokemonParty()=delete;
    PokemonParty(Pokeball* pokeball);
    PokemonParty(const std::vector<string>& id, Pokeball* pokeball);
    ~PokemonParty() override;

    void addPokemon(Pokeball* pokeball);
    void addPokemon(const string& name, Pokeball* pokeball);
    Pokemon* getPokemon(const string& name) override;
    Pokemon* getPokemon(int index) override;
    void removePokemon(int Id);
    void removePokemon(const string& name);
    void removeAllPokemon();
    void displayParty() const;
    int countAlivePokemon();
    void displayAliveParty() const;
    int getNumberOfPokemon() override;
};
#endif //POKEMONPARTY_H
