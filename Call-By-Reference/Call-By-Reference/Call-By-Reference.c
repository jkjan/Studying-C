#include <stdio.h>
void Square(int *pnum) {
	(*pnum) *= (*pnum);
}


void main() {
	int num = 2;
	//int *pnum = &num;
	Square(&num);
	printf("%d", num);
}