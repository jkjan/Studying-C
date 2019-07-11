#include <stdio.h>
int main() {
	int ch1, ch2;

	ch1 = getchar();   //문자 입력
	ch2 = fgetc(stdin);   // 엔터키 입력   (엔터도 입력임)  따라서 ch1에는 p가, ch2에는 엔터가 저장.

	putchar(ch1);  //문자 출력
	fputc(ch2, stdout);   //엔터키 출력
	return 0;
}