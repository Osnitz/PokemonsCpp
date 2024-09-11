#include <iostream>
#include "pokedex.h"
#include "pokemon.h"
#include "Pokeball.h"

int main(){
    /*Pokemon charizard(1, "Charizard",100,115,50,1);
    charizard.displayInfo();

    Pokemon pikachu(1, "Pikachu",100,15,10,1);
    pikachu.displayInfo();

    charizard.attackAnother(pikachu);
    std::cout <<"Nombre de Pokemon en memoire : " << Pokemon::getNumberOfPokemon() << std::endl;*/

    // Utilisation du Singleton pour obtenir l'instance du Pokedex
    Pokedex* pokedex = Pokedex::GetInstance("../ressources/pokedex.csv");

    Pokemon pikachu = pokedex -> getPokemonByName("Pikachu");
    pikachu.displayInfo();

    Pokemon bulbasaur = pokedex -> getPokemonById(1);
    bulbasaur.displayInfo();

    Pokeball* pokeball = new Pokeball();



    std::cout << "Nombre de Pokémon en mémoire : " << Pokemon::getNumberOfPokemon() << std::endl;
    return 0;
}