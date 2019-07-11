#include <stdio.h>
#include <string.h>
//declaring a function
char *reverse(char *s);

int main() {
   char c;
   char s[100];
   int i=0;

   //puting characters into s
   while ((c = getchar()) != EOF) {
      if (c != '\n') {
         s[i] = c;
         i++;
      }
      
      //if press enter print reversed string
      if (c == '\n'){
         s[i] = 0;
         printf("%s", reverse(s));
         printf("\n\n");
         i = 0;
      }
   }
}

char* reverse(char *s) {
   char c;
   int i, j;

   //i starting from the beginning, j starting from the end
   for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
      //till i and j meet, swap characters
      c = s[i];
      s[i] = s[j];
      s[j] = c;
   }

   return s;
}
