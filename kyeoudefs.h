#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// C++

#define forL(x) for (int i = 0; i < x; i++)
#define forL(x, a)              \
    for (int i = 0; i < x; i++) \
    {                           \
        a;                      \
    }
#define printS(s) std::cout << s << std::endl
#define printWE(s) std::cout << s;
#define randK(x)                     \
    srand((unsigned int)time(NULL)); \
    1 + (rand() % x);
#define randR(x, y) x + (rand() % y - x + 1)
#define ifS(a, b) \
    if (a)        \
    b
#define ifES(a, b, c, d) \
    if (a)               \
    {                    \
        b                \
    }                    \
    else if (c)          \
    {                    \
        d                \
    }
#define DELETE_AND_NULL(x) \
    if (x != nullptr)      \
    {                      \
        delete x;          \
        x = nullptr;       \
    }

// C

#define for (amount) for (int b = 0; b < amount; b++)
#define for_each_cond(x, y, amount)  \
    for (int b = 0; b < amount; b++) \
    {                                \
        if (x)                       \
        {                            \
            y;                       \
        }                            \
    }
#define int_input(msg, var) \
    int var;                \
    printf(msg);            \
    scanf("%d", &var)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
