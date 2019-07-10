#include <stdio.h>
int main() {
	int line = 0;
	for (int i = 33; i <= 126; i++) {
		printf("%3d %X %c  ", i, i, i);
		line++;
		if (line == 6) {
			printf("\n");
			line = 0;
		}
	}
	return 0;
}