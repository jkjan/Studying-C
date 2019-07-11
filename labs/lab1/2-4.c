#include <stdio.h>

int main() {
	puts("saving 10 to i");
	int i = 10;
	puts("saving 20 to j");
	int j = 20;

	//saving the value of i plus j into sum
	int sum = i+j;

	puts("calculating i + j");
	puts("calculating done");
	printf("%d + %d = %d\n", i, j ,sum);

	return 0;
}
