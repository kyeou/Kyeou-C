//Write a program that keeps an appointment book.
//Make a class Appointment that stores a description of the appointment, the appointment day, the starting time, and the ending time.
//Your program should keep the appointments in a sorted vector. Users can add appointments and print out all appointments for a given day.
//When a new appointment is added, use binary search to find where it should be inserted in the vector.
//Do not add it if it conflicts with another appointment.

//written by christian jarmon
#include <iostream>
#include <stdio.h>
#include <sstream>

#include <vector>
#include <algorithm>
#include "appointment.h"
using namespace std;
vector<Appointment *> book;

/*

for the binary search part, check the 2 dates closer to the middle, and then do the rest of basic binary search, return location



*/

bool compare(Appointment *a, Appointment *b)
{ //if the attributes are equal, they dont flip, the only changes that happen are when one of the conditions are true, leaving opportunity for error
  /* if (a->getYear() < b->getYear())
    return true;
  if (a->getMonth() < b->getMonth() && a->getYear() == b->getYear())
    return true;
  if (a->getDay() < b->getDay() && a->getMonth() == b->getMonth())
    return true;
  if (a->getHour() < b->getHour() && a->getDay() == b->getDay())
    return true;
  if (a->getMinute() < b->getMinute() && a->getHour() == b->getHour())
    return true;

  return false; */

  if (a->getYear() > b->getYear() || a->getMonth() > b->getMonth() || a->getDay() > b->getDay() || ( a->getHour() > b->getHour() && a->getMinute() > b->getMinute()))
  {
    return false;

    return true;
  }
}
bool checkValidity(Appointment *c)
{ //the attributes of c and d must not match, and for time, the time for c must not be between d. should return false if the appointment is invalid, true otherwise
  for (Appointment *d : book)
  { //if month and day and year and hour-minutes is not in-between/match d, return true
    if ((c->getHour() > d->getHour() && c->getEndHour() < d->getEndHour()))
    {
      return false;
    } //if ends

  } //for ends
  return true;
} //check ends
int findLocation(vector<Appointment *> vec, Appointment *tempapp)
{
  

  for (int i = 0; i < book.size() - 1; i++)
  {
    //if (a->getHour() == book.back()->getHour() && a->getMinute() == book.back()->getMinute()) break;
    if (compare(vec[i], tempapp) == true && (compare(vec[i + 1], tempapp) == false ^ vec[i + 1] == NULL))
    {
      for (int x = vec.size(); x > i + 1; x--)
      {
        vec[x] = vec[x] - 1;
      } //shift for ends
      return i;
      break;
    } //if ends
  }   //for ends
  return 0;
} //findLocation ends
void addAppointment()
{
  cout << "How many appointments do you want to add\n";
  int aq;
  cin >> aq;
  for (int i = 0; i < aq; i++)
  {
    cout << "Enter a date MM/DD/YYYY with spaces in between(no zeros in MM or DD)\n";
    int am, ad, ay;
    cin >> am >> ad >> ay;
    int hour, minute;
    cout << "at what time? enter hour, then space, minute.\n";
    cin >> hour >> minute;
    string des = "";
    cout << "what is this appointment for?\n";
    cin >> des;
    Appointment *temp = new Appointment(am, ad, ay, hour, minute, des);
    if (checkValidity(temp) == true)
    {
      book[findLocation(book, temp)] = temp;
      cout << "appointment added\n";
    }
    else
    {
      cout << "appointment invalid, please try again\n";
      i -= 1;
    } //else ends
  }   //for ends
} //add appointment ends

int main()
{
  //main for 12.12
  for (int a = 0; a < 20; a++)
  {
    ostringstream os;
    os << "This is appointment #" << a + 1 << "\t";
    Appointment *temp = new Appointment(1 + (rand() % (2 - 1 + 1)), 1 + (rand() % (10 - 1 + 1)), 2000 + (rand() % (2003 - 2000 + 1)), os.str());
    if (checkValidity(temp) == true)
      // book[findLocation(book, temp)] = temp; // if i do this it crashes
      book.push_back(temp);
    else
      cout << "Appointment #" << a << " removed(confliction)\n";
    //sort(book.begin(), book.end(), compare);
    //cout << book.back()->toString();
    //  sort(book.begin(), book.end(), compare);

  } //for ends
  //cout << "\n\nsorting the random appointments\n\n";

  sort(book.begin(), book.end(), compare);
  for (Appointment* a: book) {
book[findLocation(book, a)] = a;
  }
    for (Appointment *a : book)
    {
      cout << a->toString();
    }
  //cout << "do you want to add appointments? y/n\n";
  //char q;
  //cin >> q;
  // if (q = 'y') addAppointment();
  //cout << book.size();
  for (auto a : book)
  {
    delete a;
  }
  book.clear();
  //cout << book.size();
} //main ends
//c->getMonth() == d->getMonth() && c->getDay() == d->getDay() && c->getYear() == d->getYear() &&
