#include <stdio.h>
#include <stdlib.h>

int isprime(int n);

typedef struct _multi {
	int a;
	int b;
	int c;
} multi;

typedef struct _primes {
	multi* ddd;
	int cnt;
}primes;


int main()
{
	int N;
	int i, j;
	int n = 0;
	int num = 0;
	int comcnt = 0;
	scanf("%d", &N);
	primes *real = (primes*) malloc(sizeof(primes));
	real->ddd = (multi*)malloc(sizeof(multi)*N*(N - 1) / 2);
	int * pnum = (int*)malloc(sizeof(int) * 100);

	real->cnt = 0;

	for (i = 1; i <= N; i++) {
		if (isprime(i)==1) {
			*(pnum + n) = i;
			printf("%d ", i);
			n++;
		}
	}

	printf("%d\n", n);

	for (i = 0; i < n; i++) {
		for (j = i + 1; j <= n; j++) {
			((real->ddd) + num)->a = *(pnum + i);
			((real->ddd) + num)->b = *(pnum + j);
			((real->ddd) + num)->c = *(pnum + i)  * (*(pnum + j));

			real->cnt++;



			num++;
		}
	}

	for (i = 0; i < real->cnt; i++) {
		if (isprime(((real->ddd) + i)->c))
			comcnt++;
	}

	printf("%d", comcnt);

	return 0;
}

int isprime(int n) {
	if (n==1)
		return 0;
	else {
		for (int i = 2; i < n; i++) {
			if (n%i == 0)
				return 0;
		}
	}

	return 1;
}