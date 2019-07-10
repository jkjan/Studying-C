#include "변수 함수.h"

int* compareTriplets(int* a, int* b) {
	
	int aw = 0;
	int bw = 0;
	for (i = 0; i < 3; i++) {
		if (*(a + i) > *(b + i))
			aw++;
		else if (*(a + i) < *(b + i))
			bw++;
	}

	int *points = (int*)malloc(sizeof(int) * 2);
	*(points) = aw;
	*(points + 1) = bw;
	return points;

}