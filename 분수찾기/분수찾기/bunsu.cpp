#include <stdio.h>
#include <math.h>

void main() {
	int a;
	scanf("%d", &a);

	int b = (3 + sqrt(8 * a - 7)) / 4; //�ش� ��ġ
	int c = 2 * b; //�߰� ��
	int d = ((2 * b*b - 3 * b + 2) + ((2 * (b + 1)*(b + 1) - 3 * (b + 1) + 2) - 1)) / 2; //�߰��� ��ġ

	printf("%d/%d", (abs(d-a)+ (d-a<=0 ? 1:0)),  (c - abs(d - a)));
}