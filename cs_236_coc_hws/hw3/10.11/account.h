//written by christian jarmon
//code beautified on https://codebeautify.org/cpp-formatter-beautifier
/*

Implement a base class Account and derived classes Savings and Checking. In the base
class, supply member functions deposit and withdraw. Provide a function daily_
interest that computes and adds the daily interest. For calculations, assume that
every month has 30 days. Checking accounts yield interest of 3 percent annu ally on
balances over $1,000. Savings accounts yield interest of 6 percent annually on the
entire balance. Write a test program that makes a month’s worth of depos its and
withdrawals and calculates the interest every day

*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Account {
public:

Account() {
amount = 0;
day = 1;
}
void deposit (double namount) {
    amount += namount;
    day++; 
}
void withdraw (double oamount) {
    amount -= oamount;
   // day++; 
}
double getAmount() {
    return amount;
}
int getDay() {
    return day;
}
string getAllInfo() {
    ostringstream os;
     
     os <<  "Current Amount: " << amount<< "\n";
return os.str();
}
void daily_interest();
protected:
double amount;
int day;
};