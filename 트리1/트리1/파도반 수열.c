#include <stdio.h>

int wave(int num);

int main() {
	int n;
	int a, i;

	scanf("%d", &n);

	int* lis = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		*(lis + i) = wave(a);
	}

	for (i = 0; i < n; i++)
		printf("%d\n", *(lis + i));

	return 0;
}

int wave(int num) {
	if ((num == 1) || (num == 2) || (num == 3))
		return 1;
	else if ((num == 4) || (num == 5))
		return 2;

	else
		return wave(num - 1) + wave(num - 5);
}