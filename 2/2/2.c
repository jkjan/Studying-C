#include <stdio.h>
#include <math.h>
#include <string.h>

double round(double x, int digit);

int main() {
   double i=1;

   int ifa = 1;
   char c;

   double num1 = 0;
   double num2 = 0;
   int a = 0;
   int b = 0;
   double num=0;
   int cal;
   double sosu = 0;

   while ((c = getchar()) != EOF) {
      //determine where it should save the number in. 
      //if a has a value, it should save characters into b
      if (num1 == 0)
         ifa = 1;

      if ((num1 != 0) && (c < '0' || c > '9') && (c != '.')) {
         ifa = 0;
         i = 1;
      }

      //saving numbers on a basis that ifa is 0 or not
      if (c == '.') 
         i = 0.1;

      if (c >= '0' && c <= '9') {
         if (i==1) {
            if (ifa) {
               num1 *= 10;
               num1 += c - '0';
            }
            else {
               num2 *= 10;
               num2 += c - '0';
            }
         }
         
         else if (i<1) {
            if (ifa) {
               num1 += (c - '0') * i;
               i = i / 10;
            }
            else {
               num2 += (c - '0') * i;
               i = i / 10;
            }
         }
      }

      //calculation symbol input
      if (c == '/')
         cal = 1;
      else if (c == '*')
         cal = 2;
      else if (c == '%')
         cal = 3;
      else if (c == '+')
         cal = 4;
      else if (c == '-')
         cal = 5;
      
	  //calculate by cases
      if (c == '\n') {
		  switch (cal) {
		  case 1: printf("%.10g\n", round(num1 / num2, 6));
				  break;
			
		  case 2: printf("%.10g\n", round(num1*num2, 6));
			      break;

		  case 3: printf("%d\n", abs(num1) % abs(num2));
				  break;

		  case 4: printf("%.10g\n", round(num1 + num2, 6));
			      break;

		  case 5: printf("%.10g\n", round(num1 - num2, 6));
		  }
         i = 1;
         num1 = 0;
         num2 = 0;
      }
   }
}

double round(double x, int digit) {
	return (floor((x)* pow(10, digit) + 0.5f) / pow(10, digit));
}