#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <sstream>

using std::string;
using std::stringstream;

class Player {
    public:
    Player(int x, int y){
        health = MAX_HEALTH;
        hunger = MAX_HUNGER;
        thirst = MAX_THIRST;
        
        this->x = x;
        this->y = y;
        this->score = 0;
    }
    
    int getScore() const {
        return score;
    }
    
    void takeDamage(int val){
        this->health -= val;
        if(this->health < 0) this->health = 0;
    }

    void takeTurn(){
        if(this->hunger == 0 || this->thirst == 0){
            this->health--;
        }

        this->thirst--;
        this->hunger--;
        
        if(this->hunger < 0){
            this->hunger = 0;
        }
        
        if(this->thirst < 0){
            this->thirst = 0;
        }   

        this->score++;
    }
    
    string getStats() const {
        stringstream ss;
        ss  << "============\n"
            << "Health: " << this->health << "\n" 
            << "Hunger: " << this->hunger << "\n" 
            << "Thirst: " << this->thirst << "\n"
            << "============\n";
        return ss.str();
    }
    
    bool isAlive() const {
        return this->health > 0;
    }
    
    void increaseThrist(int val){
        this->thirst += val;
        if(this->thirst > MAX_THIRST) this->thirst = MAX_THIRST;
    }
    
    void increaseHunger(int val){
        this->hunger += val;
        if(this->hunger > MAX_HUNGER) this->hunger = MAX_HUNGER;
    }

    void heal(int val){
        this->health += val;
        if(this->health > MAX_HEALTH) this->health = MAX_HEALTH;
    }
    
    int x, y;
    private:
    int health, hunger, thirst, score;
    const int MAX_HEALTH = 5;
    const int MAX_HUNGER = 5;
    const int MAX_THIRST = 3;
};

#endif