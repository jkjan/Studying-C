#include <stdio.h>

int main() {
	FILE * fp = fopen("data.txt", "wt"); //wt 모드로 스트림 형성
	if (fp == NULL) {
		puts("파일 오픈 실패");
		return -1;  //비정상적 종료 의미하기 위해 -1 반환

	}

	fputs("Addd", fp);
	fputc('B', fp);
	fputc('C', fp);
	fclose(fp);   //스트림 종료
	return 0;
}