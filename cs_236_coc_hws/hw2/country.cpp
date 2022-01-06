//Country.cpp ---------------------
//written by Christian Jarmon

#include <iostream>
#include "Country.h"
#include <vector>
using namespace std;
int country() {

    /*
    //Using that class, write a program that reads in a set of countries and prints
• The country with the largest area.
• The country with the largest population.
• The country with the largest population density (people per square
kilometer or mile).
*/
    vector <Country> countries;
    cout << "how many countries do you want to add?\n";
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) { cout << "Country #" << i + 1 << "\n"; countries.push_back(Country::inputCountry()); }
 
    Country largestArea("nod", 1, 1), largestPop("nod", 1, 1), largestPopDen("nod", 1, 1);
    for (Country c : countries) {
        largestArea = (c.getArea() > largestArea.getArea()) ? c : largestArea;
        largestPop = (c.getPopulation() > largestPop.getPopulation()) ? c : largestPop;
        largestPopDen = (c.getPopDensity() > largestPopDen.getPopDensity()) ? c : largestPopDen;
    }
    
        cout << "\nThis country has the largest Area: \n" << largestArea.toString();
        cout << "\nThis country has the largest Population: \n" << largestPop.toString();
        cout << "\nThis country has the largest Population Density: \n" << largestPopDen.toString();
    
   exit(256);

}