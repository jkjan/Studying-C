#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sockMerchant(int n, int ar[]) {
	int i, j;
	int ano[100];
	int *ptr = ano;
	int sum = 0;
	int cnt = 0;
	int ifcnt = 0;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n; j++) {
			if (*(ptr + j) == ar[i])
				ifcnt++;
		}
		if (ifcnt == 0) {
			ano[i] = ar[i];
			sum += 1;
			for (j = i + 1; j < n; j++) {
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
	int socks;
	int i;
	
	printf("�縻�� �� ¦�Դϱ�? ");
	scanf("%d", &socks);
	int* howmany = (int*)malloc(sizeof(int)*socks);

	
	printf("���� ���� ���� ���Դϱ�? ");

	for (i = 0; i < socks; i++) {
		scanf("%d", &howmany[i]);
	}

	printf("\n");

	printf("\n%d¦�� �����ϰڳ׿�.", sockMerchant(socks, howmany));

	return 0;
}