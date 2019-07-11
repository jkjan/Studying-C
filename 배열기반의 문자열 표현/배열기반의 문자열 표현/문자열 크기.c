#include <stdio.h>
void main() {
	char word[100];
	int len=0;
	scanf("%s", word);
	char temp;

	while (word[len] != 0)
		len++;

	printf("%d", len);

	for (int i = 0; i < len / 2; i++) {
		temp = word[i];
		word[i] = word[len-i-1];
		word[len-i-1] = temp;
	}

	printf("%s", word);

	
	return 0;
}