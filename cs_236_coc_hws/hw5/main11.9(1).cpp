//Using recursion, compute the sum of all values in an array.
//written by christian jarmon
#include <iostream>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <algorithm>
using namespace std;
vector <int> values;
int check = 0;
int sum(vector <int> vec, int m)
{ 
    return (!(m > 0))  ? 0:  sum(vec,  m-1) + vec[m-1];  
} //findInsertion ends

int main() {
    //main for 11.8
 unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < (10 + (rand() % 50)); i++) {values.push_back(1 + (rand() % 9999900));}
    cout << "{ ";
    for (int i: values) {cout << i << " ";}
    cout << "}\n";
    cout << "sum is " << sum(values, values.size()) << "\n";
   for (int i: values) {check += i;}
    //this check is a for each loop that does the addition manually
    cout << "check. sum is indeed " << check << "\n";
    //if the above cout prints out the same value, the algorithm works
}