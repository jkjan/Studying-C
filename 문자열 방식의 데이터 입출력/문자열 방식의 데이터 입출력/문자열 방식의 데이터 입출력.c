#include <stdio.h>
int main() {
	FILE * fp = fopen("mystory.txt", "rt");

	char in[100];

	for (int i = 0; i < 5; i++) {
		fgets(in, sizeof(in), fp);
		fputs(in, stdout);
	}

	if (fp == NULL) {
		if (feof != 0)
			fputs("���� ��� ����!", stdout);
		else
			fputs("���� ��� ����!", stdout);
	}

	fclose(fp);

	return 0;
}