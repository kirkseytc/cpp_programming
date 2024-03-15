#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    // seeding the rand() method
    srand(time(NULL));

    // generating the number to be guessed
    int numToGuess = rand() % 10 + 1;
    
    for(int guesses = 3; guesses > 0; guesses--){

        int userNum; // variable to store user's guess

        // taking in the user's guess
        cout << "You have " << guesses << " remaining." << endl;
        cout << "Guess an integer between 1-10: ";
        cin >> userNum;

        // Handling Invaild Range
        if(userNum > 10 || userNum < 1){ 
            cout << "Invaild Range. Try Again." << endl << endl;
            guesses++;
            continue;
        }

        // User Wins
        if(userNum == numToGuess){
            cout << "You Win! You Guessed Correctly!" << endl;
            return 0;
        }

        // User Loses
        if(guesses == 1){
            continue;
        }

        // User Guessed Too High
        if(userNum > numToGuess){
            cout << "Incorrect Guess! Guess Lower!" << endl << endl;
            continue;
        }

        // User Guessed Too Low
        if(userNum < numToGuess){
            cout << "Incorrect Guess! Guess Higher!" << endl << endl;
            continue;
        }

    }

    cout << "You Lose. How Sad." << endl;

    return 0;
}