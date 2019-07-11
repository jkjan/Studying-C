#include <stdio.h>

int main() {
	int ch;

	while (1) {
		ch = getchar();   //문자 입력, 문자열도 됨. 한문자씩 한문자씩 받아들임
		if (ch == EOF) //EOF : End of File의 약자, 파일의 끝을 표현하기 위해 정의해 놓은 상수.
			break;   
		putchar(ch);  //받은 문자를 그대로 출력. 
	}
	return 0;
}

// fgetc(stdin); 후 Ctrl + Z 시 EOF 반환 (Windows 기준) - ^Z
// 왜냐하면 키보드엔 EOF가 없으므로

//출력에서 자동으로 개행이 이뤄지는 이유?
// Hi 하고 엔터 입력시 똑같이 Hi 엔터를 출력하니까.  엔터도 문자다.