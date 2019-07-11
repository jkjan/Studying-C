#include <stdio.h>
int main() {
   int line = 0;
   for (int i = 33; i <= 126; i++) {

      //printing i in different ways
      printf("%3d %X %c  ", i, i, i);
      line++;

      //change lines every 6 print
      if (line == 6) {
         printf("\n");
         line = 0;
      }
   }

   printf("\n");
   return 0;
}
