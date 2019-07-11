#include "head.h"
#define bufsize 100

char buf[bufsize];
int bufp = 0;

int getch() {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= bufsize)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]
		= c;
}
