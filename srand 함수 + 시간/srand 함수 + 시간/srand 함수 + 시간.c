#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand((int)time(NULL)); // 현재시간을 이용한 씨드 설정

	for (int i = 0; i < 5; i++)
		printf("난수 출력 : %d \n", rand() % 99);

	return 0;
}