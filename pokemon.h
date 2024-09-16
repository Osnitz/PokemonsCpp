//
// Created by matthieu on 09/09/24.
//

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include<string>
using std::string;

class  Pokemon
{
private:
    /* data */
    int id;
    string name;
    double hitPoint;
    double attack;
    double defense;
    int generation;
    static int numberOfPokemon;
public:

    // Supprime le constructeur par défaut
    Pokemon() =delete;

    // Constructeur
    Pokemon(int id, const string &name, double hitPoint, double attack, double defense, int generation);

    // Constructeur de recopie
    Pokemon(const Pokemon& other);

    // Destructeur
    ~ Pokemon();

    void displayInfo() const;



    //Getters
    static int getNumberOfPokemon();
    int getId() const;
    string getName() const;
    int getHitPoint();
    bool isAlive();
    /*double getHitPoint() const;
    double getAttack() const;
    double getDefense() const;
    int getGeneration() const;*/


    //Setters
    /*
    void setId(int newId);
    void setName(const string &newName);
    void setHitPoint(double newHitPoint);
    void setAttack(double newAttack);
    void setDefense(double newDefense);
    void setGeneration(int newGeneration);*/

    void attackAnother(Pokemon& target) const;

};

#endif // POKEMON_HPP
