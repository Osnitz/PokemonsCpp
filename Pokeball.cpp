//
// Created by matthieu on 11/09/24.
//

#include "Pokeball.h"

Pokemon Pokeball::getPokemonById(int id) {
    int index = findById(id);
    if (index != -1) {

        Pokemon pokemon (*pokemonList.at(index));
        pokemonInPokeball.push_back(&pokemon);

        std::cout << pokemon.getName() << "Stocké dans la pokeball" << std::endl;
        return pokemon;  // Renvoie une copie du Pokémon
    } else {
        throw std::invalid_argument("Le Pokémon avec l'ID " + std::to_string(id) + " n'existe pas dans le Pokedex.");
    }
}

Pokemon Pokeball::getPokemonByName(const string& name) {
    int index = findByName(name);
    if (index != -1) {
        Pokemon pokemon (*pokemonList.at(index));
        pokemonInPokeball.push_back(&pokemon);
        std::cout << name << "Stocké dans la pokeball" << std::endl;
        return pokemon;  // Renvoie une copie du Pokémon
    } else {
        throw std::invalid_argument("Le Pokémon avec le nom " + name + " n'existe pas dans le Pokedex.");
    }
}

void Pokeball::removeFromPokeballByName(const string &name) {
    for (size_t i = 0; i < pokemonInPokeball.size(); ++i) {
        if (pokemonInPokeball[i]->getName() == name) {
            std::cout << name << " retiré de la Pokeball" << std::endl;

            delete pokemonInPokeball[i];  // Libère la mémoire si nécessaire
            pokemonInPokeball.erase(pokemonInPokeball.begin() + i);  // Supprime le Pokémon du vecteur
            return;  // On arrête après avoir trouvé et supprimé le Pokémon
        }
    }

    // Si aucun Pokémon avec ce nom n'a été trouvé
    std::cerr << "Le Pokémon avec le nom " << name << " n'existe pas dans la Pokeball." << std::endl;
}

