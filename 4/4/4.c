#include <stdio.h>
#include <string.h>

char *reverse(char *s);


int main() {
	char c;
	char s[100];
	int i=0;

	while ((c = getchar()) != EOF) {
		if (c != '\n') {
			s[i] = c;
			i++;
		}
		
		
		if (c == '\n'){
			s[i] = 0;
			printf("%s", reverse(s));
			printf("\n\n");
			i = 0;
		}
	}
}

char* reverse(char *s) {
	char c;
	int i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

	return s;
}