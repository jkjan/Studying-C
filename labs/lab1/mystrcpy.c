#include <stdio.h>

void mystrcpy (char*s, char*t);

int main () {
	char a[] = "Hello";
	char b[] = "fucks";
	printf("%s %s\n", a, b);
	mystrcpy(a, b);
	printf("%s %s\n", a, b);
	}

void mystrcpy(char*s, char*t) {
	while(*s++ = *t++)
		;
}

