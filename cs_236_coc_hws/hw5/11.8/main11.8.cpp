/*
Using recursion, find the largest element in a vector of integer values:
int maximum(vector<int> values)
Hint: Find the largest element in the subset containing all but the last element. Then compare that maximum to the value of the last element.
*/
//written by christian jarmon
#include <iostream>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <algorithm>
using namespace std;
vector <int> values;
int maximum(vector <int> vec, int m)
{
return (m == 1) ? vec[0] : max(vec[m-1], maximum(vec, m-1));
} //findInsertion ends

int main() {
    //main for 11.8
 unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < (10 + (rand() % 50)); i++) {values.push_back(1 + (rand() % 9999900));}
    cout << "{ ";
    for (int i: values) {cout << i << " ";}
    cout << "}\n";
    cout << "maximum is " << maximum(values, values.size()) << "\n";
    sort(values.begin(), values.end());
    //this check uses the sort algorithm which will put the biggest value at the end of the vector
    cout << "check. maximum is indeed " << values.back() << "\n";
    //if the above cout prints out the same value, the algorithm works
}