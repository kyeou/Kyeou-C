/*
Write functions
set<int> set_union(set<int> a, set<int> b) set<int> intersection(set<int> a, set<int> b)
that compute the set union and intersection of the sets a and b. (Don’t name the first function union—that is a reserved word in C++.)
*/
//written by christian jarmon

#define forL(x) for (int i = 0; i < x; i++)
#define printS(s) std::cout << s << std::endl;

#include <iostream>
#include <ctime>
#include <set>
std::set<int> a, b;

std::set<int> set_union(std::set<int> a, std::set<int> b)
{
    std::set<int> q;
    std::set<int>::iterator itr;
    for (itr = a.begin(); itr != a.end(); ++itr)
    {
        q.insert(*itr);
    } //for ends
    for (itr = b.begin(); itr != b.end(); ++itr)
    {
        q.insert(*itr);
    } //for ends
    return q;
} //function ends

std::set<int> intersection(std::set<int> a, std::set<int> b)
{
    std::set<int> q;
    std::set<int>::iterator itr, itr2;
    for (itr = a.begin(); itr != a.end(); ++itr)
    {
        for (itr2 = b.begin(); itr2 != b.end(); ++itr2)
        {
            if ((*itr) == (*itr2))
            {
                q.insert(*itr2);
            }
        } //end of small loop
    }     //end of big for loop
    return q;
}

int main()
{
    srand((unsigned int)time(NULL));
    forL(40)
    {
        a.insert(1 + (rand() % 30));
        b.insert(1 + (rand() % 30));
    }
    std::set<int>::iterator itr;
    printS("2 sets");
    for (itr = a.begin(); itr != a.end(); ++itr)
    {
        std::cout << *itr << " ";
    }
    printS("");
    for (itr = b.begin(); itr != b.end(); ++itr)
    {
        std::cout << *itr << " ";
    }
    printS("");
    std::set<int> c = set_union(a, b);
    printS("union set");
    for (itr = c.begin(); itr != c.end(); ++itr)
    {
        std::cout << *itr << " ";
    }
    printS("");
    printS("intersection");
    std::set<int> d = intersection(a, b);
    for (itr = d.begin(); itr != d.end(); ++itr)
    {
        std::cout << *itr << " ";
    }
    printS("");
}
