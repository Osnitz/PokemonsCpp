//
// Created by matthieu on 12/09/24.
//

#include "States.h"
#include "States.h"
#include "Player.h"

void AttenteState::handleInput(Player& player) {
    std::cout << "En attente de l'initialisation du jeu..." << std::endl;
    player.changeState(new InitState());
}

void AttenteState::update(Player& player) {}

void AttenteState::enter(Player& player) {
    std::cout << "Le joueur est en état d'attente." << std::endl;
}

void InitState::handleInput(Player& player) {
    std::cout << "Initialisation du jeu..." << std::endl;
    player.initialize();
    player.changeState(new ExplorationSansDangerState());
}

void InitState::update(Player& player) {}

void InitState::enter(Player& player) {
    std::cout << "Initialisation en cours..." << std::endl;
}

void ExplorationSansDangerState::handleInput(Player& player) {
    std::cout << "Vous explorez sans danger." << std::endl;
    player.changeState(new ExplorationState());
}

void ExplorationSansDangerState::update(Player& player) {}

void ExplorationSansDangerState::enter(Player& player) {
    std::cout << "Entrée en mode Exploration sans danger." << std::endl;
}

void ExplorationState::handleInput(Player& player) {
    std::cout << "Exploration avec possibilité de rencontre." << std::endl;
    if (player.encounterWildPokemon()) {
        player.changeState(new CombatState());
    }
}

void ExplorationState::update(Player& player) {}

void ExplorationState::enter(Player& player) {
    std::cout << "Exploration avec possibilité de combat." << std::endl;
}

void CombatState::handleInput(Player& player) {
    std::cout << "Un combat commence !" << std::endl;
    player.battle();
    player.changeState(new ExplorationState());
}

void CombatState::update(Player& player) {}

void CombatState::enter(Player& player) {
    std::cout << "Entrée en mode Combat." << std::endl;
}

