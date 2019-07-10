#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

int fibo(int n);
int fact(int n);
int bin(int n);


int main() {
	int select;
	int till;
	puts("이것이 재귀함수의 기초");
	printf("1. 피보나치 2. 팩토리얼 3. 이진수 : ");
	scanf("%d", &select);

	if (select == 1) {
		printf("몇까지? : ");
		scanf("%d", &till);
		for (int i = 1; i <= till; i++) {
			printf("%d ", fibo(i));
		}
	}

	if (select == 2) {
		printf("몇팩? : ");
		scanf("%d", &till);
		printf("%d! = %d", till, fact(till));
	}

	if (select == 3) {
		printf("몇을? : ");
		scanf("%d", &till);
		bin(till);
	}
}

int fibo(int n) {
	if (n < 3)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

int fact(int n) {
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
}

int bin(int n) {
	if (n ==1 || n==0)
		printf("%d", n);
	else {
		bin(n/2);
		printf("%d",  n % 2);
	}
	return 0;
}