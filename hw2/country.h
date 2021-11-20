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