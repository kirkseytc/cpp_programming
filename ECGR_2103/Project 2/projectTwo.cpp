#include <iostream>
#define SPACE_AVAIL 5000 // in sqft.
#define PERSONAL_SPACE 5 // in sqft.

using namespace std;

unsigned int calcTickets(unsigned int totalSpace, unsigned int spaceUsed, unsigned int personalSpace);

int main(){

	unsigned int boothSpace;

	cout << "Ticket Calculator\n" << endl;
	cout << "Total Available Area (in square feet): " << SPACE_AVAIL << endl;
	cout << "Personal Space (in square feet): " << PERSONAL_SPACE << endl;
	cout << "Total Space Booths/Attractions Take Up (in square feet): ";
	cin >> boothSpace;
	cout << "----------------" << endl;

	unsigned int tickets = calcTickets(SPACE_AVAIL, boothSpace, PERSONAL_SPACE); 

	cout << "Maxium Tickets That You Could Sell: " << tickets << endl;
	cout << "----------------" << endl;
	cout << "Tristan Kirksey - 801286738" << endl;

	return 0;
}

unsigned int calcTickets(unsigned int totalSpace, unsigned int spaceUsed, unsigned int personalSpace){

	unsigned int maxTickets = totalSpace - spaceUsed;

	maxTickets /= personalSpace;

	return maxTickets;
}
