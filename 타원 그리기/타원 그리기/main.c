#include <stdio.h>
#include <math.h>

int main() {

	int a, b;

	scanf("%d %d", &a, &b);

	for (int y = b; y >= -b; y--) {
		for (int x = -a - 1; x <= a + 1; x++) {
			printf(pow(x, 2) / (a * a) + pow(y, 2) / (b * b) <= 1 ? " * " : " ");
		}
		printf("\n");
	}

	return 0;
}