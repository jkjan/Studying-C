#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int num;
	scanf("%d\n", &num);
	fflush(stdin);
	char c;

	char ** names = (char**)malloc(sizeof(char*)*num);
	
	for (int i = 0; i < num; i++) {
		*(names + i) = (char*)malloc(sizeof(char) * 100);
		strcpy(*(names + i), "god");
	}

	int len;

	int start = 0;
	char a = '\0';
	for (int i = 0; i < num; i++) {
		len = 3;
		while ((c = getchar()) != '\n') {
			if (c == ' ') {
				start = 1;
			}
			if (start == 1 && c != ' ') {
				*(*(names + i) + len) = c;
				*(*(names + i) + len + 1) = '\0';
				len++;
			}
		}
		start = 0;
	}

	for (int i = 0; i < num; i++) {
		printf("%s\n", *(names + i));
	}

	return 0;
}
