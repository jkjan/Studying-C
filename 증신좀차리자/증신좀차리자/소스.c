#include <stdio.h>

int main() {
	int num = 0;
	char c;

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			num = num * 10 + c - '0';

		if (c == '\n') {
			printf("%d\n", num+5);
			num = 0;
		}
	}
	return 0;
}