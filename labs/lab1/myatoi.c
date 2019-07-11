#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myatoi (char n[]);


int main () {
	char s[] = "1234";
	printf("%d\n", myatoi(s));
	printf("%d\n", atoi(s));
}

int myatoi (char s[]) {
	int i, n;
	n=0;
	for(i = 0; s[i] >= '0' && s[i] <= '9'; i++)
		n = n*10 + s[i] - '0';
	return n;
}

