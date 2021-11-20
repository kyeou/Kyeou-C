#define forL(x) for(int i = 0; i < x; i++)
#define forL(x , a) for (int i = 0; i < x; i++) {a;}
#define printS(s) std::cout << s << std::endl
#define printWE(s) std::cout << s;
#define randK(a) 1 + (rand() % a)
#define randR(x , y) x + (rand() % y - x + 1)
#define ifS(a, b) if (a) b
#define ifES(a, b, c, d) if (a) {b} else if (c) {d}
#define DELETE_AND_NULL(x) if (x != nullptr) {\
                            delete x;\
                            x = nullptr;\
                            }
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 