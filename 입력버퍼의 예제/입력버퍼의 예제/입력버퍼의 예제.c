#include <stdio.h>

int main() {
	char perID[7];
	char name[10];

	fputs("주민번호 앞 6자리 입력: ", stdout);
	fgets(perID, sizeof(perID), stdin);

	fputs("이름 입력: ", stdout);
	fgets(name, sizeof(name), stdin);   //입력할 기회를 잃어버린다. 왜냐하면 앞에서 숫자6자리 + 엔터를 읽으나 perID의 크기가 6이어서
										//엔터가 남는다. 따라서 이 fgets에서 바로 엔터를 읽어버려서 줄이 바뀌게 된다.
	printf("주민번호: %s \n", perID);
	printf("이름: %s \n", name);
	return 0;
}