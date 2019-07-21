#include <iostream>
#include <cmath>

using namespace std;

typedef struct _drugs {
	int*super;
	int cnt;
}drugs;

drugs* init() {
	drugs *real = (drugs*)malloc(sizeof(drugs));
	real->super = (int*)malloc(sizeof(int) * 100);

	real->cnt = 0;

	return real;
}

int add(drugs* loc, int n) {
	loc->super[loc->cnt] = n;
	loc->cnt++;

	return 0;
}

int drug(int n, int d) {
	if (n%d == 0)
		return 1;

	return 0;
}

int isprime(int n) {
	if (n==1)
		return 0;

	for (int i = 2; i < n; i++)
		if (n%i == 0)
			return 0;

	return 1;
}

int main() {
	int num;
	scanf("%d", &num);

	int i;

	int j = 0;

	drugs *ok = init();

	for (i = 1; i <= num; i++)
		if (drug(num, i)&&isprime(i)) 
			add(ok, i);

	int *gas = (int*)malloc(sizeof(int)*(ok->cnt));

	for (i = 0; i < ok->cnt; i++)
		gas[i] = 0;


	while (j<ok->cnt) {
		if (num % (int)pow(ok->super[j], gas[j]+1) == 0)
			gas[j]++;

		else
			j++;
	}

	printf("%d = ", num);
	for (i = 0; i < ok->cnt; i++) {
		printf("%d^%d ", ok->super[i], gas[i]);
		if (i < ok->cnt - 1)
			printf("x ");
	}
}




