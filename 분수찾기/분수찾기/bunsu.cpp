#include <stdio.h>
#include <math.h>

void main() {
	int a;
	scanf("%d", &a);

	int b = (3 + sqrt(8 * a - 7)) / 4; //해당 위치
	int c = 2 * b; //중간 값
	int d = ((2 * b*b - 3 * b + 2) + ((2 * (b + 1)*(b + 1) - 3 * (b + 1) + 2) - 1)) / 2; //중간의 위치

	printf("%d/%d", (abs(d-a)+ (d-a<=0 ? 1:0)),  (c - abs(d - a)));
}