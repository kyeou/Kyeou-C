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
vector<Appointment *> book;
int removed = 0;
int added = 0;

bool checkTimeConflict(Appointment *a, Appointment *b)
{ //returns true if there is a time confliction
    if (a->getDate().compare(b->getDate()) != 0)
        return false;
    if (a->getDate().compare(b->getDate()) == 0 && ((a->getHour() >= b->getHour() && a->getHour() <= b->getEndHour()) || (a->getEndHour() >= b->getHour() && a->getEndHour() <= b->getEndHour())))
        return true;
    if (a->getDate().compare(b->getDate()) == 0 && ((b->getHour() >= a->getHour() && b->getHour() <= a->getEndHour()) || (b->getEndHour() >= a->getHour() && b->getEndHour() <= a->getEndHour())))
        return true;
    return false;
}

bool compareLess(Appointment *a, Appointment *b) //this function checks if a happens before(<) b, these functions only compare dates
{                                                //return true if a < b
    if ((a->getYear() < b->getYear()) ^
            (a->getMonth() < b->getMonth() && a->getYear() == b->getYear()) ^
            (a->getDay() < b->getDay()) &&
        a->getMonth() == b->getMonth() && a->getYear() == b->getYear())
        return true;

    return false;
}

bool compareMore(Appointment *a, Appointment *b) //this function checks if a happens after(>) b, these functions only compare dates
{                                                //return true if a < b
    if ((a->getYear() > b->getYear()) ^
        (a->getMonth() > b->getMonth() && a->getYear() == b->getYear()) ^
        (a->getDay() > b->getDay() && a->getMonth() == b->getMonth() && a->getYear() == b->getYear()))
        return true;

    return false;
}

int compare(Appointment *c, Appointment *d)
{

    if (compareLess(c, d) == true)
        return 1;
    if (compareMore(c, d) == true)
        return 2;

    if (checkTimeConflict(c, d) == false)
    {
        if (c->getHour() < d->getHour())
            return 1;
        else
            return 2;
            //return (c->getHour() < d->getHour()) ? 1 : 2;
    }
    return 0;
}

void printApps()
{
   // cout << "printing " << book.size() << " appointments\n";
    sort(book.begin(), book.end(), compareMore);
    int io = 1;
    //if getdes == random appointment do the ostringstream stuff
    for (auto it = book.end() - 1; it != book.begin(); --it)
    {
        if ((*it)->getDes().compare("random appointment") == 0)
        {
            ostringstream os;
            os << "random appointment #" << io;
            (*it)->setDes(os.str());
        } //if ends
        cout << (*it)->toString();
        io++;
    }
   if ((*book.begin())->getDes().compare("random appointment") == 0)
        {
    ostringstream os;
    os << "random appointment #" << io;
    (*book.begin())->setDes(os.str());       }
    cout << (*book.begin())->toString();
        
} //print ends

bool checkValidity(Appointment *c) //this function calls compare which then calls checkTimeConflict
{
    if (book.size() == 0 || book.size() == 1)
        return true;

    for (int i = 0; i < book.size() - 2; i++)
    {
        if (checkTimeConflict(c, book[i]) == true)
        {
            return false;
        } //if ends

    } //for ends
    return true;
} //check ends

int findInsertion(Appointment *c, int l, int h)//the binary search
{

    int m = (int)(l + h) / 2;

   // cout << book.size() - removed << "->>" << m << " " << l << " " << h << "\t";
    if (l == h || m + 1 == book.size() - removed)
        return (book.size() - removed);

    if ((compare(c, book[m]) == 2) && (compare(c, book[m + 1]) == 1))
        return m + 1;
    if ((compare(c, book[m]) == 2))
        findInsertion(c, m + 1, h);
    if ((compare(c, book[m]) == 1))
        findInsertion(c, l, m - 1);

    return 0;//this function should never reach this return
} //findInsertion ends

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
        book.insert(book.begin() + findInsertion(temp, 0, book.size() - 1 - removed), temp);
        added++;
    } //for ends
    sort(book.begin(), book.end(), compareMore);
    //printApps();
} //add appointment ends

int main()
{

    unsigned seed = time(0);
    srand(seed);

    for (int a = 0; a < 20; a++)
    {

        book.push_back(new Appointment(1 + (rand() % (5 - 1 + 1)), 1 + (rand() % (20 - 1 + 1)), 2000 + (rand() % (2012- 2000 + 1)), "random appointment"));

        if (checkValidity(book.back()) == false)
        {
            book.erase(book.end());
            cout << "Appointment #" << a + 1 << " removed(confliction)\n";
            removed++;
        }

    } //for ends

    char q;
    while (q != 'E' || q != 'e')
    {
        cout << "what do you want to do --->>> A)dd appointment __ P)rint Appointments? __ or E)xit?\n";
        cin >> q;
        switch (q)
        {
        case 'A':
        case 'a':
            addAppointment();
           // cout << "appointment added\n";
            break;

        case 'P':
        case 'p':
            printApps();
          //  cout << "appointments printed\n";
            break;

        case 'E':
        case 'e':
            cout << "Goodbye!\n";
            exit(0);
            break;

        default:
            cout << "invalid character entered, goodbye!\n";
            exit(0);
            break;
        }
    }
    printApps();
    addAppointment();

} //main ends
