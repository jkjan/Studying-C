#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int y = n; y >= 0; y--) {
		for (int x = 0; x <= n + 1; x++)
			printf(y <= -x + n ? "* " : " ");
		printf("\n");
 	}
	return 0;
}