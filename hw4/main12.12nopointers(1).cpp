//Write a program that keeps an appointment book.
//Make a class Appointment that stores a description of the appointment, the appointment day, the starting time, and the ending time.
//Your program should keep the appointments in a sorted vector. Users can add appointments and print out all appointments for a given day.
//When a new appointment is added, use binary search to find where it should be inserted in the vector.
//Do not add it if it conflicts with another appointment.

//written by christian jarmon
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <ctime>
#include "appointment.h"
using namespace std;
vector<Appointment> book;
//if both compare functions return false, the dates are the same 
//have a overall compare function, use the checkTimeConflict to check if the dates have conflicting times, if true, the date is to not be added to the book
/*just keep these on hand
(a.getHour() < b.getHour() && a.getDay() == b.getDay()) ^
    (a.getMinute() < b.getMinute() && a.getHour() == b.getHour())








*/
bool checkTimeConflict(Appointment a, Appointment b) {//returns true if there is a time confliction
if (a.getDate().compare(b.getDate()) !=0 ) return false;
if (a.getDate().compare(b.getDate()) == 0 &&     (      (a.getHour() >= b.getHour() && a.getHour() <= b.getEndHour())      || (a.getEndHour() >= b.getHour() &&    a.getEndHour() <= b.getEndHour())                 )    ) return true;
if (a.getDate().compare(b.getDate()) == 0 &&     (      (b.getHour() >= a.getHour() && b.getHour() <= a.getEndHour())      || (b.getEndHour() >= a.getHour() &&    b.getEndHour() <= a.getEndHour())                 )    ) return true;
return false;
}
bool compareLess(Appointment a, Appointment b) //this function checks if a happens before(<) b, these functions only compare dates
{ //return true if a < b
    if (a.getYear() < b.getYear() ^  
    (a.getMonth() < b.getMonth() && a.getYear() == b.getYear()) ^ 
    (a.getDay() < b.getDay()) && a.getMonth() == b.getMonth() && a.getYear() == b.getYear()) 
        return true;

    return false;
}
bool compareMore(Appointment a, Appointment b)//this function checks if a happens after(>) b, these functions only compare dates
{ //return true if a < b
    if (a.getYear() > b.getYear() ^  
    (a.getMonth() > b.getMonth() && a.getYear() == b.getYear()) ^ 
    (a.getDay() > b.getDay() && a.getMonth() == b.getMonth() &&  a.getYear() == b.getYear())
    )
        return true;

    return false;
}
//          c               book[0]
int compare(Appointment c, Appointment d) {
//if compareLess == true, return 1
//if compareMore == true, return 2
//only one of those can be true at a time
//if both are false return 0
if (compareLess(c, d) == true) return 1;
if (compareMore(c, d) == true) return 2;
//if both are false, check if the times here are less or more and not in the othe compare functions, because the times can only conflict if the days are the same
//this should only be called if the compare functions above are both false
if (checkTimeConflict(c ,d)  == false) {//if c start hour < d start hour, return 1, else return 2
//checking whether they conflict or not should be left to the checkconflict function
    if (c.getHour() < d.getHour()) return 1;
    else return 2;
}
return 0;
} 
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
        
    } //for ends
}

bool checkValidity(Appointment c)//this function calls compare which then calls checkTimeConflict
{ 
    if (book.size() == 0) {
        book.push_back(c);
        }//size check ends
if (book.size() == 1) {
   switch (int i = compare(c, book[0])) {
case 1:  book.insert(book.begin(), c); break;
//case 1: cout << "new was less then old "<< compare(c, book[0]) << "\n"; book.insert(book.begin(), c); break;
case 2:  book.push_back(c); break;
// cout << "new was more then old "<< compare(c, book[0]) << "\n"; book.push_back(c); break;
   }//switch ends

    
}//size check 2 ends





    for (Appointment d : book)
    { 
        if ( checkTimeConflict(c,d) == true    )
        {
            return false;
        } //if ends

    } //for ends
    return true;
} //check ends

void insertApp(Appointment c) {
int cc = 0;
for (Appointment a: book) {
if ( (compare(c , a) == 2) && (compare(c,book[cc+1]) == 1) ){
    book.insert(book.begin() + (cc+1), c);
}//if ends
cc++;
}//for ends
}//insertApp ends


int findInsertion(Appointment c, int l, int h) {//this is the binary search algorithm that return the index of where the appointment should be inserted, YOU CANT USE THIS TO SORT
    //this function is to only be called if the amount of appointments is > 1
    
  if (h == 1) {
      for (int i = 0; i < 2; i++) {
          if (compare(c,book[i]) == 1) return i;
          if (compare(c, book[i]) == 2) return i+1;
      }
  } 
while (l <= h) {
    int m = (l + h)/2;
//there is no point in checking if it present at mid considering the odds of one of these appointments being the same
//instead use the compare function to check if the book[m],c is true and c,book[m+1] false
//THESE HAVE TO FIXED
    if (  (compare(c , book[m]) == 2) && (compare(c,book[m+1]) == 1)   ) return m+1;
   if ((compare(c , book[m]) == 2)) l = m + 1;
   if ((compare(c , book[m]) == 1)) h = m - 1;
   
   
   // l = (compare(c , book[m]) == 2) ? m+1 : l;
   // h = (compare(c , book[m]) == 1) ? m-1: h;
/*
if (  (compare(book[m],c) == true) && (compare(c,book[m+1]) == false)   ) return m+1;
l = (compare(book[m], c) == true) ? m+1 : l;
h = (compare(book[m], c) == false) ? m-1: h;
*/
}//while ends
return 0;
}//findInsertion ends





//create a function that the take a new appointment (that has not been pushed back), and the appoointment before that and call a new version of the checkValidity function





int main()
{

    unsigned seed = time(0);
    srand(seed);

    for (int a = 0; a < 20; a++)
    {
        
        ostringstream os;
        os << "This is appointment #" << a + 1 << "\t";
       
       Appointment temp(1 + (rand() % (2 - 1 + 1)), 1 + (rand() % (10 - 1 + 1)), 2000 + (rand() % (2003 - 2000 + 1)), os.str());
      


if (book.size() == 0 || book.size() == 1) checkValidity(temp);

//the next if should only happen if the book has more than 1 appointment
if (checkValidity(temp))  //insertApp(temp);
book.insert(book.begin()+findInsertion(temp, 0, book.size() -1), temp);
else cout << "Appointment #" << a + 1 << " removed(confliction)\n"; 
  
         
    } //for ends

    for (Appointment a : book)
    {
        cout << a.toString();
    }

  
}