//homework #3 main file for 10.11
//written by christian jarmon
//code beautified on https://codebeautify.org/cpp-formatter-beautifier
#include <iostream>

#include <vector>

#include "savingscheckings.h"

using namespace std;

//dont mind me professor, just having some fun. create a vector of deposit and withdraw activities everyday. make them strings. ask user if they want to print them. 
int main() {
  Savings AccountSavings;
  Checking AccountChecking;
  vector < string > activites;
  for (int i = 1; i < 31; i++) {
    cout << "Day " << i << "\n";
    double dep = (double) rand() + rand();
    AccountSavings.deposit(dep);
    ostringstream os;
    os << "$" << dep << " deposited in savings account on day " << i;
    activites.push_back(os.str());
    os.str("");

    double wit = (1 + (rand() % (int) AccountSavings.getAmount() - 2));
    AccountSavings.withdraw(wit);
    os << "$" << wit << " withdrawn from savings account on day " << i;
    activites.push_back(os.str());
    os.str("");
    AccountSavings.daily_interest();

    double dep2 = (double) rand();
    AccountChecking.deposit(dep2);
    os << "$" << dep2 << " deposited in checking account on day " << i;
    activites.push_back(os.str());
    os.str("");

    double wit2 = (1 + (rand() % (int) AccountChecking.getAmount() - 2));
    AccountChecking.withdraw(wit2);
    os << "$" << wit2 << " withdrawn from checking account on day " << i;
    activites.push_back(os.str());
    os.str("");
    AccountChecking.daily_interest();

    cout << "Savings: " << AccountSavings.getAllInfo();
    cout << "Checkings: " << AccountChecking.getAllInfo() << "\n";

  } //for ends
  cout << "Do you want to see the deposits and withdrawls from the past 30 days? y/n?\n";
  char c;
  cin >> c;
  if (c == 'y') {
    cout << "Activites: \n";
    int sep = 1;
    for (string s: activites) {
      cout << s << "\n";
      if (sep % 4 == 0) {
        cout << "\n";
      }
      sep++;
    } //for each ends
  } //if choice ends
  else if (c == 'n') {
    cout << "activites not printed";
  } else if (c != 'y' && c != 'n') {
    cout << "invalid choice made, activites not printed\n";
  }
} //main ends