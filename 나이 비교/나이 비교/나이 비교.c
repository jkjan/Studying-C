#include <stdio.h>
#include <string.h>

void cut() {
	while (getchar() != ' ');
}

int main() {
	char ch1[100], ch2[100];
	fgets(ch1, sizeof(ch1), stdin);
	//cut();

	fgets(ch2, sizeof(ch2), stdin);
	//cut();

	printf("%d", strcmp(ch1, ch2));

	return 0;
}