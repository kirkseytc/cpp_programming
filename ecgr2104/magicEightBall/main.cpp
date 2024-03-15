#include <iostream>

using namespace std;

int main(){

    cout << "Magic Eight Ball" << endl;

    string input = "placeholder";

    while(true){

        cout << endl;
        cout << "Ask a yes or no question or type \'q\' to quit: ";
        getline(cin, input);

        if(input.length() == 1 && (input.at(0) == 'q' || input.at(0) == 'Q')){
            break;
        }

        int randNum = input.length() % 6;

        switch(randNum){
            case 0:
                cout << "Probably Not." << endl;
                break;
            case 1:
                cout << "Probably." << endl;
                break;
            case 2:
                cout << "A Straight 50/50." << endl;
                break;
            case 3:
                cout << "Definite No." << endl;
                break;
            case 4:
                cout << "Definite Yes." << endl;
                break;
            default:
                cout << "Maybe." << endl;
        }

    }

    return 0;
}