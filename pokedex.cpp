//
// Created by matthieu on 09/09/24.
//

#include "pokedex.h"
#include <fstream>
#include <sstream>

Pokedex* Pokedex::instance = nullptr;

Pokedex::Pokedex(const string &fileName){
    //std::cout<< "Pokedex constructor" << std::endl;
    std::ifstream file(fileName); // Ouvre le ficher
    if (!file.is_open()) { // Vérifie si le fichier est bien ouvert
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
    }
    file.close(); // Ferme le file
}

Pokedex::~Pokedex() {
    for (auto pokemon : pokemonList) {
        delete pokemon;  // Libère la mémoire allouée pour chaque Pokémon
    }
    pokemonList.clear();  // Vide le vecteur pour éviter des pointeurs pendants

    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}



Pokedex* Pokedex::GetInstance(const std::string& fileName) {
    if (instance == nullptr) {
        instance = new Pokedex(fileName);
    }
    return instance;
}

Pokemon *Pokedex::getPokemon(int id) {
    int index = findPokemon(id);
    if (index != -1) {
        return pokemonList.at(index);//renvoie un pointeur
    } else {
        throw std::invalid_argument("Le Pokémon avec l'ID " + std::to_string(id) + " n'existe pas dans le Pokedex.");
    }
}

Pokemon* Pokedex::getPokemon(const string& name) {
    int index = findPokemon(name);
    if (index != -1) {
        return pokemonList.at(index);
    } else {
        throw std::invalid_argument("Le Pokémon avec le nom " + name + " n'existe pas dans le Pokedex.");
    }
}

Pokemon *Pokedex::getOneRandomPokemon() {
    std::random_device rd;   // Graine
    std::mt19937 gen(rd());  // Générateur Mersenne Twister
    std::uniform_int_distribution<> distrib(0, pokemonList.size() - 1);  // Distribution uniforme entre 0 et pokedexSize-1
    auto pokemon = pokemonList[distrib(gen)];
    return pokemon;
}

int Pokedex::getNumberOfPokemon() {
    return pokemonList.size();
}

