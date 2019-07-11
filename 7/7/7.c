#include <stdio.h> 

int isprime(int n);

int main() {


	for (int i = 1; i <= 200; i++)
		if (i != 1 && isprime(i))
			printf("%d ", i);
	return 0;
}

int isprime(int n) {
	for (int i = 2; i < n; i++) {
		if (n != i && n%i == 0)
			return 0;
	}
	return 1;
}