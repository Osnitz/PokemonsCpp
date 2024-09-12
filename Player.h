// player.h
// Created by matthieu on 12/09/24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "States.h"


class Player {
private:
    State* currentState;  // Pointeur vers l'état courant du joueur.

public:
    // Initialise l'état du joueur.
    Player();

    // Destructeur de la classe Player.
    ~Player();

    // newState : Pointeur vers le nouvel état à appliquer au joueur.
    void changeState(State* newState);

    // Gère les entrées utilisateur
    void handleInput();

    // Met à jour l'état du joueur en appelant la méthode update de l'état courant.
    void update();

    // Initialise l'état initial avant le début du jeu.
    void initialize();

    //le joueur rencontre un Pokémon sauvage.
    bool encounterWildPokemon();

    // Gère le combat entre le joueur et un Pokémon
    void battle();
};

#endif // PLAYER_H
