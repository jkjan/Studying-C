#include <stdio.h>
<<<<<<< HEAD
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
=======

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
>>>>>>> 0ba30ea316b5ebad600bc13dc6ed51204e5f22f3
