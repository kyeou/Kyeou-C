
//Write a program that counts how often each word occurs in a text file. Use a multiset<string>.
#define forL(x) for (int i = 0; i < x; i++)
#define printS(s) std::cout << s << std::endl;

#include <iostream>
#include <set>

std::multiset<std::string> s1;
std::string randomwords[15] = {"the", "be", "of", "and", "a", "to", "in", "he", "have", "it", "that", "for", "they", "I", "with"};
std::string previous = "";
int findOccur(std::string str)
{
    int c = 0;
    std::multiset<std::string>::iterator itr;
    for (itr = s1.begin(); itr != s1.end(); ++itr)
    {
        if ((*itr).compare(str) == 0)
        {
            c++;
        } //if ends
    }     //for ends
    return (c);
} //findOccur ends

int main()
{
    std::multiset<std::string>::iterator itr;
    forL(45)
    {
        s1.insert(randomwords[1 + (rand() % 15)]);
    }
    for (itr = s1.begin(); itr != s1.end(); ++itr)
    {
        std::cout << *itr << " ";
    }
    printS("");

    for (itr = s1.begin(); itr != s1.end(); ++itr)
    {
        if ((*itr).compare(previous) != 0)
        {
            printS((*itr) << " occurs this many times -->> " << findOccur(*itr));
            previous = *itr;
        } //if ends
    }     //for ends
}