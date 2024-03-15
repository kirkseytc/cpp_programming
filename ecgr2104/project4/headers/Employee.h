#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {

    public:
        /**
         * This is the default constructor for Employee.
        */
        Employee();

        /**
         * This is the paramater constructor for Employee.
         * 
         * @param name the name of the employee
         * @param title the title of the employee
         * @param wage the wage of the employee
        */
        Employee(const string& name, const string& title, const double& wage);

        /**
         * Sets the "name" of the Employee to the given value.
         * 
         * @param name the new value of "name"
         * 
        */
        void setName(const string& name);

        /**
         * Sets the "title" of the Employee to the given value.
         * 
         * @param title the new value of "title"
         * 
        */
        void setTitle(const string& title);

        /**
         * Sets the "wage" of the Employee to the given value.
         * 
         * If the value given is below 0, 
         * then "wage" will be set to 0.0 
         * 
         * @param wage the new value of "wage"
         * 
        */
        void setWage(const double& wage);

        /**
         * Retrieves the value stored under "name" in Employee.
         * 
         * @return the value of "name"
        */
        string getName() const;

        /**
         * Retrieves the value stored under "title" in Employee.
         * 
         * @return the value of "title"
        */
        string getTitle() const;

        /**
         * Retrieves the value stored under "wage" in Employee.
         * 
         * @return the value of "wage"
        */
        double getWage() const;
    private:
        /**
         * The name of the Employee.
        */
        string name;

        /**
         * The title of the Employee.
        */
        string title;

        /**
         * The wage of the Employee.
         * This value should not be less than 0.0.
        */
        double wage;

};

#endif