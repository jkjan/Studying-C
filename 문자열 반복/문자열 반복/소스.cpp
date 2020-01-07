#include <stdio.h>
#include <string.h>
int main() {
	int test, i, j, re, len;
	char word[21];
	scanf("%d", &test);

	for (i = 0; i < test; i++) {
		scanf("%d %s", &re, word);
		len = strlen(word);
		for (j = 0; j < len; j++) {
			for (int k = 0; k < re; k++)
				printf("%c", word[j]);
		}
		printf("\n");
	}
	return 0;
}