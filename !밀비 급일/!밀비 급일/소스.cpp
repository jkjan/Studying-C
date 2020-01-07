#include <stdio.h>
#include <string.h>
int main() {
	char encrypted[501];
	scanf(" %[^\n]", encrypted);
	int len = strlen(encrypted);
	while (strcmp(encrypted, "END") != 0) {
		for (int i = len - 1; i >= 0; i--)
			printf("%c", encrypted[i]);
		printf("\n");
		scanf(" %[^\n]", encrypted);
		len = strlen(encrypted);
	}
	return 0;
}