#include <stdio.h>
#include <stdlib.h>

#define RAND_MAX 99

int random () {

	return rand();

}


void main() {
	printf("0부터 %d까지 \n", RAND_MAX);
	for (int i = 0; i < 5; i++)
		printf("%d \n", rand()%99);
}

//rand() 함수는 가짜 난수이다. 따라서 srand() 함수에서 인자를 받아야 한다.