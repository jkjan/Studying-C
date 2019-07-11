#include <stdio.h>
#define multiple(x, y, z) ((x)*(y)*(z))

int main() {
	int a, b, c, res;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	res=multiple(a, b, c);

	printf("%d", res);

	return 0;
}