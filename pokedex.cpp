//
// Created by matthieu on 09/09/24.
//

#include "pokedex.h"
#include <fstream>
#include <sstream>

//Pokemon charizard(1, "Charizard",100,115,50,1);

Pokedex* Pokedex::instance = nullptr;

Pokedex::Pokedex(const string &fileName){
    std::cout<< "Pokedex constructor" << std::endl;
    std::ifstream file(fileName); // Ouvre le file
    if (!file.is_open()) { // Vérifie si le file est bien ouvert
        std::cerr << "Impossible d'ouvrir le file : " << fileName << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) { // Lit le file line par line
        std::stringstream ss(line); // Utilise un flux pour diviser la line
        std::string cellule;
        std::vector<std::string> linedata;
        // Divise la line en cellules séparées par des virgules
        while (std::getline(ss, cellule, ',')) {
            linedata.push_back(cellule); // Ajoute chaque cellule au vecteur
        }

        int id = std::stoi(linedata.at(0));
        string name = linedata.at(1);
        string type1 = linedata.at(2);
        string type2 = linedata.at(3);
        double healthValue =std::stod(linedata.at(5));
        double attackValue =std::stod(linedata.at(6));
        double defenseValue =std::stod(linedata.at(7));
        //double attackSpeValue=std::stod(linedata.at(8));
        //double defenseSpeValue=std::stod(linedata.at(9));
        //double speed = std::stod(linedata.at(10));
        int generation = std::stoi(linedata.at(11));
        string legendary = linedata.at(12);

        auto* newPokemon = new Pokemon (id,name,healthValue,attackValue,defenseValue,generation);

        pokemonList.push_back(newPokemon);

        // Affiche les données de la line
        /*for (const auto& valeur : linedata) {
            std::cout << valeur << " "; // Affiche les valeurs séparées par un espace
        }*/
    }
    file.close(); // Ferme le file
}

Pokedex::~Pokedex() {
    std::cout << "Ici le destructeur de pokedex" << std::endl;
}


Pokedex* Pokedex::GetInstance(const std::string& fileName) {
    if (instance == nullptr) {
        instance = new Pokedex(fileName);
    }
    return instance;
}

Pokemon Pokedex::getPokemonById(int id) {
    int index = findById(id);
    if (index != -1) {
        return *pokemonList.at(index);  // Renvoie une copie du Pokémon
    } else {
        throw std::invalid_argument("Le Pokémon avec l'ID " + std::to_string(id) + " n'existe pas dans le Pokedex.");
    }
}

Pokemon Pokedex::getPokemonByName(const string& name) {
    int index = findByName(name);
    if (index != -1) {
        return *pokemonList.at(index);  // Renvoie une copie du Pokémon
    } else {
        throw std::invalid_argument("Le Pokémon avec le nom " + name + " n'existe pas dans le Pokedex.");
    }
}
