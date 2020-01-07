#include <stdio.h>

int isPrime(int i);

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++) {
		if (isPrime(i)) {}
			printf("%d\n", i);
	}

	return 0;
}

int isPrime(int a) {
	if (a <= 0 || a == 1) {
		return 0;
	}

	if (a == 2)
		return 1;

	for (int i = 2; i < a; i++) {
		if (a%i == 0)
			return 0;
	}

	return 1;
}