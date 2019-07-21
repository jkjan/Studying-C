#include <stdio.h>
#define ADD(A,B,C) ((A)+(B)+(C))
#define MUL(A,B,C) ((A)*(B)*(C))

int main() {
	printf("3+4+5 = %d\n", ADD(3, 4, 5));
	printf("3x4X5 = %d\n", MUL(3, 4, 5));
	return 0;
}