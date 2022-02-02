/*
Reimplement the Polynomial class of Exercise P13.14 by using a map<int, double> to store the coefficients.
*/
#define forL(x) for (int i = 0; i < x; i++)
#define printS(s) std::cout << s << std::endl;

// written by christian jarmon
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <map>
// make a pair
// create the term with a char, and the pair
class Term
{
public:
    Term(int coeff, int expo)
    {
        t.first = coeff;
        t.second = expo;

    } // term con ends

    int getC()
    {
        return t.first;
    }
    int getE()
    {
        return t.second;
    }
    std::pair<int, int> getTerm()
    {
        return t;
    }

private:
    std::pair<int, int> t;

}; // term ends

class Polynomial
{
public:
    Polynomial(Term *t)
    {
        poly.insert(std::pair<char, Term *>('a', t));
    }
    char findEnd()
    {
        return (char)counter;
    } // findEnd ends

    void add(Term *t)
    {
        poly.insert(std::pair<char, Term *>(findEnd(), t));
        counter++;
    } // add ends

    std::map<char, Term *> getMap()
    {
        return poly;
    } // getMap ends

    void toString()
    {
        std::ostringstream os;
        std::map<char, Term *>::iterator print;
        for (print = poly.begin(); print != poly.end(); ++print)
        {
            os << (*print).second->getTerm().first << "" << (*print).first << "^" << (*print).second->getTerm().second << " + ";
        } // for ends
        std::string send = os.str();
        printS(send.substr(0, (send.length() - 2)));
    } // tostring ends

    static void multiply(Polynomial *p, Polynomial *q)
    {
        std::map<char, Term *>::iterator polint;
        std::map<char, Term *>::iterator polint2;
        Polynomial *a = new Polynomial(new Term((*(p->poly.begin())).second->getTerm().first * (*(q->poly.begin())).second->getTerm().first, (*(p->poly.begin())).second->getTerm().second + (*(q->poly.begin())).second->getTerm().second));
        for (polint = p->poly.begin(); polint != p->poly.end(); ++polint)
        {
            for (polint2 = q->poly.begin(); polint2 != q->poly.end(); ++polint2)
            {
                if ((*polint).first == (*polint2).first)
                {
                    a->add(new Term(((*polint).second->getTerm().first * (*polint2).second->getTerm().first), ((*polint).second->getTerm().second + (*polint2).second->getTerm().second)));

                } // if ends
            }     // nested for ends
        }         // big for ends
        a->poly.erase(a->poly.begin());
        printS("\nmultiplied poly")
            a->toString();
    } // multiply ends

private:
    int counter = 98;
    std::map<char, Term *> poly;
}; // poly ends

int main()
{
    srand((unsigned int)time(NULL));
    Polynomial *z = new Polynomial(new Term(1 + (rand() % 10), 1 + (rand() % 10)));
    forL(3)
    {
        z->add((new Term(1 + (rand() % 10), 1 + (rand() % 10))));
    }
    z->toString();

    Polynomial *y = new Polynomial(new Term(1 + (rand() % 10), 1 + (rand() % 10)));
    forL(3)
    {
        y->add((new Term(1 + (rand() % 10), 1 + (rand() % 10))));
    }
    y->toString();
    Polynomial::multiply(z, y);
}
