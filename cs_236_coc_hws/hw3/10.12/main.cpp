//this main is for 10.12
//written by christian jarmon
//code beautified on https://codebeautify.org/cpp-formatter-beautifier
#include <iostream>

#include <sstream>

#include "appointmentTypes.h"

#include <vector>


vector < Appointment * > apps;
/*
void createRandomApps() {//if-else version
  int i;
  for (int a = 0; a < 20; a++) {
    i = (1 + (rand() % 4));
    ostringstream os;
    os << "This is appointment #" << a + 1 << "\t";
    if (i == 1) {
      os << " Type: OneTime\t";
      apps.push_back(new Onetime(1 + (rand() % (2 - 1 + 1)), 1 + (rand() % (10 - 1 + 1)), 2000 + (rand() % (2001 - 2000 + 1)), os.str()));
    } else if (i == 2) { //Daily tempapp(1 + (rand() % (12  - 1 + 1)), 1 + (rand() % (30  - 1 + 1)), 2000 + (rand() % (2040  - 2000 + 1)), os.str()); 
      os << " Type: Daily\t";
      apps.push_back(new Daily(1 + (rand() % (2 - 1 + 1)), 1 + (rand() % (10 - 1 + 1)), 2000 + (rand() % (2001 - 2000 + 1)), os.str()));
      apps.back() -> occurs_on(apps.back() -> getMonth(), apps.back() -> getDay(), apps.back() -> getYear());
      // cout << "daily created" << "\n";
    } else if (i == 3) {
      os << " Type: Weekly\t";
      apps.push_back(new Weekly(1 + (rand() % (2 - 1 + 1)), 1 + (rand() % (10 - 1 + 1)), 2000 + (rand() % (2001 - 2000 + 1)), os.str()));
      apps.back() -> occurs_on(apps.back() -> getMonth(), apps.back() -> getDay(), apps.back() -> getYear());
      // cout << "weekly created" << "\n";
    } else if (i == 4) {
      os << " Type: Monthly\t";
      apps.push_back(new Monthly(1 + (rand() % (2 - 1 + 1)), 1 + (rand() % (10 - 1 + 1)), 2000 + (rand() % (2001 - 2000 + 1)), os.str()));
      apps.back() -> occurs_on(apps.back() -> getMonth(), apps.back() -> getDay(), apps.back() -> getYear());
      //cout << "monthly created" << "\n";
    }//if-else ends
  } //for ends

} //end of createRandom
*/

void createRandomApps() {//switch version
  int i;
  for (int a = 0; a < 20; a++) {
    i = (1 + (rand() % 4));
    ostringstream os;
    os << "This is appointment #" << a + 1 << "\t";
    switch (i) {
   case 1:  
      os << " Type: OneTime\t";
      apps.push_back(new Onetime(1 + (rand() % (2 - 1 + 1)), 1 + (rand() % (10 - 1 + 1)), 2000 + (rand() % (2001 - 2000 + 1)), os.str()));
      break;
     case 2:  //Daily tempapp(1 + (rand() % (12  - 1 + 1)), 1 + (rand() % (30  - 1 + 1)), 2000 + (rand() % (2040  - 2000 + 1)), os.str()); 
      os << " Type: Daily\t";
      apps.push_back(new Daily(1 + (rand() % (2 - 1 + 1)), 1 + (rand() % (10 - 1 + 1)), 2000 + (rand() % (2001 - 2000 + 1)), os.str()));
      apps.back() -> occurs_on(apps.back() -> getMonth(), apps.back() -> getDay(), apps.back() -> getYear());
      // cout << "daily created" << "\n";
      break;
  case 3:
      os << " Type: Weekly\t";
      apps.push_back(new Weekly(1 + (rand() % (2 - 1 + 1)), 1 + (rand() % (10 - 1 + 1)), 2000 + (rand() % (2001 - 2000 + 1)), os.str()));
      apps.back() -> occurs_on(apps.back() -> getMonth(), apps.back() -> getDay(), apps.back() -> getYear());
      // cout << "weekly created" << "\n";
      break;
   case 4: 
      os << " Type: Monthly\t";
      apps.push_back(new Monthly(1 + (rand() % (2 - 1 + 1)), 1 + (rand() % (10 - 1 + 1)), 2000 + (rand() % (2001 - 2000 + 1)), os.str()));
      apps.back() -> occurs_on(apps.back() -> getMonth(), apps.back() -> getDay(), apps.back() -> getYear());
      //cout << "monthly created" << "\n";
      break;
    }//switch ends
  } //for ends

} //end of createRandom
int main() {
  createRandomApps();
  for (Appointment * a: apps) {
    cout << a -> toString() << "\n";

  }

  int um, ud, uy;
  cout << "Enter a date, start a with the month, then day, then year, with a space in between each.\n";
  cin >> um >> ud >> uy;
  cout << "Appointments on this day -->> " << um << "/" << ud << "/" << uy << "\n\n";
  for (Appointment * a: apps) {
    if (a -> getMonth() == um && a -> getDay() == ud && a -> getYear() == uy) {
      cout << a -> getDes().substr(8, 16) << " at " << a -> getTime() << "\n";
    } //if ends
  } //for ends

  for (Appointment * a: apps) {

    delete a;
    a = NULL;
  }
  apps.clear();
} //main ends

//figure out how to create random appointments and return them to main()