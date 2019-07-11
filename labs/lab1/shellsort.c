#include <stdio.h>

void shellsort(int * a, int m);

int main () {

	int aa[] = {10, 9 ,8, 7, 6, 5, 4, 3, 2, 1};
	shellsort (aa, 10); 
	return 0;
	}

void shellsort ( int *v, int n) {

	int gap, i, j, temp;
	int cnt = 1;

	for (gap = n/2; gap > 0; gap /= 2) {
		for (i = gap; i< n; i++) {
			for (j = i-gap; j >=0 && v[j] > v[j+gap]; j-=gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
				

				printf("try %d : ", cnt);
				for (i = 0; i < n; i++)
					printf("%d ", *(v+i));
				printf("\n");
				cnt++;
				}
			}
		}
	for (i = 0; i < n; i++)
		printf("%d ", *(v+i));
	printf("\nsort complete!\n");
	}

