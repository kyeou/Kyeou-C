#define forL(x) for(int i = 0; i < x; i++)
#define printS(s) std::cout << s << std::endl;
#define randK(x) 1 + (rand() % x);
#define ifS(a, b) if (a) b;
#define ifES(a, b, c, d) if (a) {b} else (c) {d} ;
#include <iostream>

int main()
{
    forL(100)
    {//program takes two sequential numbers (i-1 and i ) and prints the distance of their squares
        printS(i << " " << i - 1 << " -->> " << (i * i) - ((i - 1) * (i - 1)));
    }
}