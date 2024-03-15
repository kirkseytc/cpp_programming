#include "food.h"

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){

    const Food CHOICES[] = {
        Food("An Apple", 95, 0, 19, 0, 0),
        Food("A Banana", 131, 0, 18, 2, 1),
        Food("A Big Mac", 563, 33, 9, 26, 1007),
        Food("A Bowl of Cherrios", 70, 2, 1, 2, 95),
        Food("A Bowl of Cinnamon Toast Crunch", 110, 3, 8, 2, 160),
        Food("A Serving of Cheez-Its", 150, 8, 0, 3, 230),
        Food("An Orange", 45, 0, 9, 1, 0),
        Food("A Serving of Oreos", 160, 7, 14, 1, 135),
        Food("A 20oz Bottle of Pepsi", 250, 0, 69, 0, 55),
        Food("An 8oz Glass of Water", 0, 0, 0, 0, 0)
    };
    const int CHOICES_SIZE = 10;
    const int CALORIES_AVG = 2000;
    const int TOTAL_FATS_AVG = 70;
    const int SUGAR_AVG = 30;
    const int PROTIEN_AVG = 50;
    const int SODIUM_AVG = 2300;

    cout << "Welcome to the Nutrition Tracker!" << endl;

    Food sum = Food("Sum");

    do {

        string input;

        cout << "Please Select an Item from the List to add to the tracker: " << endl;

        // printing the list
        for(int i = 0; i < CHOICES_SIZE; i++){
            cout << "\t" << (i + 1) << ". " << CHOICES[i].getName() << endl;
        }

        cout << "\t" << (CHOICES_SIZE + 1) << ". Finish" << endl;
        cout << "> ";

        // getting input
        getline(cin, input);
        cout << endl;

        // converting the input into an integer
        int index = atoi(input.c_str()); 

        // checking for valid input
        if(index <= 0 || index > (CHOICES_SIZE + 1)){
            cout << "Invalid Input. Try Again." << endl << endl;
            continue;
        }

        // breaking if finished is choosen
        if(index == (CHOICES_SIZE + 1)){
            break;
        }

        // offsetting the index to make it valid for the array.
        index--;

        // summing the total nutrients
        sum = sum + CHOICES[index];

    } while (true);
    
    // formating the output
    cout << "-----------------------------------------------" << endl << endl;

    if(sum.getName() == "Sum"){ // nothing was selected.

        cout << "No items were selected to be tracked." << endl;    
        cout << endl;
        cout << "Goodbye!" << endl;
    
    } else { // something was selected.
        
        cout << ">>> Nutrient Tracker Report <<<" << endl;
        cout << endl;
        cout << "\tTotal Calories Consumed: " << sum.getCalories() << " calories" << endl;
        cout << "\tTotal Fat Consumed: " << sum.getTotalFat() << " grams" << endl;
        cout << "\tTotal Sugar Consumed: " << sum.getSugars() << " grams" << endl;
        cout << "\tTotal Protien Consumed: " << sum.getProtiens() << " grams" << endl;
        cout << "\tTotal Sodium Consumed: " << sum.getSodium() << " milligrams" << endl;

        cout << endl;

        bool formatFlag = false;

        if(sum.getCalories() > CALORIES_AVG){
            cout << "You exceeded the daily recomendation for Calories (" << CALORIES_AVG << " calories)" << endl;
            formatFlag = true;
        }

        if(sum.getTotalFat() > TOTAL_FATS_AVG){
            cout << "You exceeded the daily recomendation for Total Fats (" << TOTAL_FATS_AVG << " grams)" << endl;
            formatFlag = true;
        }

        if(sum.getSugars() > SUGAR_AVG){
            cout << "You exceeded the daily recomendation for Sugars (" << SUGAR_AVG << " grams)" << endl;
            formatFlag = true;
        }

        if(sum.getProtiens() > PROTIEN_AVG){
            cout << "You exceeded the daily recomendation for Protiens (" << PROTIEN_AVG << " grams)" << endl;
            formatFlag = true;
        }

        if(sum.getSodium() > SODIUM_AVG){
            cout << "You exceeded the daily recomendation for Sodium (" << SODIUM_AVG << " milligrams)" << endl;
            formatFlag = true;
        }

        if(formatFlag){ // makes the output look pretty.
            cout << endl;
        }

        cout << "Goodbye!" << endl;

    }

    return 0;
}