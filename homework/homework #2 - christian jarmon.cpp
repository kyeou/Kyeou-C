//all code written by Christian Jarmon
//9.3 -------------------------------------------
#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include <vector>
using namespace std;
 /**
 A simulated cash register that tracks the item count and
 the total amount due.
 */
class CashRegister
{
public:
    /**
    Constructs a cash register with cleared item count and total.
    */
   // CashRegister();

    /**
    Clears the item count and the total.
    */
    void clear() {
        record.clear();
    }
    /**
    Adds an item to this cash register.
    @param price the price of this item
    */
    void add_item(double price) {
        record.push_back(price);
        total += price;
    }

    /**
    @return the total amount of the current sale
    */
    double get_total() const {
        return total;
    }
    void display_all() {
        int count = 1;
        for (double a : record) {
            cout << "Item #" << count << ": " << record[a] << "\n";
            count++;
        }
    }
    /**
    @return the item count of the current sale
    */
    int get_count() const {
        return record.size();
    }

private:
    vector <double> record;
    double total = 0.0;
};

#endif#


//9/13 ------------------------------------------------
//Country.h -------------------
//written by Christian Jarmon

#include <iostream>
#include <sstream>
using namespace std;
class Country {

public:
    Country() {

    
        area = 0;
        population = 0;
        popDensity = 0;
    }
        Country(string nname, double narea, int npopulation) {
        name = nname;
       area = narea;
        population = npopulation;
        popDensity = npopulation / narea;
    }

    double getArea() const {
        return area;
    }
    double getPopDensity() const {
        return popDensity;
    }
    int getPopulation() {
        return population;
    }
    string toString() {
        ostringstream os;
        os << "\nThis country's info \n Name: " << name << "\n Population: " << population << "\n Area: " << area << "\n Population Density: " << popDensity << "\n";
        return os.str();
    }
    static Country inputCountry() {
        double a;
        int p;
        string n;
        cout << "enter a country name\n";
        cin >> n;
        cout << "enter a its population\n";
        cin >> p;
        cout << "enter its area\n";
        cin >> a;
        cout << "\n";
        
        return  Country(n, a, p);

    }


private:
    double area, popDensity;
    int population;
    string name = "";
};//class ends

//Country.cpp ---------------------
//written by Christian Jarmon

#include <iostream>
#include "Country.h"
#include <vector>
using namespace std;
int main() {

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