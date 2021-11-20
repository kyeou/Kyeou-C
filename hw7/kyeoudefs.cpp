#define forL(x) for(int i = 0; i < x; i++)
#define printS(s) std::cout << s << std::endl;
#define randK(x) 1 + (rand() % x);
#define ifS(a, b) if (a) b;
#include <iostream>

int main() {
    int x = 2;
    ifS(x == 2, x = 3; int a = 3);
    printS(x);
}
