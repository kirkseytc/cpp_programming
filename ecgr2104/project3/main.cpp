#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

#define EARTH_RADIUS 3958.8 // in miles
#define AIRPLANE_SPEED 515.0 // in mph

using namespace std;

const vector<string> LOCATION_NAMES = {
    "Miami, FL, USA", 
    "Dallas, TX, USA", 
    "New York City, NY, USA",
    "Charlotte, NC, USA",
    "Washington D.C., USA",
    "Pheonix, AZ, USA",
    "Los Vegas, NV, USA",
    "San Francisco, CA, USA",
    "Atlanta, GA, USA",
    "Portland, OR, USA"
};
const vector<double> LOCATION_LATS = {
    25.7751,
    32.7767,
    40.7128,
    35.2238,
    38.8921,
    33.5722,
    36.2292,
    37.7009,
    33.7629,
    45.5370
};
const vector<double> LOCATION_LONGS = {
    -80.1947,
    -96.7970,
    -74.0060,
    -80.8411,
    -77.0199,
    -112.0901,
    -115.2601,
    -122.4650,
    -84.4227,
    -122.6500
};
const double PI = 3.1415926536;

double haversine(double, double, double, double, double);
double getFlightTime(double, double, double, double);
double degreeToRadians(double);

/**
 * the main method
 * 
 * @return error code
 * 
*/
int main(){

    cout << "Welcome to the Flight Time Calculator!" << endl;
    cout << endl;

    do {

        string input;

        cout << "Here is our list of locations to pick from:" << endl;

        for(int i = 0; i < LOCATION_NAMES.size(); i++){

            cout << "\t" << (i + 1) << ". " << LOCATION_NAMES.at(i) << "  " << LOCATION_LATS.at(i) << "  " << LOCATION_LONGS.at(i) << endl; 

        }

        cout << endl << "Please enter the number associated with your departure location: ";
        cin >> input;

        int place1 = atoi(input.c_str());
        
        // error handling
        if(place1 <= 0 || place1 > 10){
            cout << "Invalid Input. Try Again." << endl << endl;
            continue;
        }

        place1--; // offseting for arrays.

        cout << endl;

        int offset = 0;
        
        for(int i = 0; i < LOCATION_NAMES.size(); i++){

            if(i == place1){
                offset--;
                continue;
            }

            cout << "\t" << (i + 1 + offset) << ". " << LOCATION_NAMES.at(i) << "  " << LOCATION_LATS.at(i) << "  " << LOCATION_LONGS.at(i) << endl;

        }

        cout << endl << "Please enter the number associated with your arrival location: ";
        cin >> input; 

        int place2 = atoi(input.c_str());

        if(place2 <= 0 || place2 > 9){
            cout << "Invalid Input. Try Again." << endl << endl;
            continue;
        }

        place2--; // offsetting for array

        // fixing list offset
        if(place2 >= place1){
            place2++;
        }

        cout << endl;

        double flightTime = getFlightTime(LOCATION_LATS.at(place1), LOCATION_LONGS.at(place1), LOCATION_LATS.at(place2), LOCATION_LONGS.at(place2));
        
        cout << "Your flight time from \"" << LOCATION_NAMES.at(place1) << "\" to \"" << LOCATION_NAMES.at(place2) << "\" is " << flightTime << " hour(s)." << endl;

        cout << endl;

        cout << "Would you like to get another flight time? ([Y]/N): ";
        cin >> input;

        if(input.at(0) == 'N' || input.at(0) == 'n'){
            break;
        }

        cout << endl;

    } while(true);
    
    cout << endl;
    cout << "Thanks for using the Flight Time Calculator!" << endl;

    return 0;
}

/**
 * calculates the distance between two point with haversine formula.
 * 
 * @param lat1 the latatude of the first point.
 * @param long1 the longitude of the first point.
 * @param lat2 the latatude of the second point.
 * @param long2 the longitude of the second point.
 * @param radius the radius of the sphere.
 * 
 * @return the distance between the two point.
*/
double haversine(double lat1, double long1, double lat2, double long2, double radius){

    /*
        Formula: https://en.wikipedia.org/wiki/Haversine_formula
    */

    lat1 = degreeToRadians(lat1);
    long1 = degreeToRadians(long1);
    lat2 = degreeToRadians(lat2);
    long2 = degreeToRadians(long2);

    return 2.0 * radius * asin(sqrt((sin((lat2 - lat1)/2.0) * sin((lat2 - lat1)/2.0)) + cos(lat1) * cos(lat2) * (sin((long2 -  long1) / 2.0) * sin((long2 -  long1) / 2.0))));

}

/**
 * gets the flight time between two locations.
 * 
 * @param lat1 the latatude of the first point.
 * @param long1 the longitude of the first point.
 * @param lat2 the latatude of the second point.
 * @param long2 the longitude of the second point.
 * 
 * @return the flight time in hours.
 * 
*/
double getFlightTime(double lat1, double long1, double lat2, double long2){

    return haversine(lat1, long1, lat2, long2, EARTH_RADIUS) / AIRPLANE_SPEED;

}

/**
 * converts degrees to radians
 * 
 * @param degrees the degrees to be converted.
 * 
 * @return the degrees in radians.
 * 
*/
double degreeToRadians(double degrees){
    return (degrees * PI) / 180.0;
}
