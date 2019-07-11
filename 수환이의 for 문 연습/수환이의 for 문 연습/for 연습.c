#include <stdio.h>

int main() {
	int num1;
	int fac = 1;
	int i=1;
	printf("한 개의 정수 입력 : ");
	scanf("%d", &num1);
	for (int i = 1; i <= num1; i++) {
		 fac *= i;
	}
	printf("%d!=%d \n",num1,fac);
	return 0;
}