#include "PokemonParty.h"

#include <strings.h>

PokemonParty::PokemonParty(Pokeball *pokeball) {
    // construit la partie avec le premier pokemon dans la pokeball
    //std::vector<string> names = pokeball->selectInPokeball();
    auto pokemon = pokeball->getPokemon(0);
    Pokemon* newPokemon = new Pokemon(*pokemon);
    pokemonList.push_back(newPokemon);
    pokeball->removeOneFromPokeball(newPokemon->getName());
    /*if (names.size() <= 6) {
        for (string name : names) {
            //std::cout << "id = " << id << std::endl;
            auto pokemon = pokeball->getPokemon(name);
            auto newPokemon = new Pokemon(*pokemon);
            //Pokemon* newPokemon = new Pokemon(*pokemon);
            // Ajouter le pointeur dans le vecteur
            pokemonList.push_back(newPokemon);
            pokeball->removeOneFromPokeball(name);
        }
    } else {
        std::cerr << "Trop de Pokémon fournis. La party ne peut contenir que 6 Pokémon." << std::endl;
    }*/
}

PokemonParty::~PokemonParty() {
    // Libérer la mémoire de chaque Pokémon dans pokemonList
    for (Pokemon* pokemon : pokemonList) {
        delete pokemon;  // Libérer chaque Pokémon alloué dynamiquement
    }
    pokemonList.clear();
}

void PokemonParty::displayParty() const {
    std::cout << "Liste des Pokémon dans la party pokemon:" << std::endl;
    for (size_t i = 0; i < pokemonList.size(); ++i) {
        std::cout << i << " : " << pokemonList.at(i)->getName() << std::endl;
    }
}

Pokemon* PokemonParty::getPokemon(const string &name) {
    for(Pokemon* pokemon : pokemonList) {
        if(pokemon->getName()==name){
            return pokemon;//renvoie un pointeur
        }
    }
}

Pokemon* PokemonParty::getPokemon(int id) {
    for(Pokemon* pokemon : pokemonList) {
        if(pokemon->getId()==id){
            return pokemon;
        }
    }
}

void PokemonParty::removePokemon(const std::string& name) {
    bool found = false;

    for (size_t i = 0; i < pokemonList.size(); ++i) {
        if (pokemonList[i]->getName() == name) {
            // Supprimer le Pokémon
            delete pokemonList[i];
            pokemonList.erase(pokemonList.begin() + i);
            found = true;
            break;  // Quitter la boucle après la suppression
        }
    }
    if (!found) {
        throw std::invalid_argument("Le Pokémon avec le nom " + name + " n'existe pas dans la party.");
    }
}

void PokemonParty::removePokemon(int Id) {
    bool found = false;

    for (size_t i = 0; i < pokemonList.size(); ++i) {
        if (pokemonList[i]->getId() == Id) {
            // Supprimer le Pokémon
            delete pokemonList[i];
            pokemonList.erase(pokemonList.begin() + i);
            found = true;
            break;
        }
    }
    if (!found) {
        throw std::invalid_argument("Le Pokémon avec l'identifiant " + std::to_string(Id) + " n'existe pas dans la party.");
    }
}

void PokemonParty::removeAllPokemon() {
    for (Pokemon* pokemon : pokemonList) {
        delete pokemon;
    }
    pokemonList.clear();
}

void PokemonParty::addPokemon(Pokeball* pokeball) {
    std::vector<string> names = pokeball->selectInPokeball();
    if (names.size() <= 6) {
        for (string name : names) {
            if (pokemonList.size() < 6) {
                // Récupérer le Pokémon par ID et l'ajouter à la party
                auto pokemon = pokeball->getPokemon(name);
                auto newPokemon = new Pokemon(*pokemon);
                pokemonList.push_back(newPokemon);
                pokeball->removeOneFromPokeball(name);
        }
            else {
                std::cout << "La party est pleine. Vous ne pouvez pas ajouter plus de 6 Pokémon." << std::endl;
                std::cout << "Voulez-vous supprimer un Pokémon pour ajouter"<< name<<" ? (oui/non):" <<std::endl;

                // Lire la réponse de l'utilisateur
                std::string answer;
                std::getline(std::cin, answer);

                // Si l'utilisateur répond "oui"
                if (answer == "oui") {
                    displayParty();
                    std::cout << "Entrez le nom du Pokémon à supprimer : ";
                    std::string pokemonName;
                    std::getline(std::cin, pokemonName);

                    try {
                        // Supprimer le Pokémon de la party
                        removePokemon(pokemonName);
                        std::cout<<pokemonName<<" a été supprimé de la partie"<<std::endl;
                        // Ajouter le nouveau Pokémon après suppression
                        auto pokemon = pokeball->getPokemon(name);
                        auto newPokemon = new Pokemon(*pokemon);
                        pokemonList.push_back(newPokemon);
                        pokeball->removeOneFromPokeball(name);
                        ;
                    } catch (const std::invalid_argument& e) {
                        std::cout << e.what() << std::endl;  // Afficher l'erreur si le Pokémon n'est pas trouvé
                    }
                } else {
                    std::cout << "Aucun Pokémon n'a été ajouté." << std::endl;
                }
        }
    }}


}

void PokemonParty::addPokemon(const string& name, Pokeball* pokeball) {
    if (pokemonList.size() < 6) {
        // Récupérer le Pokémon par ID et l'ajouter à la party
        auto pokemon = pokeball->getPokemon(name);
        auto newPokemon = new Pokemon(*pokemon);
        pokemonList.push_back(newPokemon);
        pokeball->removeOneFromPokeball(name);
    } else {
        std::cout << "La party est pleine. Vous ne pouvez pas ajouter plus de 6 Pokémon." << std::endl;
        std::cout << "Voulez-vous supprimer un Pokémon ? (oui/non): ";

        // Lire la réponse de l'utilisateur
        std::string answer;
        std::getline(std::cin, answer);

        // Si l'utilisateur répond "oui"
        if (answer == "oui") {
            displayParty();
            std::cout << "Entrez le nom du Pokémon à supprimer : ";
            std::string pokemonName;
            std::getline(std::cin, pokemonName);

            try {
                // Supprimer le Pokémon de la party
                removePokemon(pokemonName);
                // Ajouter le nouveau Pokémon après suppression
                addPokemon(name, pokeball);
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;  // Afficher l'erreur si le Pokémon n'est pas trouvé
            }
        } else {
            std::cout << "Aucun Pokémon n'a été ajouté." << std::endl;
        }
    }
}




