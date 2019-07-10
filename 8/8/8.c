#include <stdio.h>

int main() {

	unsigned int fac = 1;

	for (int i = 1; i <= 20; i++) {
		for (int j = i; j >= i; j--)
			fac *= j;

		printf("%llu\n", fac);
	}
		
	return 0;
}
