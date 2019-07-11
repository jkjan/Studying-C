#include <stdio.h>
#include <string.h>
int main () {

	char str[100];

	puts("input your string");

	//input string
	fgets(str, 100, stdin);

	//get the length of the string
	int len = strlen(str);

	//delete the buffer of str
	str[len] = '\0';
	

	//change every blank into newline
	for (int i=0; i<len; i++) {
		if (str[i] == ' ')
			str[i] = '\n';
	}

	puts("\nprinting a word in a line");
	//print words
	for (int i=0; i<len; i++) 
		printf("%c", str[i]);
	

}
