#include <stdio.h>
int main()
{	int n, i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n-1; i++) {
		for (j = 0; j <= i; j++)
			printf("%d ", n - j);

		for (k = 0; k < 2*(n-i-1)-1; k++)
			printf("%d ", n - i);


		for (j = i; j >= 0; j--)
			printf("%d ", n - j);

		printf("\n");
	}
	for (i = 0; i < n - 1; i++)
		printf("%d ", n - i);
	printf("1 ");
	for (i = n-2 ; i > -1; i--)
		printf("%d ", n - i);

	printf("\n");

	for (i = n-2; i >=0; i--) {
		for (j = 0; j <= i; j++)
			printf("%d ", n - j);

		for (k = 0; k < 2 * (n - i - 1) - 1; k++)
			printf("%d ", n - i);

		for (j = i; j >=0; j--)
			printf("%d ", n - j);

		printf("\n");
	}
}
