#include <stdio.h>
void shellsort(int v[], int n);

int main() {
	int s[] = { 12, 73, 4, 41, 22, 71, 2, 68, 100, 35 };

	int i;
	int m = sizeof(s) / sizeof(int); //the total number of the array elements

	for (i = 0; i < m; i++) 
		printf("%4d", s[i]);
	putchar('\n');

	shellsort(s, m);
	for (i = 0; i < m; i++)
		printf("%4d", s[i]);
	putchar('\n');

	return 0;

}


void shellsort(int v[], int n) {
	int gap, i, j, temp;

	for ( gap = n/2; gap > 0; gap /=2) 
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
}