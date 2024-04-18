#ifndef LAND_HPP
#define LAND_HPP

#include <cstdlib>

#include "player.hpp"

using std::string;

class Land {
    public:
    virtual string getDescription() = 0;
    virtual string visit(Player& player) = 0;
};

class Forest : public Land {
    public:
    string getDescription(){
        return "a densely wooded forest.";
    }
    
    string visit(Player& player){
        short randomNum = rand() % 100;
        
        if(randomNum > 74){
            player.takeDamage(1);
            return "You are attacked by a bear while foraging for berries.";
        } else {
            player.increaseHunger(1);
            return "You forage for berries in the woods and eat a few.";
        }
    }
};

class Lake : public Land {
    public:
    string getDescription(){
        return "a clear sparkling lake.";
    }
    
    string visit(Player& player){
        player.increaseThrist(2);
        return "You visit the lake and drink its clean water";
    }
};

class Mountain : public Land {

    public:
    string getDescription(){
        return "a high and mighty mountain.";
    }

    string visit(Player& player){
        player.increaseHunger(2);
        return "You found some filling mountain berries.";
    }

};

class Desert : public Land {

    public:
    string getDescription(){
        return "a hot and aird desert.";
    }

    string visit(Player& player){
        short rng = rand() % 100;

        if(rng < 25){
            player.takeDamage(1);
            return "You took damage while trying to get a cactus fruit.";
        } else {
            player.increaseHunger(1);
            player.increaseThrist(1);
            return "You got a juicy cactus fruit without taking damage.";
        }

    }

};

class Field : public Land {

    public:
    string getDescription(){
        return "a sprawling field of flowers.";
    }

    string visit(Player& player){
        player.heal(1);
        return "You found some medicial flowers in the field and healed a little.";
    }

};

#endif