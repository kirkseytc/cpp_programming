#ifndef FOOD_H
#define FOOD_H

#include <string>

class Food {

    public:

        /**
         * The default constructor of the Food class.
         * 
         * @param name the name of the food.
        */
        Food(const std::string& name);

        /**
         * The alternate constructor of the Food class.
         * 
         * @param name the name of the food.
         * @param calories the calories of the food.
         * @param totalFat the total fat of the food in grams.
         * @param sugars the suagrs of the food in grams.
         * @param protiens the protiens of the food in grams.
         * @param sodium the sodium of the food in milligrams.
        */
        Food(const std::string& name, const int& calories, const int& totalFat, const int& sugars, const int& protiens, const int& sodium);

        /**
         * This method returns the value stored under name.
         * 
         * @return the value of the variable name.
        */
        std::string getName() const;
        
        /**
         * This method returns the value stored under calories.
         * 
         * @return the value of the variable calories.
        */
        int getCalories() const;
        
        /**
         * This method returns the value stored under totalFats.
         * 
         * @return the value of the variable totalFats.
        */
        int getTotalFat() const;
        
        /**
         * This method returns the value stored under sugars.
         * 
         * @return the value of the variable sugars.
        */
        int getSugars() const;
        
        /**
         * This method returns the value stored under protiens.
         * 
         * @return the value of the variable protiens.
        */
        int getProtiens() const;
        
        /**
         * This method returns the value stored under sodium.
         * 
         * @return the value of the variable sodium.
        */
        int getSodium() const;
        
        /**
         * This method set the value of name to a new given value.
         * 
         * @param name the new value for name.
        */
        void setName(const std::string& name);
        
        /**
         * This method set the value of calories to a new given value.
         * 
         * @param calories the new value for calories.
        */
        void setCalories(const int& calories);
        
        /**
         * This method set the value of totalFats to a new given value.
         * 
         * @param totalFats the new value for totalFats.
        */
        void setTotalFat(const int& totalFat);
        
        /**
         * This method set the value of sugars to a new given value.
         * 
         * @param sugars the new value for sugars.
        */
        void setSugars(const int& sugars);
        
        /**
         * This method set the value of protiens to a new given value.
         * 
         * @param protiens the new value for protiens.
        */
        void setProtiens(const  int& protiens);
        
        /**
         * This method set the value of sodium to a new given value.
         * 
         * @param sodium the new value for sodium.
        */
        void setSodium(const int& sodium);

        /**
         * This method adds to Food objects together with the + operator.
         * 
         * @param rhs the Food object to be added.
         * @return the total of the two objects.
        */
        Food operator+(const Food& rhs) const;

    private:

        std::string name;
        int calories;
        int totalFat;
        int sugars;
        int protiens;
        int sodium;

        /**
         * This method will clamp a val to a given low value.
         * 
         * @param val the value to be clamped.
         * @param low the low value to clamp to.
         * 
         * @return the clamped value.
        */
        int floorClamp(const int& val, const int& low);

};

#endif