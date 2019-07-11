#include <stdio.h>

int get() {
	FILE * fp = fopen("easy.txt", "wt");
	if (fp == NULL) {
		puts("파일오픈 실패");
		return -1;
	}
	char input[100];
	int i;
	for (i = 0; i < 4; i++) {
		fgets(input, sizeof(input), stdin);
		fputs(input, fp);
	}
	fclose(fp);
	return 0;
}

int put() {
	FILE * fp = fopen("easy.txt", "rt");
	if (fp == NULL) {
		puts("파일오픈 실패");
		return -1;
	}
	int i;
	char in[100];
	puts("\n\nWhat you wrote is...");
	for (i = 0; i < 4; i++) {
		fgets(in, sizeof(in), fp); //fgets는 개행까지 읽는다. 안 하면 끝까지 읽음
		printf("%s", in);
	}
	fclose(fp);
	return 0;
}

int main() {
	get();
	put();
}