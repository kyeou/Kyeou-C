
#include <stdint.h>
#include <inttypes.h>
#define int_input(msg, var) \
    printf(msg);            \
    scanf("%ld", &var)

long int number = 0;

int main()
{

    int_input("pick a number, any number: ", number);
    printf("start -> %ld\n", number);
    for (;;)
    {
        if (number % 2 == 0)
            number /= 2;
        else
            number = (3 * number) - 1;
        printf("start -> %ld\n", number);
    }
}