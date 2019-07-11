#include <stdio.h>

void Odd(int *n) {

	for (int i = 0; i < 10; i++) {
		if ((*n) % 2 != 0) {
			printf("%d ", (*n));
		}
		n++;
	}
	printf("\n");
}

void Even(int *n) {
	for (int i = 0; i < 10; i++) {
		if ((*n) % 2 == 0) {
			printf("%d ", (*n));
		}
		n++;
	}
	printf("\n");
}


void main() {
	int Arr[10];

	for (int i = 0; i < 10; i++) {
		scanf("%d ", &Arr[i]);
	}

	Odd(&Arr);
	Even(&Arr);

	return 0;
}



