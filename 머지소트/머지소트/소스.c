#include <stdio.h>

void merge(int ss, int se, int es, int ee,  int* a) {
	int * merging = (int*)malloc(sizeof(int)*(se-ss+ee-es+2));

	int lp = ss;
	int rp = es;
	int bp = 0;

	while (lp <= se && rp <= ee) {
		if (a[lp] > a[rp])
			merging[bp++] = a[rp++];
		else
			merging[bp++] = a[lp++];
	}

	if (lp > se)
		for (int i = rp; i <= ee; i++)
			merging[bp++] = a[i];
	if (rp > ee)
		for (int i = lp; i <= se; i++)
			merging[bp++] = a[i];

	for (int i = 0; i < se - ss + ee - es + 2; i++)
		a[i+ss] = merging[i];
}

void mergesort(int s, int e, int*a) {
	if (s == e)
		return;

	int m = (s + e) / 2;

	mergesort(s, m, a);
	mergesort(m + 1, e, a);
	for (int i = s; i<=e; i++)
		printf("%d ", a[i]);
	printf("\n");

	merge(s, m, m+1, e, a);
	for (int i = s; i <= e; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void main() {
	int arr[] = { 2, 1, 5, 3 };
	mergesort(0, 3, arr);
	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
}