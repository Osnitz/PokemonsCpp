//
// Created by matthieu on 12/09/24.
//

#include "Player.h"
#include <iostream>

Player::Player() : currentState(new AttenteState()) {
    currentState->enter(*this);
}

Player::~Player() {
    delete currentState;
}

void Player::changeState(State* newState) {
    delete currentState;
    currentState = newState;
    currentState->enter(*this);
}

void Player::handleInput() {
    currentState->handleInput(*this);
}

void Player::update() {
    currentState->update(*this);
}

void Player::initialize() {
    // Initialisation du joueur
}

bool Player::encounterWildPokemon() {
    return rand() % 2;
}

void Player::battle() {
    // Combat entre Pokémon
}
