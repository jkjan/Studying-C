#include <stdio.h> 

int isprime(int n);

int main() {
   int j = 0;

   for (int i = 1; i <= 200; i++) {

      //when i is prime number, and also i isn't 1
      if (i != 1 && isprime(i)) {
         printf("%3d ", i);
         j++;
         }

      //press enter every 6 numbers
      if (j ==6) {
         printf("\n");
         j=0;
      }
   }
   printf("\n");
   return 0;
}


//starting from 2 and till n, if i can devide n without remainder
int isprime(int n) {
   for (int i = 2; i < n; i++) {
      if (n != i && n%i == 0)

         //i is not a prime number
         return 0;
   }
   //if not, i is.
   return 1;
}
