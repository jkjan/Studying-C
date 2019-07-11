#include <stdio.h>
#include "변수 함수.h"

int main() {
	int a[3];
	int b[3];
	

	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	scanf("%d %d %d", &b[0], &b[1], &b[2]);

	int*result = compareTriplets(a, b);

	for (i = 0; i < 2; i++)
		printf("%d ", *(result+i));

}