#include "../headers/Employee.h"

Employee::Employee() {
    setName("null");
    setTitle("null");
    setWage(-1.0);
}

Employee::Employee(const string& name, const string& title, const double& wage){
    setName(name);
    setTitle(title);
    setWage(wage);
}

void Employee::setName(const string& name){
    this->name = name;
}

void Employee::setTitle(const string& title){
    this->title = title;
}

void Employee::setWage(const double& wage){

    if(wage < 0.0){
        this->wage = 0.0;
    } else {
        this->wage = wage;
    }

}

string Employee::getName() const {
    return this->name;
}

string Employee::getTitle() const {
    return this->title;
}

double Employee::getWage() const {
    return this->wage;
}