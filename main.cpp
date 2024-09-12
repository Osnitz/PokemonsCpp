#include <iostream>
#include "pokedex.h"
#include "pokemon.h"
#include "Pokeball.h"
#include <vector>
#include "PokemonParty.h"

using namespace std;

int main(){
    /*Pokemon charizard(1, "Charizard",100,115,50,1);
    charizard.displayInfo();

    Pokemon pikachu(1, "Pikachu",100,15,10,1);
    pikachu.displayInfo();

    charizard.attackAnother(pikachu);
    std::cout <<"Nombre de Pokemon en memoire : " << Pokemon::getNumberOfPokemon() << std::endl;*/

    // Utilisation du Singleton pour obtenir l'instance du Pokedex
    Pokedex* pokedex = Pokedex::GetInstance("../ressources/pokedex.csv");

    /*Pokemon* pikachu = pokedex -> addPokemon("Pikachu");
    pikachu->displayInfo();*/

    /*Pokemon* bulbasaur = pokedex -> addPokemon(1);
    bulbasaur->displayInfo();*/

    Pokeball pokeball;
    pokeball.addPokemon(1);
    pokeball.addPokemon(12);
    pokeball.addPokemon(3);
    pokeball.addPokemon(4);
    pokeball.addPokemon(115);
    pokeball.addPokemon(28);
    pokeball.addPokemon(30);
    pokeball.addPokemon(73);
    pokeball.addPokemon(617);
    pokeball.addPokemon(111);
    ::cout << "Nombre de Pokémon en mémoire : " << Pokemon::getNumberOfPokemon() << std::endl;
    pokeball.displayPokeballList();
    ::cout<< "------------------------------------------------"<< endl;
    //pokeball.displayPokeballList();
    //pokeball.aPokemon("Pikachu");
    //pokeball.displayPokeballList();
    //::cout << "Nombre de Pokémon en mémoire : " << Pokemon::getNumberOfPokemon() << std::endl;
    //pokeball.removeOneFromPokeball(1);
    //pokeball.displayPokeballList();

    /*vector<int> ids = {1,2,3,4,5,6};
    vector<string> names ={"Bulbasaur","Charmander","Pikachu"};*/
    PokemonParty party(&pokeball);
    ::cout << "Nombre de Pokémon en mémoire : " << Pokemon::getNumberOfPokemon() << std::endl;
    party.displayParty();
    pokeball.displayPokeballList();
    ::cout<< "-------------------- ADD POKEMON TO PARTY ----------------------------"<< endl;
    party.addPokemon(&pokeball);
    party.displayParty();
    ::cout<< "------------------------------------------------"<< endl;
    pokeball.displayPokeballList();
    ::cout<< "------------------------------------------------"<< endl;
    ::cout << "Nombre de Pokémon en mémoire : " << Pokemon::getNumberOfPokemon() << std::endl;

    return 0;
}
