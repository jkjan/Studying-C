#include <stdio.h>

char*expand(char* s1, char*s2);

int main() {
   char expanded[100];

   printf("%s\n", expand("a-g", expanded));
   printf("%s\n", expand("0-9", expanded));

   return 0;
}

char*expand(char* s1, char*s2) {
   char s, e;
   int j =0;
   s = s1[0];

   //s1[1] = -
   e = s1[2];
   
   //thanks to ascii code
   for (int i = s; i <= e; i++) {
      s2[j] = i;
      j++;
   }

   s2[j] = 0;

   return s2;

}
