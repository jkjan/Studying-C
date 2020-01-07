#include <stdio.h>
#include <time.h>
long long int fibo_naive(long long int n);
long long int fibo_dp(long long int n);
long long int fibo_mine(long long int n);

long long int memo[1000001] = { 0 ,};

int main() {
	clock_t tik, tok;
	long long int a;
	printf("The Nth fibonacci number?\nN : ");
	scanf("%lld", &a);

	//dynamic programming
	printf("\n");
	tik = clock();
	printf("The answer is %lld\n", fibo_dp(a));
	tok = clock();
	printf("Via dynamic programming algorithm,\nit took %.2f seconds\n", (float)(tok - tik) / CLOCKS_PER_SEC);

	puts("\n");

	tik = clock();
	//my algorithm
	printf("The answer is %lld\n", fibo_mine(a));
	tok = clock();
	printf("Via repeating algorithm with for,\nit took %.2f seconds\n", (float)(tok - tik) / CLOCKS_PER_SEC);

	puts("\n");

	tik = clock();
	//naive recursive algorithm
	printf("The answer is %lld\n", fibo_naive(a));
	tok = clock();
	printf("Via naive recursive algorithm,\nit took %.2f seconds", (float)(tok - tik) / CLOCKS_PER_SEC);

	return 0;
 }

long long int fibo_naive(long long int n) {
	if (n <= 2)
		return 1;

	else
		return fibo_naive(n - 1) + fibo_naive(n - 2);
}

long long int fibo_dp(long long int n) {
	if (n <= 2)
		return 1;

	else if (memo[n] != 0)
		return memo[n];

	else {
		memo[n] = fibo_dp(n - 1) + fibo_dp(n - 2);
		return memo[n];
	}
}

long long int fibo_mine(long long int a) {
	long long int c, d, e;
	c = 0;
	d = e = 1;

	if (a <= 2)
		return 1;

	for (long long int i = 0; i < a - 2; i++) {
		c = d;
		d = e;
		e = c + d;
	}

	return e;
}