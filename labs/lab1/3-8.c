#include <stdio.h>

int main() {
   //to store big number (when i > 12, normal int can't handle it)
   long long unsigned int fac = 1;

   for (int i = 1; i <= 20; i++) {
      for (int j = i; j >= i; j--)
         fac *= j;

      printf("%llu\n", fac);
   }
      
   return 0;
}
