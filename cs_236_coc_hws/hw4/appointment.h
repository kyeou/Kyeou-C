#include <iostream>

#include <sstream>

#include <vector>
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
      startTime = timeS.str();
    }
  Appointment(int month, int day, int year, string des) {
    this -> month = month;
    this -> day = day;
    this -> year = year;
    hour = 1 + (rand() % (24));
    minute = 1 + (rand() % (59));
    tempEnd =  hour + (1 + rand() % 3);
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
    startTime = timeS.str(); timeS.str("");
    
     if (minute < 10) {
      timeS << tempEnd << ":0" << minute;
    } else {
      timeS << tempEnd << ":" << minute;
    }//if else ends
    endTime = timeS.str();
  }

  Appointment(int month, int day, int year,int nhour,int nminute, string des) {
   int ntempEnd =  nhour + (1 + rand() % 3);
    this -> month = month;
    this -> day = day;
    this -> year = year;
    hour = nhour;
    minute = nminute;
    ostringstream os;
    os << month << "/" << day << "/" << year;
    date = os.str();
    description = des;
    ostringstream timeS;
    if (nminute < 10) {
      timeS << nhour << ":0" << nminute;
    } else {
      timeS << nhour << ":" << nminute;
    }
    startTime = timeS.str(); timeS.str("");
    
     if (nminute < 10) {
      timeS << ntempEnd << ":0" << minute;
    } else {
      timeS << ntempEnd << ":" << minute;
    }//if else ends
    endTime = timeS.str();
  }
//~Appointment();
  
  void setDes(string str) {
    description = str;
  }
  string getDes() {
    return description;
  }
  string getStartTime() {
    return startTime;
  }
  string getEndTime() {
    return endTime;
  }

 string toString() {
   // cout << "non-overidden called" << "\n";
    ostringstream os;
    os << description << ": "<< date << " from -->> " << startTime <<" to " << endTime <<"\n";

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
  int getHour() {
    return hour;
  }
  int getMinute() {
    return minute;
  }
  int getEndHour() {
    //stringstream end(endTime.substr(0,2))
    return tempEnd;
  }
  string getDate() {
    return date;
  }
  private:
    int year, day, month, hour, minute, tempEnd;
  string date = "";
  string description = "";
  string startTime = "";
  string endTime = "";
 

}; //appointment ends






//(A1.getMonthNum() < A2.getMonthNum() ^ (A1.getDay() < A2.getDay() && A1.getMonthNum() == A2.getMonthNum()) ^ (A1.getHour() < A2.getHour() && A1.getDay() == A2.getDay()) ^ (A1.getMinute() < A2.getMinute() && A1.getHour() == A2.getHour())