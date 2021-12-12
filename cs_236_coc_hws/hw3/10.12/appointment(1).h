//written by christian jarmon
////code beautified on https://codebeautify.org/cpp-formatter-beautifier
/*
Implement a base class Appointment and derived classes Onetime, Daily, Weekly, and
Monthly. An appointment has a description (for example, “see the dentist”) and a date
and time. Write a virtual function occurs_on(int year, int month, int day) that checks
whether the appointment occurs on that date. For example, for a monthly appointment,
you must check whether the day of the month matches. Then fill a vector of
Appointment* with a mixture of appointments. Have the user enter a date and print out
all appointments that happen on that date.
*/
#include <iostream>

#include <sstream>

using namespace std;

class Appointment {
  public:

    Appointment() {
      year = 2000;
      day = 1;
      month = 1;
      ostringstream os;
      os << month << "/" << day << "/" << year;
      date = os.str();
      description = "default app.";
      ostringstream timeS;
      if (minute < 10) {
        timeS << hour << ":0" << minute;
      } else {
        timeS << hour << ":" << minute;
      }
      time = timeS.str();
    }
  Appointment(int month, int day, int year, string des) {
    this -> month = month;
    this -> day = day;
    this -> year = year;
    ostringstream os;
    os << month << "/" << day << "/" << year;
    date = os.str();
    description = des;
    ostringstream timeS;
    if (minute < 10) {
      timeS << hour << ":0" << minute;
    } else {
      timeS << hour << ":" << minute;
    }
    time = timeS.str();
  }

  virtual void occurs_on(int month, int day, int year) {};

  void setDes(string str) {
    description = str;
  }
  string getDes() {
    return description;
  }
  string getTime() {
    return time;
  }

  virtual string toString() {
    cout << "non-overidden called" << "\n";
    ostringstream os;
    os << description << ": " << date << " at -->> " << time << "\n";

    return os.str();
  };
  int getDay() {
    return day;
  }
  int getMonth() {
    return month;
  }
  int getYear() {
    return year;
  }
  private:
    int year, day, month, hour = 1 + (rand() % (24)), minute = 1 + (rand() % (59));
  string date = "";
  string description = "";
  string time = "";

}; //appointment ends

//random num between a and b
//a + (rand() % (b  - a + 1))