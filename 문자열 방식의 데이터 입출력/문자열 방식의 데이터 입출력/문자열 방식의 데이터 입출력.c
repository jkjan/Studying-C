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
			fputs("파일 출력 성공!", stdout);
		else
			fputs("파일 출력 실패!", stdout);
	}

	fclose(fp);

	return 0;
}