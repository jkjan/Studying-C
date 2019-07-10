#include <stdio.h>
int recursive(int n) {
	if (n <= 0) {
		return 0;
	}
	printf("%d\n", n);
	recursive(n - 1);
}

int main() {
	recursive(10);
}