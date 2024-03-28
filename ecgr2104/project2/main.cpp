#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * This method prints the symbol associate with the number.
 * 
 * @param num The number to be matched with a symbol.
*/
void printSymb(int num);

/**
 *  This method handles the spining of the slot machine in the program.
 * 
 * @param balance The amount of money the user has.
 * @return The new balance of the user
*/
int spin(int balance);

/**
 * This is the main method of the program.
*/
int main(){

    srand(time(NULL)); // seeds the random num generator.

    cout << "Slot Machine - Project 2" << endl;

    int balance = 10;
    string input = "exit";

    do {
        
        cout << endl;
        cout << "Your Current Balance: $" << balance << endl;
        cout << "Do you want to (s)pin or (e)xit?: ";
        cin >> input;

        switch(input.at(0)){ // determines the action of the user by using the first character of their input.
            case 'S': // spin
            case 's':
                balance = spin(balance);
                break;
            case 'E': // exit
            case 'e':
                // prints the normal exit
                cout << "Your Final Balance was: $" << balance << endl;
                cout << "Goodbye!" << endl;
                exit(0); // exits the program with a success code.
                break;
            default: // invaild inputs
                cout << "Invalid Input." << endl;
                break;
        }

    } while(balance > 0); // loop will exit is balance reaches 0 or lower.

    // print the ran out of money exit.
    cout << "You Ran Out of Money to Play!" << endl;
    cout << "Goodbye!" << endl; 

    return 0;
}

void printSymb(int num){
    switch(num){
        case 0:
            cout << "7";
            break;
        case 1:
            cout << "$";
            break;
        case 2:
            cout << "#";
            break;
        case 3:
            cout << "X";
            break;
    }
}

int spin(int balance){

    balance--; // deducts the balance to spin.

    cout << "[";

    int slotArr[3];

    for(int i = 0; i < 3; i++){ // "spins" the machine and prints symbols as well.
        slotArr[i] = rand() % 4;
        printSymb(slotArr[i]);
    }

    cout << "] ";

    if(slotArr[0] == slotArr[1] && slotArr[1] == slotArr[2]){ // checks if the user won.
        
        cout << "You Won $";
        
        switch(slotArr[0]){ // prints and adds amount won.
            case 0: // 7 -> $100
                cout << "100!" << endl;
                balance += 100;
                break;
            case 1: // $ -> $50
                cout << "50!" << endl;
                balance += 50;
                break;
            case 2: // # -> $25
                cout << "25!" << endl;
                balance += 25;
                break;
            case 3: // X -> $10
                cout << "10!" << endl;
                balance += 10;
                break;
        }
    } else { 
        cout << "You Lose!" << endl;
    }

    return balance;
}

// Tristan Kirksey - ECGR 2104 