#include <stdio.h>
#include <string.h>
int main() {
	char input[256];
	scanf("%s", input);
	int len = strlen(input);
	for (int i = 0; i < len; i++) {
		if (input[i] >= 65 && input[i] <= 90)
			printf("%c", input[i]);
	}
	return 0;
}