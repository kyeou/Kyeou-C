
#include "stdlib.h"
#include "stdio.h"
#define lli long long int
#define int_input(msg, var) \
    printf(msg);            \
    scanf("%lld", &var)

lli number = 4;
lli n2;

int main()
{

    // int_input("pick a number, any number: ", number);
   for (lli i = 0; i < 9223372036854775807/2; i++) {
       n2 = number;
       while (number != 1 || number > 0) {
           if (number % 2 == 0) {
               number /= 2;
           } else {
               number = (3*number) -1;
           }
       }
   if (number == 1) {
       printf("%lld, TRUE", n2);
       number += 2;
   } else { 
        printf("%lld, FALSE", n2);
        number += 2;
   }
   }
}