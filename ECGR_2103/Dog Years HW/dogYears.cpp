#include <iostream>

using namespace std;

int main(){

	int humanYears;
	cout << "Please enter your age: ";
	cin >> humanYears; 

	float dogYears;

	if(humanYears > 2){ // handles cases above 2 

		dogYears += 21 + ((humanYears - 2) * 4);
		
	} else if(humanYears > 0){ // handels cases 1-2 

		dogYears = humanYears * 10.5f;	

	} else { // handles negatives and zero cases
	
		dogYears = 0;

	}

	cout << "Your age in dog years is: " << dogYears << endl;
	
	return 0;
}
