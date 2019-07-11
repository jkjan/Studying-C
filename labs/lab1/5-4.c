#include <stdio.h>

void b(int *p) {
	printf("%d %d %d\n", p[0], p[-1], p[-2]);        //9 8 7
	                                                 //calculating with pointer is possible, in some case like this
	return;
}


int main() {

	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int n = (int)(sizeof(a) / sizeof(int));  //how many elements a has

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);         //that would be printing 0 ~ 9

	putchar('\n');

	b(a + n - 1);        // a + n - 1 means the address of the n-1 th element of a.
	                     // so, it is basically the last element. the address of 9.

	return 0;

}
