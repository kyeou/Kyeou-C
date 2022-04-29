#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <sstream>
#include <fstream>
#include "json.hpp"
//#include <bits/stdc++.h>

using json = nlohmann::json;



int main() {
    json TEST;
    std::cout << TEST.size() << std::endl;
    TEST[0]["IDK"] = "FUCKSAKE";
     TEST[1]["IDK"] = "FUCKSAKE";

     std::cout << TEST.size() << std::endl;

}


































/*
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
            
            std::cout << (*it)["Name"] << '\n';
        }
            //int a = RECORD["A_O_T"] ;
            //a+=2;
            //RECORD["A_O_T"] = a; 

        i.close();
       // std::cout << A_O_T << std::endl;
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

    j[0] = {
        {"Name", "Monster Energy"},
        {"A_O_T", 1},
        {"Budgets", {}},
        {"Scores", {}},
        {"SumDebits", 1}

    };

printf("Size of Empty array TEST: %d\n", j[0]["Budgets"].size());
//int ti = j[0]["Budgets"].size();
j[0]["Budgets"][j[0]["Budgets"].size()] = 32;
printf("Size of Empty array TEST: %d\n", j[0]["Budgets"].size());


j[1] = {
        {"Name", "Steven Smith"},
        {"A_O_T", 2},
        {"Budgets", {2}},
        {"Scores", {2}},
        {"SumDebits", 2}

    };

    fileWrite << std::setw(4) << j << std::endl;

    return 0;
}*/

// https://www.geeksforgeeks.org/c-program-to-create-a-file/
// https://www.tutorialspoint.com/json/json_objects.htm
// https://dev.to/zigabrencic/json-in-c-3mie
// https://github.com/nlohmann/json