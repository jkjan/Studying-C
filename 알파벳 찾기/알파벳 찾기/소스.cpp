#include <stdio.h>
#include <string.h>
int main() {
	char alphabets[26];
	int i;

	for (i = 0; i < 26; i++) {
		alphabets[i] = -1;
	}

	char word[101];
	scanf("%s", word);
	int len = strlen(word);
	for (i = 0; i < len; i++) {
		if (alphabets[word[i] - 97] == -1)
			alphabets[word[i] - 97] = i;
	}
	for (i = 0; i < 26; i++) {
		printf("%d ", alphabets[i]);
	}
	return 0;
}