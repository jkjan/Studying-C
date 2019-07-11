#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf_s("%d", &n);
	
	for (int y = n; y >= -5 * n / 3; y--) {
		for (int x = -2 * n - 1; x <= 2 * n + 1; x++)
			printf((y <= x * 2 + n) + (y <= -x * 2 + n) + (y >= x / 2 - n) + (y >= -x / 2 - n) + (y <= 0) >= 4 ? "*" : " ");
		printf("\n");
	}
	return 0;
	

	int a, b;
	scanf_s("%d %d", &a, &b);
	/*
	for (int y = a; y >= -a; y--) {
		for (int x = -a-1; x <= a + 1; x++)
			printf(pow(x, 2) + pow(y, 2) <= (double)a*a ? "o" : " ");
		printf("\n");
	}
	*/
	/*
	for (int y = b; y >= -b; y--) {
		for (int x = -a-1; x <= a + 1; x++)
			printf(pow(x, 2) / (a * a) + pow(y, 2) / (b * b) <= 1 ? " * " : " ");
		printf("\n");
	}
	*/
	





}