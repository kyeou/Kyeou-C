/*
Simulate the processing of customers at a bank with five tellers. Customers arrive on average once per minute, and they need an average of five minutes to complete a transaction. 
Customers enter a queue to wait for the next available teller.
Use two kinds of events. An arrival event adds the customer to the next free teller or the queue and schedules the next arrival event. 
When adding a customer to a free teller, also schedule a departure event. 
The departure event removes the customer from the teller and makes the teller service the next customer in the waiting queue, again scheduling a departure event.
For greater realism, use an exponential distribution for the time between arrivals and the transaction time. 
If m is the desired mean time and r a uniformly distributed random number between 0 and 1, then –m log(r) has an exponential distribution.
After each event, your program should print the bank layout, showing empty and occupied tellers and the waiting queue, like this:
C.CC.
if there is no queue, or
CCCCC CCCCCCCCCCCCCCCCC
if there is one. Simulate customer arrivals for 8 hours. 
At the end of the simulation, print the total number of customers served and the average time each customer spent in the bank. 
(Your Customer objects will need to track their arrival time.)
*/
#include "../kyeoudefs.h"
#include <time.h>
#include <chrono>
#include <thread>
#include <vector>
#include <map>
#include <fstream>
#include <cctype>
using namespace std::chrono;
using namespace std::chrono_literals;
  std::ofstream dC;
//5 tellers -->> Customers arrive 1/min -->> 5 min for trans comp -->> they wait in queue -->> 2 events ||-> Arrival and Event
//Arrival adds customer to next free teller or queue and schedules next
//Departure event removes cutomer from teller -->> teller calls for next customer

//Customer 1 arrives -> create departure 1 , schedule arrival for customer 2 -> to next free teller #?, and customer 1 leaves - > 2 arrives -> loop
//Class Customer has a arrival and departure pieces of data
//There is a 1 queue
//Class Teller has 2 states -> Busy and Free
//Total time for each run - > 8 hours = 480 minutes = 28800 seconds

class Customer {
public:

Customer() {
Arrival();

}
void Arrival() {

}
void Departure() {
   
}
private:
int duration;
};







class Teller {
    public:
    Teller(int id) {
this->id = id;
    }
    void statUpdate(std::string str) {
        status = str;
    } 


private:
int id;
std::string status;
};








class Bank{
public:
Bank() {
    
    std::vector <Teller*> tellers;
    forL(5) {
    tellers.push_back(new Teller(i+1));
    }
}
private:
int duration;
};
void findTeller(int i) {
    if (i == 1) {
return;
    } else {
    forL (i - 1) {
    dC << "        ";
    dC << "\t\t\t";
        }//end for
    }//ends else




}//ends function
int main() {
    srand((unsigned int)time(NULL));
  
    auto start = std::chrono::system_clock::now();
       auto ongoing = start;
       auto diff = std::chrono::duration_cast <std::chrono::seconds>( ongoing - start).count();
    auto tI = std::chrono::system_clock::to_time_t(start - 24h);
    dC.open("Data Collected.txt");
    dC << "Start Time -->> " << tI << std::endl;
    forL (5) {
        dC << "Teller#" << i+1 << "\t\t\t"; 
    }
    while (diff != 28800 ) {//this functions as long time passed does not equal 480 minutes
   auto diff = std::chrono::duration_cast <std::chrono::seconds>( ongoing - start).count();
   ongoing += 60s;
}//while ends

}//main ends
//for the file 
//in the beginning of execution, write teller 1, teller 2, etc
//after something is written to the file, make sure to do new line
//a teller has customers, so that class controlls the text file, each customer has a number, have get set functions for time for customers and write those to a file
//NOTE; instead of using chrono, use random amounts of seconds instead, use system clock for the runs but not code function
