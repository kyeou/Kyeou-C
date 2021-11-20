//written by christian jarmon
//code beautified on https://codebeautify.org/cpp-formatter-beautifier
#include <iostream>

#include <sstream>

#include "appointment.h"

#include <vector>

//----------------------------------------------------------------------------------------------------
class Onetime: public Appointment {
  public: Onetime(): Appointment() {}
  Onetime(int month, int day, int year, string des): Appointment(month, day, year, des) {
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
  } //end of con
  void occurs_on(int month, int day, int year) override {
    cout << "This is a onetime appointment" << "\n";
  }
  string toString() override {

    ostringstream os;
    os << description << "Date: " << date << " at -->> " << time << "\n";

    return os.str();
  } //tostring ends
  string getDes() {
    return description;
  }
  string getTime() {
    return time;
  }

  private: int year,
  day,
  month,
  hour = 1 + (rand() % (24)),
  minute = 1 + (rand() % (59));
  string date = "";
  string description = "";
  string time = "";
  //vector <Onetime> nextApps;

}; //one time ends
//---------------------------------------------------------------------------------------------------------
class Daily: public Appointment {
  public: Daily(): Appointment() {}
  Daily(int month, int day, int year, string des): Appointment(month, day, year, des) {
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
  } //end of con
  string getDes() {
    return description;
  }
  string getTime() {
    return time;
  }
  void occurs_on(int m, int d, int y) override {
    int tempd = d + 1;
    for (int i = 0; i < 10; i++) {
      Daily temp(m, tempd, y, "this is a daily appointment");
      tempd++;
      nextApps.push_back(temp);
      if (d + i == 30) {
        for (int a = 0; a < 10 - i; a++) {
          Daily temp(m + 1, a + 1, y, "this is a daily appointment");
          nextApps.push_back(temp);
        } //for ends
        break;
      } //if ends

    } //for ends

  } //occurs_on ends
  string toString() override {
    ostringstream os;
    os << description << "Date: " << date << " at -->> " << time << "\n  ---------   Next Appointments: ";
    for (Daily d: nextApps) {
      os << d.getMonth() << "/" << d.getDay() << "/" << d.getYear() << " ";
    }
    os << "\n";
    return os.str();
  } //tostring ends
  /*int getDay() {return day;}
  int getMonth() {return month;}
  int getYear() {return year;}*/
  private: int year,
  day,
  month,
  hour = 1 + (rand() % (24)),
  minute = 1 + (rand() % (59));
  string date = "";
  string description = "";
  string time = "";
  vector < Daily > nextApps;
}; //Daily ends
//------------------------------------------------------------------------------------------------------------
class Weekly: public Appointment {
  public: Weekly(): Appointment() {}
  Weekly(int month, int day, int year, string des): Appointment(month, day, year, des) {
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
  } //con ends
  string getDes() {
    return description;
  }
  string getTime() {
    return time;
  }
  void occurs_on(int m, int d, int y) override {
    int tempd;
    if (d + 7 >= 30) {
      tempd = d - 30 + 7;
    } else {
      tempd = d + 7;
    }
    for (int i = 0; i < 3; i++) {
      Weekly temp(m, tempd, y, "this is a weekly appointment");
      tempd += 7;
      nextApps.push_back(temp);
      if (nextApps[nextApps.size() - 1].getDay() + 7 > 30) {
        //if the a date from the next month is to be added, add 7 days to the day of the app at the end of the vector
        int nm = m + 1;
        for (int b = 0; b > 3 - i; b++) {
          Weekly temp(nm, nextApps[nextApps.size() - 1].getDay() - 30 + 7, y, "this is a weekly appointment");
          nextApps.push_back(temp);
        }
        break;
      } //if ends
    } //for ends

  } //occurs_on ends

  string toString() override {
    ostringstream os;
    os << description << "Date: " << date << " at -->> " << time << "\n  ---------   Next Appointments: ";
    for (Weekly d: nextApps) {
      os << d.getMonth() << "/" << d.getDay() << "/" << d.getYear() << " ";
    }
    os << "\n";
    return os.str();
  } //tostring ends
  /*int getDay() {return day;}
  int getMonth() {return month;}
  int getYear() {return year;}*/
  private: int year,
  day,
  month,
  hour = 1 + (rand() % (24)),
  minute = 1 + (rand() % (59));
  string date = "";
  string description = "";
  string time = "";
  vector < Weekly > nextApps;
};

//--------------------------------------------------------------------------------------------------------------------------

class Monthly: public Appointment {
  public: Monthly(): Appointment() {}
  Monthly(int month, int day, int year, string des): Appointment(month, day, year, des) {
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
  } //com ends

  string getDes() {
    return description;
  }
  string getTime() {
    return time;
  }
  void occurs_on(int m, int d, int y) override { //same day every month
    int tempm;
    int ny;
    if (m == 12) {
      tempm = 1;
      ny = y + 1;
    } else {
      tempm = m + 1;
      ny = y;
    }
    for (int i = 0; i < 5; i++) {
      Monthly temp(tempm, d, ny, "this is a monthly appointment");
      tempm++;
      nextApps.push_back(temp);
      if (tempm >= 12) {
        ny++;
        tempm = 1;
        for (int a = 0; a < 5 - i; a++) {
          Monthly temp(tempm, d, ny, "this is a monthly appointment");
        } //for ends
        break;
      } //if ends
    }
  }
  string toString() override {
    ostringstream os;
    os << description << "Date: " << date << " at -->> " << time << "\n  ---------   Next Appointments: ";
    for (Monthly d: nextApps) {
      os << d.getMonth() << "/" << d.getDay() << "/" << d.getYear() << " ";
    }
    os << "\n";
    return os.str();
  } //tostring ends
  /*int getDay() {return day;}
  int getMonth() {return month;}
  int getYear() {return year;}*/
  private: int year,
  day,
  month,
  hour = 1 + (rand() % (24)),
  minute = 1 + (rand() % (59));
  string date = "";
  string description = "";
  string time = "";
  vector < Monthly > nextApps;
};
/*
int main() {
     vector <Appointment> apps;
     for (int i = 0; i < 12; i++) {
         apps[i] = Appointment(1 + (rand() % (12  - 1 + 1)), 1 + (rand() % (30  - 1 + 1)), 2000 + (rand() % (2040  - 2000 + 1))); 
         ostringstream os; os << "This is appointment ->> " << i + 1; 
         apps[i].setDes(os.str());
        apps[i].toString();
     }
}

*/