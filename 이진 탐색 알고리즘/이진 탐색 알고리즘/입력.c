#include "testing.h"

int *input() {
	printf("몇 개 입력? : ");
	scanf("%d", &quan);

	int*tank = (int*)malloc(sizeof(int)*quan);

	for (i = 0; i < quan; i++)
		scanf("%d", tank + i);

	return tank;
}