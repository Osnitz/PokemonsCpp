//
// Created by matthieu on 11/09/24.
//

#include "Pokeball.h"
#include "pokedex.h"

Pokeball::Pokeball() {
    std::cout << "Pokeball constructor" << std::endl;
};
Pokeball::~Pokeball() {
    std::cout << "Pokeball destructor" << std::endl;
    for (auto pokemon : pokemonInPokeball) {
        delete pokemon;  // Libère chaque Pokémon alloué dynamiquement
    }
};

Pokemon Pokeball::getPokemonById(int id) {
    Pokedex* pokedex = Pokedex::GetInstance("../ressources/pokedex.csv");
    auto pokemon = new Pokemon(pokedex->getPokemonById(id));
    pokemonInPokeball.emplace_back(pokemon);  // Ajoute le pointeur au vecteur
    std::cout << pokemon->getName() << " d'identifiant : " << pokemon->getId() << ", a été ajouté à la pokeball" << std::endl;
    return *pokemon;  // Renvoie une copie du Pokémon
}


Pokemon Pokeball::getPokemonByName(const string& name) {
    Pokedex* pokedex = Pokedex::GetInstance("../ressources/pokedex.csv");
    auto pokemon = new Pokemon(pokedex->getPokemonByName(name));  // Alloue sur le tas
    pokemonInPokeball.emplace_back(pokemon);  // Ajoute le pointeur au vecteur
    std::cout << pokemon->getName() << " a été ajouté à la pokeball" << std::endl;
    return *pokemon;  // Renvoie une copie du Pokémon
}

void Pokeball::removeAllFromPokeball() {
    for (size_t i = 0; i < pokemonInPokeball.size(); ++i) {
        pokemonInPokeball[i];
        std::cout << pokemonInPokeball[i]->getName() << " retiré de la Pokeball" << std::endl;

        delete pokemonInPokeball[i];  // Libère la mémoire du Pokémon
        pokemonInPokeball.erase(pokemonInPokeball.begin() + i);  // Supprime du vecteur

        --i;  // Pour compenser la suppression d'un élément et éviter de sauter l'élément suivant
    }
}


/*void Pokeball::removeFromPokeballByIndex(int index) {
    if (index < 0 || index >= pokemonInPokeball.size()) {
        std::cerr << "Index hors limites" << std::endl;
        return;
    }
    string name = pokemonInPokeball[index]->getName();
    delete pokemonInPokeball[index];  // Libère la mémoire du Pokémon
    pokemonInPokeball.erase(pokemonInPokeball.begin() + index);  // Supprime du vecteur
    std::cout << name << " retiré de la Pokeball" << std::endl;
}*/


void Pokeball::displayPokeballList() const {
    std::cout << "Liste des Pokémon dans la pokeball:" << std::endl;
    for (size_t i = 0; i < pokemonInPokeball.size(); ++i) {
        std::cout << i << " : " << pokemonInPokeball[i]->getName() << std::endl;
    }
}
