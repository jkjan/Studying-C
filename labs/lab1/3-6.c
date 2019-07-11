#include <stdio.h>

int main() {
   int a, b;
   while(1) {
        scanf("%d %d", &a, &b);

        //if i can devide a and b without remainders
        for (int i = 2; i<= (a>b?a:b); i++) {
            if ((a%i == 0) && (b%i == 0))
                 printf("%d ", i);
            }

        printf("\n");
 
        //to end the program
        if (a ==0 && b ==0) { 
            printf("\n");
            return 0;
         }
   }
}
