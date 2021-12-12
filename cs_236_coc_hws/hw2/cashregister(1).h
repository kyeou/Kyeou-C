//all code written by Christian Jarmon
//9.3 -------------------------------------------
#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include <vector>
using namespace std;
 /**
 A simulated cash register that tracks the item count and
 the total amount due.
 */
class CashRegister
{
public:
    /**
    Constructs a cash register with cleared item count and total.
    */
   // CashRegister();

    /**
    Clears the item count and the total.
    */
    void clear() {
        record.clear();
    }
    /**
    Adds an item to this cash register.
    @param price the price of this item
    */
    void add_item(double price) {
        record.push_back(price);
        total += price;
    }

    /**
    @return the total amount of the current sale
    */
    double get_total() const {
        return total;
    }
    void display_all() {
        int count = 1;
        for (double a : record) {
            cout << "Item #" << count << ": " << record[a] << "\n";
            count++;
        }
    }
    /**
    @return the item count of the current sale
    */
    int get_count() const {
        return record.size();
    }

private:
    vector <double> record;
    double total = 0.0;
};

#endif#