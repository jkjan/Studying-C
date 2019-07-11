#include <stdio.h>
#include <string.h>

void RemoveBSN(char str[]) {
	int len = strlen(str);
	str[len - 1] = 0;    //엔터 자체를 널로 만듦.
}

int main() {
	char str[100];
	printf("문자열 입력: ");
	fgets(str, sizeof(str), stdin);
	printf("길이 : %d, 내용: %s \n", strlen(str), str);  //역시 엔터가 포함돼서 실제 글자수보다 하나 더 많음.

	RemoveBSN(str);        //예 : 가나다 하고 엔터 칠 시에 str엔 가나다\n\0 이 저장됨.
	printf("길이: %d, 내용: %s \n", strlen(str), str);
	return 0;
}