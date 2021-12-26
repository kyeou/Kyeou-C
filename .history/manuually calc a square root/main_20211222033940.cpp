#define forL(x, y, z) for(int i = x; i < y; z)
#define printS(s) std::cout << s << std::endl;
#define randK(x) 1 + (rand() % x);
#define ifS(a, b) if (a) b;
#define ifES(a, b, c, d) if (a) {b} else (c) {d} ;
#include <iostream>
//if any of these function return -1, no square root exists
int repSubtraction(int num);
int primeFactorization(int num);
//int estimationMethod();
//int longDivisionMethod();




int main() {
 printS(repSubtraction(256));
}

int repSubtraction(int num) {
  int copy = num;
  forL(1, num, i += 2) {
      if (copy > 0) {
          copy -= i;
      } else {
          return (copy == 0) ? (i-1)/2 : -1; 
      }
  }
  return 0;
}

int primeFactorization(int num) {
    std::string numAsString = to_string (num);
    if ()
}