#include <stdio.h>
#define PI 3.14
#define square(x) ((x)*(x))
#define area(r) ((square(r))*PI)


int main() {
	int rad;
	double width;
	scanf("%d", &rad);
	printf("\n");
	width = area(rad);
	printf("%f", width);
}