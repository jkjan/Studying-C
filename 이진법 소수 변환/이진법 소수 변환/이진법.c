#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *bin(int n);
int bincnt = 0;
int dotupper[23];
int num;

double logB(double x, double base) {
	return log(x) / log(base);
}

int floating(float n);

int bin2(int n);

int main() {

	float n;
	scanf("%f", &n);
	if (floor(n) < n)
		floating(n);
	else
		bin(n);
		for (int i = 0; i < num; i++) {
			printf("%d",*( bin(n) + i));
		}
}

int floating(float n) {
	int dotunder[23];
	float dot;
	int i;
	//scanf("%f", &n);

	dot = n - floor(n);
	n = floor(n);

	for (i = 0; i < 23; i++) {
		dot *= 2;
		dotunder[i] = floor(dot);
		dot = dot - floor(dot);
	}
	
	bin(n);

	int cnt = num;

	printf("0 ");

	for (i = 0; i < 8; i++) {
		printf("%d", *(bin(127+cnt-1)+i));
	}
	
	printf(" ");
	
	for (i = 0; i < cnt-1; i++) {
		printf("%d", *(bin(n) + i+1));
	}
	
	for (i = 0; i < 21 - cnt+1; i++) {
		printf("%d", dotunder[i]);
	}
	
}


/*
int bin(int n) {
	if (n == 1 || n == 0)
		dotupper[j] = n;
	else {
		bin(n / 2);
		dotupper[j] = n % 2;
	}
	bincnt++;
	j++;
	return 0;
}
*/

int * bin(int n) {

	num = logB(n, 2) + 1;
	int *arr = (int *)malloc(sizeof(int) * num);
	int *ptr = arr;
	int cc = n;
	int dd;
	//printf("%d", num);
	int i;

	while (cc > 0) {
		dd = cc % 2;
		cc = cc / 2;
		*ptr = dd;
		ptr++;
	}

	int *arr2 = (int *)malloc(sizeof(int) * num);
	for (i = 0; i < num; i++) {
		arr2[i] = arr[num - i - 1];
	}
	free(arr);

	return arr2;
}


int bin2(int n) {
	if (n == 1 || n == 0)
		printf("%d", n);
	else {
		bin(n / 2);
		printf("%d", n % 2);
	}
	return 0;
}
