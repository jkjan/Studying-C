#include <stdio.h>
void main() {

	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	int *fptr = &arr[0];
	int *bptr = &arr[5];
	int temp[1];
	int i;
	int *tpr = temp;

	for (i = 0; i < 3; i++) {
		*tpr = *fptr;
		*fptr = *bptr;
		*bptr = *tpr;
		fptr++;
		bptr--;
	}

	for (i = 0; i < 6; i++) {
		printf("%d", arr[i]);
	}

}