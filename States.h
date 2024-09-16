//
// Created by matthieu on 12/09/24.
//

#ifndef STATES_H
#define STATES_H
#include <iostream>

class Player;

class State {
public:
    virtual ~State() = default;

    virtual void handleInput(Player& player) = 0;
    virtual void enter(Player& player) = 0;
};

class AttenteState : public State {
public:
    void handleInput(Player& player) override;
    void enter(Player& player) override;
};

class InitState : public State {
public:
    void handleInput(Player& player) override;
    void enter(Player& player) override;
};

class ExplorationSansDangerState : public State {
public:
    void handleInput(Player& player) override;
    void enter(Player& player) override;
};

class ExplorationState : public State {
public:
    void handleInput(Player& player) override;
    void enter(Player& player) override;
};

class CombatState : public State {
public:
    void handleInput(Player& player) override;
    void enter(Player& player) override;
};

class GameOverState : public State {
public:
    void handleInput(Player& player) override;
    void enter(Player& player) override;
};

class WinState : public State {
    public:
    void handleInput(Player& player) override;
    void enter(Player& player) override;
};

#endif // STATES_H

