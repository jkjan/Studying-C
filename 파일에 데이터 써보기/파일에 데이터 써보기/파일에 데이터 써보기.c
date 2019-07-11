#include <stdio.h>
int main() {
	FILE *fp = fopen("data.txt", "wt");
	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1; //비정상적 종료 의미
	}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	rewind(fp);
	fputc('E', fp);
	fputc('B', fp);
	fputc('C', fp);
	fclose(fp);

	fp = fopen("data.txt", "rt");

	char d[4];
	fscanf(fp, "%s", d);
	printf("%s", d);

	fclose(fp);   //스트림 종료
	
	return 0;
}
