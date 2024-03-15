#include <iostream>
#include <vector>

using namespace std;

double calcAvg(vector<double> calcVector);
double calcMin(vector<double> calcVector);
double calcMax(vector<double> calcVector);

// main method
int main(){

    vector<double> bass;
    vector<double> catfish;
    vector<double> carp;

    char userInput = '-';

    cout << "====================" << endl;
    cout << "=== REGISTRATION ===" << endl;
    cout << "====================" << endl;

    // loop will keep running until it breaks.
    while(true){

        cout << "What fish do you want to register? (b = Bass, c = Catfish, k = Carp, s = Stop): ";
        cin >> userInput;

        // converts userInput to lowercase in case of capitalization
        userInput = tolower(userInput);

        // exits regestration
        if(userInput == 's'){
            cout << endl;
            break;
        }

        // checks if a vaild input was made.
        if(!(userInput == 'b' || userInput == 'c' || userInput == 'k')){
            cout << "Invaild Input. Try Again." << endl << endl;

            string temp;
            getline(cin, temp);

            continue;
        }

        // After a valid input is made, an input for weight is taken.

        double weight;

        cout << "What was the weight (in kgs): ";
        cin >> weight;

        // adds the weight to the correct vector
        switch(userInput){
            case 'b':
                bass.push_back(weight);
                break;
            case 'c':
                catfish.push_back(weight);
                break;
            case 'k':
                carp.push_back(weight);
                break;
        }

        cout << endl;

    }

    cout << "=================" << endl;
    cout << "=== ANALYTICS ===" << endl;
    cout << "=================" << endl;

    // checks if any bass were regestered and outputs accordingly
    if(bass.empty()){
        cout << "No basses were recorded." << endl << endl;
    } else {
        double bassAvg, bassMin, bassMax;
        
        bassAvg = calcAvg(bass);
        bassMin = calcMin(bass);
        bassMax = calcMax(bass);

        cout << "Basses: " << endl;
        cout << "\tThe heaviest Bass was " << bassMax << " kgs." << endl;
        cout << "\tThe lightest Bass was " << bassMin << " kgs." << endl;
        cout << "\tThe average Bass was " << bassAvg << " kgs." << endl;
        cout << endl;
    }

    // checks if any catfish were regestered and outputs accordingly
    if(catfish.empty()){
        cout << "No catfish were recorded." << endl << endl;
    } else {
        double catfishAvg, catfishMin, catfishMax;

        catfishAvg = calcAvg(catfish);
        catfishMin = calcMin(catfish);
        catfishMax = calcMax(catfish);

        cout << "Catfish:" << endl;
        cout << "\tThe heaviest Catfish was " << catfishMax << " kgs." << endl;
        cout << "\tThe lightest Catfish was " << catfishMin << " kgs." << endl;
        cout << "\tThe average Catfish was " << catfishAvg << " kgs." << endl;
        cout << endl;
    }
    
    // checks if any carp were regestered and outputs accordingly
    if(carp.empty()){
        cout << "No carps were recorded." << endl << endl;
    } else {
        double carpAvg, carpMin, carpMax;

        carpAvg = calcAvg(carp);
        carpMin = calcMin(carp);
        carpMax = calcMax(carp);

        cout << "Carps: " << endl;
        cout << "\tThe heaviest Carp was " << carpMax << " kgs." << endl;
        cout << "\tThe lightest Carp was " << carpMin << " kgs." << endl;
        cout << "\tThe average Carp was " << carpAvg << " kgs." << endl;
        cout << endl;
    }
    
    cout << "===================================" << endl;
    cout << "=== Tristan Kirksey - ECGR 2103 ===" << endl;
    cout << "===================================" << endl;

    return 0;
}

// calculates the average double of a vector of doubles and returns it.
double calcAvg(vector<double> calcVector){

    double avg = 0.0;
    
    for(int i = 0; i < calcVector.size(); i++){
        avg += calcVector[i];
    }

    avg /= calcVector.size();

    return avg;

}

// finds the smallest double in a vector of doubles and returns it.
double calcMin(vector<double> calcVector){

    double min = calcVector[0];

    for(int i = 0; i < calcVector.size(); i++){
        if(calcVector[i] < min){
            min = calcVector[i];
        }
    }

    return min;

}

// finds the largest double in a vector of doubles and returns it.
double calcMax(vector<double> calcVector){

    double max = calcVector[0];

    for(int i = 0; i < calcVector.size(); i++){
        if(calcVector[i] > max){
            max = calcVector[i];
        }
    }

    return max;

}
