#include <stdio.h>
#include <string.h>
int main() {
	char words[101];
	int len;

	while ((fgets(words, 101, stdin))) {
		//len = strlen(words);
		//words[len - 1] = '\0';
		printf("%s", words);
	}

	return 0;
}