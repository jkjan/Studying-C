#include <stdio.h>
void Swap(int *num1, int *num2, int *num3) {
	int temp2, temp3;
	temp2 = *num2; 
	temp3 = *num3;
	*num2 = *num1;
	*num3 = temp2;
	*num1 = temp3;
}

int main() {
	int num1 = 10;
	int num2 = 20;
	int num3 = 30;

	/*int *pnum1 = &num1;
	int *pnum2 = &num2;
	int *pnum3 = &num3;*/

	Swap(&num1, &num2, &num3);
	printf("%d %d %d", num1, num2, num3);
}