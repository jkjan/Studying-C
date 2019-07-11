#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int vsum(int n, ...) {
	va_list ap;   //to declare a variable that  will refer to each argument in turn
	va_start(ap, n);  //to initialize ap to point to the  first unnamed argument.
	int sum = 0;

	for (int i = 0; i < n; i++)    //the first arg is a total num of the args
		sum += va_arg(ap, int);     //to return one argument and steps argument pointer to the next

	va_end(ap); //clean up
	return sum;
}


int main () {
	printf("1+2=%d\n", vsum(2, 1, 2));
	printf("1+2+3=%d\n", vsum(3, 1, 2, 3));
	printf("1+2+3+4=%d\n", vsum(4, 1, 2, 3, 4));
	return 0;
}
