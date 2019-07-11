#include <stdio.h>

int main() {
	int a, b, sum;

	//get a and b
	scanf("%d %d", &a, &b);

	//calculate a minus b and save it to sum
	sum = a - b;

	//if a >= b is true, print sum, if not, print -sum
	printf("%d", a >= b ? sum : sum * (-1));

	return 0;
}