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
json RECORD;
int A_O_T =0;

    void countTrans()
    {
        for (json::iterator it = RECORD.begin(); it != RECORD.end(); ++it)
        {
            A_O_T++;
        }
    }

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
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

std::ifstream file;
if (!(is_empty(file))) {
std::ifstream i("example.json");
i >> RECORD;
countTrans();
i.close();
std::cout << A_O_T << std::endl;
} else {
    printf("IS EMPTY\n");
}

std::fstream fileWrite;
fileWrite.open("example.json", std::ios_base::in | std::ios_base::out);




//printf("Check 1\n");

for (int i = 0; i < 4; i++) {
    std::ostringstream na;
na << "Test Name " << i;
    j[i][na.str()] = "Successful";
}

int printCount = 0;
for (json::iterator it = j.begin(); it != j.end(); ++it) {
    std::ostringstream qw;
  std::cout << (*it)["Test Name"] << '\n';
}

//printf("Check 2\n");

//file >> a;


//printf("Check 3\n");
int count = 4;



printf("Check 4\n");

fileWrite << std::setw(4) << j  << std::endl;

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