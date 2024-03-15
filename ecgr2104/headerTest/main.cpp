#include "test.h"
#include <iostream>

using namespace std;

int main(){
    double radius = 9.0;
    double area = circleArea(radius);

    cout << "radius: " << radius << " area: " << area << endl;

    return 0;
}