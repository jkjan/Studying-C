#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double logB(double x, double base) {
	return log(x) / log(base);
}


int list[100];
int* ptr = list;

int bin(int n) {
	if (n == 1 || n == 0)
		*ptr = n;
	else {
		bin(n / 2);
		*ptr = n % 2;
		ptr++;
	}
	return 0;
}


int main() {

	int n;

	scanf("%d", &n);
	int num = logB(n, 2) + 1;

	/*
	int *arr = (int *)malloc(sizeof(int) * num);
	int *ptr = arr;
	cc = n;
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
	int cnt=0;
	int cntmax=0;
	*/
	int i;
	int cnt = 0;
	int cntmax = 0;

	for (i = 0; i < num; i++) {
		printf("%d", list[i]);
	}

	/*

	for (i = 0; i < num; i++) {
		if (list[i] == 1)
			cnt++;
		else {
			if (cnt > cntmax)
				cntmax = cnt;
			cnt = 0;
		}
	}

	
	for (i = 0; i < num; i++) {
		printf("%d", list[i]);
	}
	printf("\n\n");

	printf("%d", cntmax);
	*/

	return 0;
}


