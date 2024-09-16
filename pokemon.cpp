//
// Created by matthieu on 09/09/24.
//

#include "pokemon.h"
#include<iostream>

int Pokemon::numberOfPokemon=0;

// Constructeur
Pokemon::Pokemon(int id, const string& name, double hitPoint, double attack, double defense, int generation)
    : id(id), name(name), hitPoint(hitPoint), attack(attack), defense(defense), generation(generation) {
    numberOfPokemon++;
}

// Constructeur de recopie
Pokemon::Pokemon(const Pokemon& other)
    : id(other.id), name(other.name), hitPoint(other.hitPoint), attack(other.attack), defense(other.defense), generation(other.generation) {
    //std::cout << "Constructeur de recopie appelé pour " << name << std::endl;
    numberOfPokemon++;
}

// Destructeur
Pokemon::~Pokemon() {
    numberOfPokemon--;
    //std::cout << "Ici le destructeur de pokemon appelé pour " << name << std::endl;
}

void Pokemon::displayInfo()const{
    std::cout<<"ID : "<< id << std::endl;
    std::cout<<"Name : "<< name << std::endl;
    std::cout<<"HitPoint : "<< hitPoint<<std::endl;
    std::cout<<"Attack : "<< attack<< std::endl;
    std::cout<<"Defense : "<<defense<<std::endl;
    std::cout<<"Generation : "<<generation<<std::endl;
}

int Pokemon::getNumberOfPokemon() {
    return numberOfPokemon;
}

string Pokemon::getName()const {
    return name;
}
int Pokemon::getId()const {
    return id;
}

int Pokemon::getHitPoint() {
    return hitPoint;
}

bool Pokemon::isAlive() {
    auto hitPoint = getHitPoint();
    if(hitPoint > 0) {
        return true;
    }
    else {
        return false;
    }

}



void Pokemon::attackAnother(Pokemon& target) const {
    std::cout << name << " attaque " << target.name << std::endl;
    double damage = attack - target.defense;
    if (damage < 0) {
        damage = 0; // Les dégâts ne peuvent pas être négatifs
    }
    target.hitPoint -= damage;
    std::cout << name << " inflige " << damage << " points de dégâts à " << target.name << std::endl;
    if (target.hitPoint <= 0) {
        std::cout<<target.name<< " est mort"<<std::endl;
    }
    else {
        std::cout << " Il reste "<< target.hitPoint<<"points de vie à "<< target.name<<std::endl;
        std::cout<<std::endl;
    }
}



