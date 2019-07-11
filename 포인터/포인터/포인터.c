#include <stdio.h>
void main() {
	int num1 = 10;
	int num2= 20;
	
	int *pnum1, *pnum2,  *temp;
	pnum1 = &num1;
	pnum2 = &num2;

	(*pnum1) += 10;
	(*pnum2) -= 10;

	temp = pnum1;
	pnum1 = pnum2;
	pnum2 = temp;

	printf("%d, %d", *pnum1, *pnum2);

	return 0;
}