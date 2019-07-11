#include <stdio.h>
int main() {
	char str[100];
	int i;

	for (i = 0; i < 3; i++) {
		fgets(str, sizeof(str), stdin);    //딱 6글자만 읽음. 그 이상 입력시에는 다음에 읽음.
		printf("Read %d : %s \n", i + 1, str);   //개행은 두 번 된다. 입력받은 엔터 + \n
	}
	return 0;
}