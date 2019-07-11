#include <stdio.h>

int a[][3] = {    {1, 2, 3},
		  {4, 5, 6},
		  {7, 8, 9} };

int *pa[3] = { a[0], a[1], a[2] };

int *p = a[0];

int main() {
	int i;
	for (i = 0; i < 3; i++)
		printf("%d %d %d\n", a[i][2 - i], *a[i], *(*(a + i) + i));

	//the first column shows the Nth row's elements of a, starting from behind , 3, 5, 7
	//the second column shows the elements of the rows of a. 1, 4, 7
	//the last column shows the Nth row's elements of a, so it's 1, 5, 9

	putchar('\n');

	return 0;
}
