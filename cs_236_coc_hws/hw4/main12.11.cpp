//Write a program that sorts a vector of Employee objects by the employee names and prints the results. 
//Use the sort function from the C++ library.
#include <iostream>

#include <sstream>

#include <vector>

#include <algorithm>

#include "employee.h"
std::vector <std::string> names = {//this is just a set of names to test
"Pamelia Tramble",
"Tai Savard",
"Emmy Morter",
"Cathie Shell",
"Debi Reichard",
"Mikaela Vestal",
"Aimee Tsai",
"Ona Kimpel",
"Mackenzie Marini",
"Phebe Peart",
"Martina Braun",
"Marx Jeffrey",
"Robena Fugate",
"Genna Shadley",
"Maryjo Scheu",
"Janeth Michels",
"Tamatha Wallingford",
"Mitzi Kimbrell",
"Carter Favors",
"Catherina Landau"
};
bool compare(Employee a, Employee b) {
    return (a.getName() < b.getName());
}
int main() {
    //main for 12.11
    std::vector <Employee> emps;
    for (std::string n: names) {
       Employee temp(n);
        emps.push_back(temp);
    }
 
std::sort(emps.begin(), emps.end(), compare);
std::cout <<"sorted\n";
for (Employee e: emps) {
    std::cout << e.getName() << "\n";
}
}





