#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <sstream>
#include <fstream>
#include "json.hpp"
//#include <bits/stdc++.h>

using json = nlohmann::json;

struct employees {
    std::string firstName;
    std::string lastName;
    int StudentID;
    std::string Department;
};

std::fstream file;
int A

    void countTrans()
    {
        A_O_T = 0;
        for (json::iterator it = g .begin(); it != transactionsJSON.end(); ++it)
        {
            A_O_T++;
        }
    }


int main()
{

    

/*  json jdEmployees =
    {
        {"firstName","Sean"},
        {"lastName","Brown"},
        {"StudentID",21453},
        {"Department","Computer Sc."}
    };
*/
    // Access the values
   
    /*
    std::string fName = jdEmployees[0].value("firstName", "oops");
    std::string lName = jdEmployees[0].value("lastName", "oops");
    int sID = jdEmployees[0].value("StudentID", 0);
    std::string dept = jdEmployees[0].value("Department", "oops");
   
     Print the values
    std::cout << "First Name: " << fName << std::endl;
    std::cout << "Last Name: " << lName << std::endl;
    std::cout << "Student ID: " << sID << std::endl;
    std::cout << "Department: " << dept << std::endl;
    */
             
std::fstream file;
/*
json as = json::array();
as.push_back(jdEmployees);
as.push_back(jdEmployees);
as.push_back(jdEmployees);
*/

// create an empty structure (null)
json j;

//j["Transactions 1"] = "Name 1";

//j["Transaction 1"]["Name 1"] = "This is a test";

file.open("example.json", std::ios_base::in | std::ios_base::out);

//printf("Check 1\n");

for (int i = 0; i < 4; i++) {
    std::ostringstream add;
    std::ostringstream na;
    add << "Transaction " << i;
na << "Test Name";
    j[i][na.str()] = "Successful";
}

for (json::iterator it = j.begin(); it != j.end(); ++it) {
  std::cout << (*it)["Test Name"] << '\n';
}

//printf("Check 2\n");

//file >> a;
std::ifstream i("example.json");
json a;
i >> a;

//printf("Check 3\n");
int count = 4;
for (json::iterator it = a.begin(); it != a.end(); ++it) {
  std::cout << (*it)["Test Name"] << '\n';
  j[count] = (*it);
  count++;
}



printf("Check 4\n");

file << std::setw(4) << j  << std::endl;

/*
// add a number that is stored as double (note the implicit conversion of j to an object)
j["TEST 1"]["pi"] = 3.141;

// add a Boolean that is stored as bool
j["TEST 1"]["happy"] = true;

// add a string that is stored as std::string
j["TEST 1"]["name"] = "Niels";

// add another null object by passing nullptr
j["TEST 1"]["nothing"] = nullptr;

// add an object inside the object
j["TEST 1"]["answer"]["everything"] = 42;

// add an array that is stored as std::vector (using an initializer list)
j["TEST 1"]["list"] = { 1, 0, 2 };

// add another object (using an initializer list of pairs)
j["TEST 1"]["object"] = { {"currency", "USD"}, {"value", 42.99} };



j["TEST 2"]["pi"] = 3.141;

// add a Boolean that is stored as bool
j["TEST 2"]["happy"] = true;

// add a string that is stored as std::string
j["TEST 2"]["name"] = "Niels";

// add another null object by passing nullptr
j["TEST 2"]["nothing"] = nullptr;

// add an object inside the object
j["TEST 2"]["answer"]["everything"] = 42;

// add an array that is stored as std::vector (using an initializer list)
j["TEST 2"]["list"] = { 1, 0, 2 };

// add another object (using an initializer list of pairs)
j["TEST 2"]["object"] = { {"currency", "USD"}, {"value", 42.99} };

std::cout << j["TEST 2"]["list"] << "\n";
*/


std::ostringstream sq;
//sq << "TEST 2";
//std::cout << j[sq.str()]["list"] << "\n";








//json::parse("example.json");


file.close();

    return 0;
}


//https://www.geeksforgeeks.org/c-program-to-create-a-file/
//https://www.tutorialspoint.com/json/json_objects.htm
//https://dev.to/zigabrencic/json-in-c-3mie
//https://github.com/nlohmann/json