#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <sstream>
#include <fstream>
#include "json.hpp"
//#include <bits/stdc++.h>

using json = nlohmann::json;

struct employees
{
    std::string firstName;
    std::string lastName;
    int StudentID;
    std::string Department;
};

std::fstream file;
json RECORD;
int A_O_T = 0;

void countTrans()
{
    for (json::iterator it = RECORD.begin(); it != RECORD.end(); ++it)
    {
        A_O_T++;
    }
}

bool is_empty(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}
int main()
{

    // create an empty structure (null)
    json j;
    int printCount;
    // j["Transactions 1"] = "Name 1";

    // j["Transaction 1"]["Name 1"] = "This is a test";

    std::ifstream file;
    file.open("example.json");
    if (!(is_empty(file)))
    {
        file.close();
        std::ifstream i("example.json");
        i.open("example.json");
        i >> RECORD;
        countTrans();
        printCount = 0;
        for (json::iterator it = RECORD.begin(); it != RECORD.end(); ++it)
        {
            std::ostringstream qw;
            qw << "Test Name " << printCount;
            std::cout << (*it)[qw.str()] << '\n';
            printCount++;
        }
        i.close();
        std::cout << A_O_T << std::endl;
    }
    else
    {
        printf("IS EMPTY\n");
    }

    std::fstream fileWrite;
    fileWrite.open("example.json", std::ios_base::out);

    // printf("Check 1\n");

    for (int i = 0; i < 4; i++)
    {
        std::ostringstream na;
        na << "Test Name " << i;
        j[i][na.str()] = "Successful";
    }

    printCount = 0;
    for (json::iterator it = RECORD.begin(); it != RECORD.end(); ++it)
    {
        std::ostringstream qw;
        qw << "Test Name " << printCount;
        std::cout << (*it)[qw.str()] << '\n';
        printCount++;
    }

    // printf("Check 2\n");

    // file >> a;

    // printf("Check 3\n");

    printf("Check 4\n");

    fileWrite << std::setw(4) << j << std::endl;

    fileWrite.close();

    fileWrite.open("example.json", std::ios_base::out);

    j = {
        {"Name", "FirstName LastName"},
        {"A_O_T", 0},
        {"Budgets", {0}},
        {"Scores", {0}},
        {"SumDebits", {0}}

    };

    fileWrite << std::setw(4) << j << std::endl;

    return 0;
}

// https://www.geeksforgeeks.org/c-program-to-create-a-file/
// https://www.tutorialspoint.com/json/json_objects.htm
// https://dev.to/zigabrencic/json-in-c-3mie
// https://github.com/nlohmann/json