//
// Created by matthieu on 12/09/24.
//

#include "Player.h"
#include <iostream>
#include <set>

Player::Player() : currentState(new AttenteState()) {
    currentState->enter(*this);
}

Player::~Player() {
    if (currentState) {
        delete currentState;
        currentState = nullptr;
    }

    if (pokeball) {
        delete pokeball;
        pokeball = nullptr;
    }

    if (pokemonParty) {
        delete pokemonParty;
        pokemonParty = nullptr;
    }
}

State *Player::getCurrentState() const {
    return currentState;
}

void Player::changeState(State *newState) {
    delete currentState;
    currentState = newState;
    currentState->enter(*this);
}

void Player::handleInput() {
    currentState->handleInput(*this);
    //std::cout<<"Player::handleInput"<<std::endl;
}


void Player::initialize() {
}

bool Player::encounterWildPokemon(int chanceOutOf) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, chanceOutOf - 1);

    int randomValue = distrib(gen);
    return randomValue == 0;
}

void Player::battle() {

    auto pokedex = Pokedex::GetInstance("../ressources/pokedex.csv");
    // Obtenir un Pokémon sauvage aléatoire
    auto wildPokemon = new Pokemon(*pokedex->getOneRandomPokemon());
    std::cout << "Wild Pokémon:" << std::endl;
    wildPokemon->displayInfo();
    int wildPokemonInitialHitPoint = wildPokemon->getHitPoint();
    std::cout << std::endl;

    int numberOfAlivePokemon = pokemonParty->countAlivePokemon();

    Pokemon *battlePokemon = nullptr;

    while (wildPokemon->isAlive() && numberOfAlivePokemon > 0 and !getCapture()) {
        // Sélectionner le premier Pokémon vivant si aucun pokemon n'est sélectionné
        if (battlePokemon == nullptr) {
            for (int i = 0; i < pokemonParty->getNumberOfPokemon(); i++) {
                if (pokemonParty->getPokemon(i)->isAlive()) {
                    battlePokemon = pokemonParty->getPokemon(i);
                    break;
                }
            }
        }
        if (battlePokemon == nullptr) {
            std::cout << "Tous vos Pokémon sont KO !" << std::endl;
            changeState(new GameOverState());
            break;
        }

        std::cout << "Player's Pokémon:" << std::endl;
        battlePokemon->displayInfo();
        std::cout << std::endl;
        //std::cout <<"Nombre de Pokemon en memoire : " << Pokemon::getNumberOfPokemon() << std::endl;

        // Combat entre le Pokémon du joueur et le Pokémon sauvage
        int counter = 0;
        while (counter < 8 and battlePokemon->isAlive() and wildPokemon->isAlive()) {
            counter++;
            battlePokemon->attackAnother(*wildPokemon);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (wildPokemon->isAlive() and wildPokemon->getHitPoint() < wildPokemonInitialHitPoint / 3) {
                // Scénario da capture
                std::cout << "Vous pouvez tenter de capturer " << wildPokemon->getName() << std::endl;
                std::cout << "Voulez vous lancer une pokeball ? (y/n) : " << std::endl;
                string answer;
                std::cin >> answer;
                if (answer == "y") {
                    std::cout << " POKEBALL !! " << std::endl;
                    if (encounterWildPokemon(3)) {
                        // J'utilise le générateur aléatoire pour définir le pourcentage de chance de capture
                        pokeball->addPokemon(wildPokemon);
                        std::cout << " 1.... " << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << " 2.... " << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << " 3.... " << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << " Capture Réussie ! " << std::endl;
                        setcapture(true);
                        break;
                    }

                    std::cout << " 1.... " << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << " 2.... " << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << wildPokemon->getName() << " s'est enfuit de la pokeball " << std::endl;
                }
            }

            if (wildPokemon->isAlive()) {
                wildPokemon->attackAnother(*battlePokemon);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }

        if (battlePokemon->isAlive() and wildPokemon->isAlive() and !getCapture()) {
            std::cout << wildPokemon->getName() << " a pris la fuite !" << std::endl;
            break; // Le Pokémon sauvage fuit, fin du combat
        }
        if (!battlePokemon->isAlive()) {
            // Le Pokémon du joueur est KO
            //std::cout << battlePokemon->getName() << " est KO !" << std::endl;
            numberOfAlivePokemon--;

            if (numberOfAlivePokemon > 0) {
                std::cout << "Voulez-vous changer de Pokémon ou prendre la fuite ? (1 = fuite / 2 = changer de Pokémon)"
                        << std::endl;
                std::string answer;
                std::getline(std::cin, answer);

                if (answer == "1") {
                    std::cout << "Vous prenez la fuite !" << std::endl;
                    setFuitePlayer(true);
                    break; // Le joueur fuit, fin du combat
                }
                if (answer == "2") {
                    // Afficher les Pokémon vivants restants dans la party
                    pokemonParty->displayAliveParty();
                    std::cout << "Quel Pokémon voulez-vous envoyer au combat ? (entrez l'index)" << std::endl;
                    std::string index;
                    std::getline(std::cin, index);


                    int idx = std::stoi(index);
                    if (idx < 0 || idx >= 6 || !pokemonParty->getPokemon(idx)->isAlive()) {
                        std::cout << "Choix invalide. Fin du combat." << std::endl;
                        break; // Si l'utilisateur fait une mauvaise sélection, fin du combat
                    }

                    // Changer de Pokémon
                    battlePokemon = pokemonParty->getPokemon(idx);
                } // Si une autre entrée est fournie, le premier pokemon en vie de la party sera sélectionné automatiquement
            } else {
                std::cout << "Tous vos Pokémon sont KO. Fin du combat !" << std::endl;
                break;
            }
        } else if(battlePokemon->isAlive() and !wildPokemon->isAlive() and !capture) {
            // Le Pokémon du joueur a gagné
            std::cout << battlePokemon->getName() << " a gagné le combat !" << std::endl;
            break;
        }
    }


    if (numberOfAlivePokemon == 0) {
        //std::cout <<"Nombre de Pokemon en memoire : " << Pokemon::getNumberOfPokemon() << std::endl;
        changeState(new GameOverState());
    }
}


void Player::givePokeball(Pokeball *newPokeball) {
    if (pokeball != nullptr) {
        delete pokeball;
    }
    pokeball = newPokeball;
}

Pokeball *Player::getPokeball() {
    return pokeball;
}

void Player::givePokemonParty(PokemonParty *newPokemonParty) {
    if (pokemonParty != nullptr) {
        delete pokemonParty;
    }
    pokemonParty = newPokemonParty;
}


PokemonParty *Player::getPokemonParty() {
    return pokemonParty;
}

int Player::getNumberOfWins() {
    return numberOfWins;
}

void Player::addOneNumberOfWins() {
    numberOfWins++;
}

void Player::setGameOver(bool value) {
    isGameOver = value;
}

bool Player::getGameOver() const {
    return isGameOver;
}

bool Player::getFuitePlayer() const {
    return fuitePlayer;
}

void Player::setFuitePlayer(bool value) {
    fuitePlayer = value;
}

bool Player::getCapture() const {
    return capture;
}

void Player::setcapture(bool value) {
    capture = value;
}