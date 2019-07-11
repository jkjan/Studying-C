#include <stdio.h>
#include <string.h>

void swap(int*a, int*b);


int main() {
	
	int i, j;

	int num = 10;

	int s[] = {5, 6, 2,4,1,6,10,9,8,11};
	do {
		int newn = 0;
		for (j = 0; j < num-1; j++) {
			if (s[j] > s[j+1]) {
				swap(s + j, s + j + 1);
				newn = 1;
			}
			
		}
		num = newn == 1 ? num-- : 0;
	} while (num != 0);
	
	for (i = 0; i < 10; i++)
		printf("%d ", *(s + i));
	}

void swap(int *a, int*b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}