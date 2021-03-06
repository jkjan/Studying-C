#include <stdio.h>

int find(int n);

int main() {
	int m, n, i;
	scanf ("%d %d", &m, &n);

	if (m < 1 || n> 1000000)
		return 0;

	for (i = m; i <= n; i++) {
		if (find(i))
			printf("%d ", i);
	}
	return 0;
}

int find(int n) {
	int i = 1;
	if (n == 1)
		return 0;
	else {
		while (i < n - 1) {
			i++;
			if (!(n%i))
				return 0;
		}
	}
	return 1;
}
