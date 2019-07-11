#include <stdio.h>
#include <stdlib.h>


int main() {

	char *name = (char*)malloc(sizeof(char) * 11);
	gets(name);

	int i, j;

	int pre = -1;
	int rev[100];
	int *ptr = rev;

	for (i = 0; i < 11; i++) {
		if (name[i] == ' ') {
			for (j = pre + 1; j < i; j++) {
				*ptr = j;
				ptr++;
			}
			pre = i;
		}
	}

	/*for (i = 0; i < sizeof(name); i++) {
		name[i] = name[rev[i]];
	}*/


	for (i=0; i<11; i++)
		printf("%d ", *(ptr+i));
	free(name);
	return 0;
}