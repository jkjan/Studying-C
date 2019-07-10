#include <stdio.h>

void swap(int *a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int split(int s, int e, int*a) {
	int p = s;
	s++;
	
	while (s <= e) {
		while (s <= e && a[s] <= a[p])
			s++;
		while (s <= e && a[e] >= a[p])
			e--;
		if (s <= e)
			swap(&a[s], &a[e]);
	}
	swap(&a[p], &a[e]);

	for (int i = 0; i < 7; i++)
		printf("%d ", a[i]);
	printf("\n");

	return e;
}

void quicksort(int s, int e, int* a) {
	if (s >= e)
		return;

	int m = split(s, e, a);
	quicksort(s, m-1, a);
	quicksort(m + 1, e, a);

	

}

void main() {
	int arr[] = { 5, 3, 5, 1, 2, 1, 4 };
	quicksort(0, 6, arr);
	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);
}