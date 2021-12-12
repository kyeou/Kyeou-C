//written by christian jarmon

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
class Term
{
public:
    Term(char v, int coeff, int expo)
    {
        this->coeff = coeff;
        this->expo = expo;
        this->v = v;
    } //term con ends
    void setTerm(int a, int b)
    {
        coeff = a;
        expo = b;
    } //set term ends
    int getC()
    {
        return coeff;
    }
    int getE()
    {
        return expo;
    }
    char getVar()
    {
        return v;
    }

private:
    int coeff, expo;
    char v;
}; //term ends

class Node
{
public:
    Term *data = new Term('x', 0, 0);
    Node *next = NULL;
}; //node ends

class Polynomial
{
public:
    Polynomial(Term *t)
    {
        head = new Node;
        head->data->setTerm(t->getC(), t->getE());
    }
    void add(Term *t)
    {
        findNextNull(head)->next = new Node();

        findZero(head)->data = t;
    }
    Node *findNextNull(Node *h)
    {
        return (h->next == NULL) ? h : findNextNull(h->next);
    }
    Node *findZero(Node *n)
    {
        return (n->data->getC() == 0) ? n : findZero(n->next);
    }
    std::string createEQ(Node *t)
    {
        os << t->data->getC() << t->data->getVar() << "^" << t->data->getE();
        if (t->next != NULL)
            os << " + ";
        return (t->next != NULL) ? createEQ(t->next) : os.str();
    }
    void toString()
    {
        std::cout << createEQ(head) << std::endl;
    }
    static void multiply(Polynomial *p, Polynomial *q)
    {
        Polynomial a(new Term('x', (p->head->data->getC() * q->head->data->getC()), (p->head->data->getE() + q->head->data->getE())));
        a.add(new Term('y', (p->head->next->data->getC() * q->head->next->data->getC()), (p->head->next->data->getE() + q->head->next->data->getE())));
        a.add(new Term('z', (p->head->next->next->data->getC() * q->head->next->next->data->getC()), (p->head->next->next->data->getE() + q->head->next->next->data->getE())));
        a.toString();
    } //multiply function ends
private:
    Node *head;
    std::ostringstream os;
}; //poly ends

int main()
{
    for (int i = 0; i < 5; i++) {
        std::cout << "------------" << std::endl;
    srand((unsigned int)time(NULL));
    Polynomial *p = new Polynomial(new Term('x', 1 + (rand() % 10), 1 + (rand() % 10)));
    p->add(new Term('y', 1 + (rand() % 10), 1 + (rand() % 10)));
    p->add(new Term('y', 1 + (rand() % 10), 1 + (rand() % 10)));

    p->toString();

    Polynomial *q = new Polynomial(new Term('x', 1 + (rand() % 10), 1 + (rand() % 10)));
    q->add(new Term('y', 1 + (rand() % 10), 1 + (rand() % 10)));
    q->add(new Term('z', 1 + (rand() % 10), 1 + (rand() % 10)));

    q->toString();

    std::cout << "\nmultiplied poly\n";
    Polynomial::multiply(p, q);
    std::cout << std::endl;
    }
    //1 + (rand() % 20 )
}

