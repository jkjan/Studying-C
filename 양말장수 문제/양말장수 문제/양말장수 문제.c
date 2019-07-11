#include <stdio.h>
#include <string.h>
#define many 10
int findif(int n,int ara[]) {
	int i;
	int cnt = 0;

	for (i = 0; i < many; i++) {
		if (ara[i] == n) 
			cnt++;
	}

	if (cnt == 0)
		return 0;
	else
		return 1;
}

int sockMerchant(int n, int ar[]) {
	int i, j;
	int ano[10];
	int sum = 0;
	int cnt = 0;

	for (i = 0; i < n-1; i++) {
		if (findif(ar[i], ano) == 0) {
			ano[i] = ar[i];
			sum += 1;
			for (j = i+1; j < n; j++) {
				if (ar[i] == ar[j])
					sum++;
			}
		}
		cnt += sum / 2;
		sum = 0;
	}
	return cnt;
}

int main() {
	int socks=9;
	int howmany[many];
	int i;
	/*
	printf("양말은 몇 짝입니까? ");
	scanf("%d", &socks);
	*/
	printf("색은 각각 무슨 색입니까? ");

	for (i = 0; i < many; i++) {
		scanf("%d", &howmany[i]);
	}
	
	printf("\n");

	printf("\n%d짝이 가능하겠네요.", sockMerchant(socks, howmany));      

	return 0;
}