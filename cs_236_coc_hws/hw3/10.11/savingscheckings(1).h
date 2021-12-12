//written by christian jarmon
//code beautified on https://codebeautify.org/cpp-formatter-beautifier
#include <iostream>

#include <fstream>

#include "account.h"

using namespace std;

class Savings: public Account {
  public: void daily_interest() {
    amount = (day % 30 == 0) ? (amount + (amount * .06)) : amount;
    if (day % 30 == 0) cout << " SAVINGS AMOUNT INCREASED BY: " << amount * .06 << "\n";
  }
}; // savings ends

class Checking: public Account {
  public: void daily_interest() {
    double check = (amount * .03);
    amount = (day % 30 == 0 && amount > 1000.00) ? (amount + (amount * .03)) : amount;
    if (day % 30 == 0 && amount > (1000.00 - check)) cout << "CHECKING AMOUNT INCREASED BY: " << amount * .03 << "\n";
  }
}; // checking ends