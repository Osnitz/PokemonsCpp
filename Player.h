// player.h
// Created by matthieu on 12/09/24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Pokeball.h"
#include "PokemonParty.h"
#include "pokedex.h"
#include "States.h"
#include <thread>


class Player {
private:
    State* currentState;
    Pokeball* pokeball = nullptr;
    PokemonParty* pokemonParty = nullptr;
    int numberOfWins = 0;
    bool isGameOver = false;
    bool fuitePlayer = false;
    bool capture=false;

public:
    // Initialise l'état du joueur.
    Player();

    // Destructeur de la classe Player.
    ~Player();

    State * getCurrentState() const;

    // newState : Pointeur vers le nouvel état à appliquer au joueur.
    void changeState(State* newState);

    // Gère les entrées utilisateur
    void handleInput();


    // Initialise l'état initial avant le début du jeu.
    void initialize();

    //le joueur rencontre un Pokémon sauvage.
    bool encounterWildPokemon(int chanceOutOf);

    // Gère le combat entre le joueur et un Pokémon
    void battle();

    void givePokeball(Pokeball* newPokeball);
    Pokeball* getPokeball();

    void givePokemonParty(PokemonParty* newPokemonParty);
    PokemonParty* getPokemonParty();

    void givePokedex(Pokedex* newPokedex);
    Pokedex* getPokedex();
    int getNumberOfWins();
    void addOneNumberOfWins();
    void setGameOver(bool value);
    bool getGameOver() const;
    bool getFuitePlayer() const;
    void setFuitePlayer(bool value);
    bool getCapture() const;
    void setcapture(bool value);
};

void runCombat(Pokemon* battlePokemon, Pokemon wildPokemon);

#endif // PLAYER_H
