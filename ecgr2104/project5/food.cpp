#include "food.h"

// Constructors

Food::Food(const std::string& name){
    setName(name);
    setCalories(0);
    setTotalFat(0);
    setSugars(0);
    setProtiens(0);
    setSodium(0);
}

Food::Food(const std::string& name, const int& calories, const int& totalFat, const int& sugars, const int& protiens, const int& sodium){
    setName(name);
    setCalories(calories);
    setTotalFat(totalFat);
    setSugars(sugars);
    setProtiens(protiens);
    setSodium(sodium);
}

// Public Functions

std::string Food::getName() const {
    return this->name;
}

int Food::getCalories() const {
    return this->calories;
}

int Food::getTotalFat() const {
    return this->totalFat;
}

int Food::getSugars() const {
    return this->sugars;
}

int Food::getProtiens() const {
    return this->protiens;
}

int Food::getSodium() const {
    return this->sodium;
}

void Food::setName(const std::string& name){
    this->name = name;
}

void Food::setCalories(const int& calories){
    this->calories = floorClamp(calories, 0);
}

void Food::setTotalFat(const int& totalFat){
    this->totalFat = floorClamp(totalFat, 0); 
}

void Food::setSugars(const int& sugars){
    this->sugars = floorClamp(sugars, 0);
}

void Food::setProtiens(const  int& protiens){
    this->protiens = floorClamp(protiens, 0);
}

void Food::setSodium(const int& sodium){
    this->sodium = floorClamp(sodium, 0);
}

Food Food::operator+(const Food& rhs) const {
    return Food((this->name + " & " + rhs.getName()), this->calories + rhs.getCalories(), this->totalFat + rhs.getTotalFat(), this->sugars + rhs.getSugars(), this->protiens + rhs.getProtiens(), this->sodium + rhs.getSodium());
}

// Private Functions

int Food::floorClamp(const int& val, const int& low){
    if(val < low){
        return low;
    } else {
        return val;
    }
}