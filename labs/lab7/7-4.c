#include <stdio.h>
#include <string.h>

int mystrlen(char * s) {
	int cnt = 0;
	
	while (*(s++) != '\0')  //while it meets null
		cnt++;          //increase cnt;
	
	return cnt;
}


int mystrcmp(char* a, char* b) {
	int i;

	for (i = 0; a[i] == b[i]; i++) //increasing i
		if (a[i] == '\0')
			return 0;
	return a[i] - b[i];    
}

void mystrcat(char*a, char*b) {
	int acnt = mystrlen(a);
	
	for (int i = 0; b[i] != '\0'; i++) {
		a[acnt] = b[i];    //to the end of the charcters
		acnt++;
	}

	a[acnt] = '\0';  //pack
}

void mystrcpy (char*s, char*t) {
	while (*s++ = *t++) //just copy
		;
}

int main () {
	//string functions made by myself
	char a[20] = "Hello";
	char b[7] = " World";
	
	printf("a : %s\n", a);
	printf("b : %s\n", b);
	mystrcat(a, b);
	printf("a + b : %s\n", a);
	printf("the length of a : %d\n", mystrlen(a));
	printf("the length of b : %d\n", mystrlen(b));
	printf("a compared by \"Hello World\" : %d\n", mystrcmp(a, "Hello World"));
	mystrcpy(b, a);
	printf("b = a, b is now : %s\n", b);

	printf("\n\n");



	//string functions built in
	char c[20] = "Hello";
	char d[7] = " World";

	printf("a : %s\n", c);
	printf("b : %s\n", d);
	strcat(c, d);
	printf("a + b : %s\n", a);
	printf("the length of a : %d\n", strlen(c));
	printf("the length of b : %d\n", strlen(d));
	printf("a compared by \"Hello World\" : %d\n", strcmp(c, "Hello World"));
	strcpy(d, c);
	printf("b = a, b is now : %s\n", d);



	return 0;
}
	
