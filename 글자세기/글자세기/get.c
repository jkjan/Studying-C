#include "6-3h.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch() {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch : too many characters\n");
	else
		buf[bufp++] = c;
}

int getword(char* word, int lim) {
	int c;
	char* w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		* w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}