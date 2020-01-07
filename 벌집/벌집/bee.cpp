#include <stdio.h>
#include <math.h>
int main() {
	long long int a;
	scanf("%lld", &a);

	if (a == 1) {
		printf("1");
		return 0;
	}
	long long int b = (1+sqrt(1-(8-4*a)/3)) / 2 + 1;
	printf("%lld", b);
	return 0;
}