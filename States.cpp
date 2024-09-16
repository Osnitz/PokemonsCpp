//
// Created by matthieu on 12/09/24.
//

#include "States.h"
#include "Player.h"
#include<limits>

#include "Pokeball.h"
#include "pokemon.h"


void AttenteState::enter(Player &player) {
    std::cout << "----------------- POKEMON version (w)IS(h) -----------------" << std::endl;
    std::cout << "             Appuyez sur 'Entrée' pour jouer..." << std::endl;
    // Attendre que l'utilisateur appuie sur Entrée
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void AttenteState::handleInput(Player &player) {
    std::cout << "En attente de l'initialisation du jeu..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    player.changeState(new InitState());
}


void InitState::enter(Player &player) {
    std::cout << "Sacha se prépare... " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void InitState::handleInput(Player &player) {
    std::cout << "Ca y'est il sort de chez lui !" << std::endl;
    player.initialize();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    player.changeState(new ExplorationSansDangerState());
}


void ExplorationSansDangerState::enter(Player &player) {
    std::cout << std::endl;
    std::cout << "--------- Entrée en mode Exploration sans danger ---------" << std::endl;
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void ExplorationSansDangerState::handleInput(Player &player) {
    std::cout << "Aucun danger en vue. Direction le laboratoire !" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
    std::cout << "**Le professeur Tauvel vous a fait des cadeaux !**" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "** Vous recevez un pokedex ! **" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    auto pokedex = Pokedex::GetInstance("/home/matthieu/Cours/Exercices/Pokemons/ressources/pokedex.csv");

    /*std::cout<<"** Vous placez votre pokedex dans votre sac **"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));*/

    std::cout << "**Vous recevez une pokeball !**" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "**Il semblerait qu'il y'ai quelque chose dedans !**" << std::endl;

    auto pokeball = new Pokeball();
    for (int i = 0; i < 20; i++) {
        pokeball->addPokemon(pokedex->getOneRandomPokemon()->getName());
    }

    player.givePokeball(pokeball);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto pokemonParty = new PokemonParty(player.getPokeball());
    std::vector<string> namesToAdd = pokeball->selectInPokeball();
    for (string name: namesToAdd) {
        pokemonParty->addPokemon(name, pokeball);
    }
    player.givePokemonParty(pokemonParty);
    std::cout << std::endl;
    if (pokemonParty->countAlivePokemon() <= 0) {
        std::cout << "Vous n'avez sélectionné aucun pokemon" << std::endl;
        player.changeState(new GameOverState());
    } else {
        player.getPokemonParty()->displayParty();
        std::this_thread::sleep_for(std::chrono::seconds(2));


        player.changeState(new ExplorationState());
    }
}


void ExplorationState::enter(Player &player) {
    std::cout << std::endl;
    std::cout << "--------- Exploration avec possibilité de combat.---------" << std::endl;
    std::cout << std::endl;
    std::cout << "**Vous partez à l'aventure dans les hautes herbes** " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void ExplorationState::handleInput(Player &player) {
    while (true) {
        if (player.encounterWildPokemon(3)) {
            std::cout << std::endl;
            std::cout << "** Un pokemon sauvage apparait ! **" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Un combat commence !" << std::endl;
            player.changeState(new CombatState());
            break;
        } else {
            std::cout << "**** Marche ******" << std::endl;
            break;
        }
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));;
}


void CombatState::enter(Player &player) {
    std::cout << "------------------------- Combat -------------------------" << std::endl;
}

void CombatState::handleInput(Player &player) {
    player.battle();
    if (player.getCurrentState() == this) {
        if (!player.getFuitePlayer() and !player.getCapture()) { player.addOneNumberOfWins(); }
        player.setFuitePlayer(false);
        if (player.getNumberOfWins() >= 3) {
            player.changeState(new WinState());
        } else {
            player.setcapture(false);
            player.changeState(new ExplorationState());
        }
    }
}


void GameOverState::enter(Player &player) {
    std::cout << "------------------------- Game Over -------------------------" << std::endl;
}


void GameOverState::handleInput(Player &player) {
    player.setGameOver(true);
}

void WinState::enter(Player &player) {
    std::cout << "------------------------- Win ---------------------------" << std::endl;
    std::cout << " Félicitations vous avez gagné !" << std::endl;
}


void WinState::handleInput(Player &player) {
    player.setGameOver(true);
}
