#include "testing.h"

int *input() {
	printf("�� �� �Է�? : ");
	scanf("%d", &quan);

	int*tank = (int*)malloc(sizeof(int)*quan);

	for (i = 0; i < quan; i++)
		scanf("%d", tank + i);

	return tank;
}