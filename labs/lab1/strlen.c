#include <stdio.h>
#include <string.h>

int lenstr(char sss[]);

int main () {
	char str[] = "Hello";
	printf("%d\n", (int)strlen(str));
	printf("%d\n", lenstr(str));
	}

int lenstr(char sss[]) {
	int i=0;
	while (sss[i] != '\0')
		i++;
	return i;
	}
