#include "PokemonParty.h"

PokemonParty::PokemonParty(const std::vector<int> &ids, Pokeball *pokeball) {
    if (ids.size() < 7) {
        for (int id : ids) {
            std::cout << "id = " << id << std::endl;

            // Allouer dynamiquement le Pokémon pour qu'il persiste en dehors de la boucle
            Pokemon* pokemon = new Pokemon(pokeball->getPokemonById(id));

            // Ajouter le pointeur dans le vecteur
            partyPokemons.emplace_back(pokemon);
        }
        pokeball->removeAllFromPokeball();
    }
}

PokemonParty::PokemonParty(const std::vector<std::string> &names, Pokeball *pokeball) {
    // Construction avec les noms
    if (names.size() < 7) {
        for (const std::string& name : names) {
            // Allocation dynamique pour chaque Pokémon
            Pokemon* pokemon = new Pokemon(pokeball->getPokemonByName(name));

            // Ajoute le pointeur dans le vecteur
            partyPokemons.emplace_back(pokemon);
        }
        pokeball->removeAllFromPokeball();
    }
}

PokemonParty::~PokemonParty() {
    // Libérer la mémoire de chaque Pokémon dans partyPokemons
    for (Pokemon* pokemon : partyPokemons) {
        delete pokemon;  // Libérer chaque Pokémon alloué dynamiquement
    }
}

void PokemonParty::displayParty() const {
    std::cout << "Liste des Pokémon dans la party pokemon:" << std::endl;
    for (size_t i = 0; i < partyPokemons.size(); ++i) {
        std::cout << i << " : " << partyPokemons[i]->getName() << std::endl;
    }
}

