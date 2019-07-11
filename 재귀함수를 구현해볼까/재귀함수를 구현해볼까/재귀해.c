#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

int fibo(int n);
int fact(int n);
int bin(int n);


int main() {
	int select;
	int till;
	puts("�̰��� ����Լ��� ����");
	printf("1. �Ǻ���ġ 2. ���丮�� 3. ������ : ");
	scanf("%d", &select);

	if (select == 1) {
		printf("�����? : ");
		scanf("%d", &till);
		for (int i = 1; i <= till; i++) {
			printf("%d ", fibo(i));
		}
	}

	if (select == 2) {
		printf("����? : ");
		scanf("%d", &till);
		printf("%d! = %d", till, fact(till));
	}

	if (select == 3) {
		printf("����? : ");
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