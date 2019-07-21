#include <iostream>
#include <cstring>
int main() {
	char a[21], b[21];
	int num, alen;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf(" %s %s", a, b);
		alen = strlen(a);
		printf("Distances: ");
		for (int j = 0; j < alen; j++)
			printf("%d ", b[j] >= a[j] ? b[j] - a[j] : b[j] + 26 - a[j]);
		printf("\n");
	}
	return 0;
}