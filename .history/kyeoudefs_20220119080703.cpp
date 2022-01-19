#define forL(x, y, z) for(int i = x; i < y; z)
#define printS(s) std::cout << s << std::endl
#define randK(x) srand((unsigned int)time(NULL)); 1 + (rand() % x);
#define ifS(a, b) if (a) b;
#define ifES(a, b, c, d) if (a) {b} else (c) {d} ;
#include <iostream>

int main() {
    int x = 2;
    ifS(x == 2, x = 3; int a = 3);
    printS(x);
}

//System.out.println(sdfiguasldfgia);


//std::cout << some shit here << std::endl;