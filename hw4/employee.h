
#include <iostream>

#include <sstream>

#include <vector>

#include <algorithm>

class Employee{
public: 
Employee(std::string name) {
this -> name = name;
}
std::string getName() {
    return name;
}

private: 
std::string name = "";

};//class ends