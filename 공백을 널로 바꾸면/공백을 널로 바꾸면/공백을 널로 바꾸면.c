#include <stdio.h>
int main() {
	char s[14] = "wel come to c";
	int i;
	for (i = 0; i < 14; i++) {
		if (s[i] == ' ')
			s[i] = '\0';
	}
	for (i = 0; i < 2; i++)
		printf(s[i]);


}