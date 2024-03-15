#ifndef EMPLOYEE_DATABASE_H
#define EMPLOYEE_DATABASE_H

#include "Employee.h"
#include <vector>

class EmployeeDatabase{

    public:
        
        /**
         * This method adds an employee to the database.
         * 
         * @param name the name of the employee
         * @param title the title of the employee
         * @param wage the wage of the employee
         * 
        */
        void add(string name, string title, double wage);

        /**
         * This method returns the database as a string.
         * 
         * @return the database as a string.
        */
        string databaseToString();

        /**
         * This method returns the information of an employee as a string from a give index.
         * 
         * @param index the index of the employee in the database.
         * 
         * @return the employee as a string.
        */
        string employeeToString(int index);

        /**
         * Calculates the total wages of all the Employees in the database.
         * 
         * @returns the total wages
        */
        double calcTotalWages();
    private:
        /**
         * The list of Employees.
        */
        vector<Employee> database;

};

#endif