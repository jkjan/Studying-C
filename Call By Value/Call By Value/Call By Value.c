#include <stdio.h>
int Square(int val) {
	val *= val;
	return val;
}


void main() {
	int num = 2;
	int *pnum = &num;
	printf("%d", Square(num));
}