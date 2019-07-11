#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE*fp = fopen("words.txt", "wt");
	fputs("Apple Pineapple Banana Program", fp);
	fclose(fp);

	fp = fopen("words.txt", "rt");

	char text[50];
	fgets(text, 50, fp);
	int i;
	int pcnt = 0;
	int acnt = 0;

	for (i = 0; i < 50; i++); {
		if (text[i] == ' ') {
			if (text[i+1] == 'a' || text[i+1] == 'A')
				acnt++;
			else if (text[i+1] == 'p' || text[i+1] == 'P')
				pcnt++;
		}
	}

	printf("A로 시작하는 단어의 수 : %d\n", acnt);
	printf("P로 시작하는 단어의 수 : %d\n", pcnt);


	fclose(fp);
	return 0;
}