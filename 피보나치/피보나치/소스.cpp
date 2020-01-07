#include <stdio.h>

int main() {
	long long int a;
	scanf("%lld", &a);

	long long int c, d, e;
	c = 0;
	d = 1;

	e = c + d;

	if (a == 0) {
		printf("%lld", 0);
		return 0;
	}

	if (a == 1) {
		printf("%lld", 1);
		return 0;
	}

	for (long long int i = 0; i < a-2; i++) {
		c = d;
		d = e;
		e = c + d;
	}
	printf("%lld\n", e);

	return 0;
}