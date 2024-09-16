//
// Created by matthieu on 11/09/24.
//

#include "Pokeball.h"
#include "pokedex.h"

Pokeball::Pokeball() {
    //std::cout << "Pokeball constructor" << std::endl;
};
Pokeball::~Pokeball() {
    //std::cout << "Pokeball destructor" << std::endl;
    for (auto pokemon : pokemonList) {
        delete pokemon;  // Libère chaque Pokémon alloué dynamiquement
    }
};

Pokemon* Pokeball::getPokemon(int id) {
    // Recherche les pokemon par index dans la pokeball
    // Vérifie si l'index id est valide
    if (id >= 0 && id < pokemonList.size()) {
        return pokemonList[id];  // Renvoie le Pokémon à l'index id
    } else {
        std::cerr << "Erreur : index hors limites." << std::endl;
        return nullptr;  // Renvoie nullptr si l'index est invalide
    }
}



Pokemon* Pokeball::getPokemon(const string& name) {
    for (auto pokemon : pokemonList) {
        if (pokemon->getName() == name) {
            return pokemon;
        }
    }
    std::cerr << "Erreur : index hors limites." << std::endl;
    return nullptr;
}

void Pokeball::addPokemon(const string& name) {
    Pokedex* pokedex = Pokedex::GetInstance("../ressources/pokedex.csv");
    Pokemon* pokemon = pokedex->getPokemon(name);
    auto newPokemon = new Pokemon(*pokemon); //pointeur vers copie du pokemon
    pokemonList.push_back(newPokemon);
}

void Pokeball::addPokemon(int id) {
    Pokedex* pokedex = Pokedex::GetInstance("../ressources/pokedex.csv");
    Pokemon* pokemon = pokedex->getPokemon(id);
    auto newPokemon = new Pokemon(*pokemon); //pointeur vers copie du pokemon
    pokemonList.push_back(newPokemon);
}



void Pokeball::removeAllFromPokeball() {
    for (size_t i = 0; i < pokemonList.size(); ++i) {
        //std::cout << ^pokemonList[i]->getName() << " retiré de la Pokeball" << std::endl;
        delete pokemonList[i];
    }
    pokemonList.clear();//vide le vecteur
}

void Pokeball::removeOneFromPokeball(const std::string &name) {
    for (auto it = pokemonList.begin(); it != pokemonList.end();) {
        if ((*it)->getName() == name) {
            delete *it;  // Libère la mémoire de l'objet
            it = pokemonList.erase(it);  // Supprime l'élément du vecteur et obtient l'itérateur suivant
            break;
        } else {
            ++it;  // Incrémente l'itérateur uniquement si aucun élément n'est supprimé
        }
    }
}

void Pokeball::removeOneFromPokeball(int id) {
    for (auto it = pokemonList.begin(); it != pokemonList.end(); /* no increment here */) {
        if ((*it)->getId() == id) {
            delete *it;  // Libère la mémoire de l'objet
            it = pokemonList.erase(it);  // Supprime l'élément du vecteur et obtient l'itérateur suivant
            break;
        } else {
            ++it;  // Incrémente l'itérateur uniquement si aucun élément n'est supprimé
        }
    }
}


void Pokeball::displayPokeballList() const {
    std::cout << "Liste des Pokémon dans la pokeball:" << std::endl;
    for (size_t i = 0; i < pokemonList.size(); ++i) {
        std::cout << i << " : " << pokemonList[i]->getName() << std::endl;
    }
}


std::vector<std::string> Pokeball::selectInPokeball() {
    std::vector<std::string> names;

    // Afficher la liste des Pokémon dans la Pokéball
    displayPokeballList();
    std::cout << "Quels Pokémon voulez-vous ajouter à votre party ?" << std::endl;

    std::vector<int> indexs;
    std::string line;
    std::cout << "Veuillez entrer des entiers séparés par des espaces : ";
    std::getline(std::cin, line);  // Lire la ligne entière d'entrée

    std::istringstream stream(line);  // Flux de chaînes pour extraire les entiers
    int number;

    while (stream >> number) {  // Extraire chaque entier
        indexs.push_back(number);  // Ajouter l'entier au vecteur
    }

    for (int index : indexs) {
        if (index >= 0 && index < pokemonList.size()) {
            names.push_back(pokemonList[index]->getName());
        } else {
            std::cerr << "Index " << index << " est invalide." << std::endl;
        }
    }
    return names;  // Retourner le vecteur des noms
}

void Pokeball::addPokemon(Pokemon *pokemon) {
    pokemonList.push_back(pokemon);
}

int Pokeball::getNumberOfPokemon() {
    return pokemonList.size();
}
