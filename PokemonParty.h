//
// Created by matthieu on 11/09/24.
//

#ifndef POKEMONPARTY_H
#define POKEMONPARTY_H
#include "SetOfPokemon.h"
#include "pokedex.h"
#include "Pokeball.h"
using std::string;

class PokemonParty{
private:
    std::vector<Pokemon*> partyPokemons; // Liste des Pokémon dans la partie
    Pokeball* pokeball;
public:
    PokemonParty()=delete;
    PokemonParty(const std::vector<int>& id, Pokeball* pokeball);
    PokemonParty(const std::vector<string>& id, Pokeball* pokeball);
    ~PokemonParty();

    /*void addPokemon(int idOrIndex);
    Pokemon getPokemonByName(const string& name);
    Pokemon getPokemonById(int index);
    void removePokemon(int nameOrId);
    void removeAllPokemon();*/
    void displayParty() const;
};
#endif //POKEMONPARTY_H
