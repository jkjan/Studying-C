#include <stdio.h>
#include <math.h>

int main() {
	int chaHelper, cha, p, N;
	int cnt = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		cnt++;
		chaHelper = i % 10;
		cha = (i % 100)/10 - chaHelper;

		p = 1;

		while (i / (int)pow(10, p) > 0) {
			chaHelper = (i % (int)pow(10, p)) / (int)pow(10, p-1);
			if (cha != (i % (int)pow(10, p+1))/(int)pow(10, p) - chaHelper) {
				cnt--;
				break;
			}
			p++;
		}
	}
	printf("%d", cnt);

	return 0;
}