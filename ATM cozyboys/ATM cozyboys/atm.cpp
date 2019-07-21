#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int i, j, temp;
	int* ppl = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		cin >> ppl[i];
	}

	int sum = 0;
	int tot = 0;

	for (i = 0; i < n - 2; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (ppl[j + 1] < ppl[j]) {
				temp = ppl[j];
				ppl[j] = ppl[j + 1];
				ppl[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			sum += ppl[j];
		}
		tot += sum;
		sum = 0;
	}

	printf("%d", tot);
}