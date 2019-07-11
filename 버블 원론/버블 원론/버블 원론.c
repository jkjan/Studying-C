#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int *arr, int n) {
	int temp;
	int cnt = 0;
	for (int c = n - 1; c > 0; c--) {
		int *f = &arr[0];
		int *b = &arr[1];

		for (int i = 0; i < c; i++) {
			if (*f >= *b) {
				temp = *f;
				*f = *b;
				*b = temp;
			}
			f++;
			b++;
			cnt++;
		}
	}

	printf("%d\n", cnt);
}

int main() {
	int len=1;
	int i;
	int* super = (int*)malloc(sizeof(int)*len);
	srand((int)time(NULL));
	for (len = 5; len < 1000; len++) {
		for (i = 0; i < len; i++) {
			super = (int*)realloc(super, sizeof(int)*len);
			*(super + i) = rand() % 99;
		}

		bubblesort(super, len);
	}

	/*for (i = 0; i < len; i++) {
		printf("%d ", *(super + i));
	}*/

	//printf("\n\n%d", bubblesort(super, len));
	free(super);

}