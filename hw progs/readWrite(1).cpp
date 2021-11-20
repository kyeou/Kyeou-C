//written by christian jarmon
//P8.4
//THIS CPP FILE CONTAINS BOTH PROBLEMS
#include <iostream>
#include <fstream>
using namespace std;
string floatingNumbersFile = "";

int main() {//open the file in write mode(ofstream), generate random floating point numbers for testing, open the file in read mode(ifstream), then log the averages in the console
    ofstream outfile;
    
cout << "name the file\n";
cin >> floatingNumbersFile;
outfile.open(floatingNumbersFile + ".txt"); 



for (int i = 1; i < 11; i++) {
    float r = static_cast<float> (rand())/static_cast <float> (RAND_MAX) + (rand() % 100);
    float r2 = static_cast<float> (rand())/static_cast <float> (RAND_MAX) + (rand() % 100);
   outfile << r << " " << r2 << "\n";
   
}
outfile.close();
float ave1, ave2;
ifstream readFile;
readFile.open(floatingNumbersFile + ".txt");
for (int i = 1; i < 11;i++) {
    readFile >> ave1 >> ave2;
    cout << "average is "<<(ave1 + ave2)/2 << "\n";
}
readFile.close();
cout<< "cpp compiled\n";
}


