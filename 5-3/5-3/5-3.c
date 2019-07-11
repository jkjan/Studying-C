#include <stdio.h>

int mystrlen(char*s);


int main() {
	char *s[] = { "This is Lab5", "Easy C Programming", "Have fun" };

	printf("with strlen()\n");

	int n = (int)(sizeof(s) / sizeof(char*));    // the number of the string array's total characters.

	for (int i = 0; i < n; i++)
		printf("%s %d\n", *(s + i), (int)strlen(s[i]));
	putchar('\n');

	// print string s and string length using mystrlen() with for loop
	printf("with mystrlen()\n");

	for (int i = 0; i < n; i++)
		printf("%s %d\n", *(s + i), (int)mystrlen(s[i]));

	return 0;

}

int mystrlen(char*s) {
	int cnt = 0;

	for (int i = 0; *(s + i) != NULL; i++)       //i starting from 0, till the received string's ith 
		                                         //character isn't NULL cnt increases one by one
		cnt++;
	

	return cnt;
}

