#include <string.h>
#include <stdio.h>

void reverse(char*s) ;

int main () { 
	char hello[] = "Hello World";


	reverse(hello);

	}

void reverse (char *s) {
	int c, i, j;

	for (i=0, j = strlen(s) -1; i< j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		printf("%s\n", s);
		}
	}
