#include <stdio.h>

int main() {
	FILE*fp = fopen("simple.txt", "wt");
	if (fp == NULL) {
		puts("���� ���� ����");
		return -1;
	}
	fputc('A', fp);
	fputc('B', fp);
	fputs("My name is Jin", fp);
	fputs("Your name is Oh", fp);
	fclose(fp);
	return 0;
}