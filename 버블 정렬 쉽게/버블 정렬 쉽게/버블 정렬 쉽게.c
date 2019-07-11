#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubblesort(int *arr, int n) {
	int sorted = 0;
	int cnt = 0;
	int i;
	while (!sorted) {
		sorted = 1;
		for (i = 0; i < n - 1; i++) {
			if ((*(arr+i) > *(arr+i+1) ? 1:0) > 0) {
				int tmp = *(arr+i);
				*(arr+i) = *(arr+i+1);
				*(arr + i + 1) = tmp;
				sorted = 0;
			}
		}
		for (i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}

int main() {
	int arr[] = { 2, 1, 3, 5 };
	bubblesort(arr, 4);
	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
}