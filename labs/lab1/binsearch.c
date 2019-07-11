#include <stdio.h>
#include <stdlib.h>

int binsearch (int *a, int n);

int main () {

	int aaaa[8] = {1, 5, 10, 15, 20, 25, 30, 35};

	printf("%d\n", binsearch(aaaa, 30));

	printf("%d\n", binsearch(aaaa, 7));

	return 0;

	}

int binsearch(int* a, int x) {
	int low, high, mid;

	low = 0;
	high = 8-1;

	while (low <= high) {
	
		mid = (low + high ) /2;
		if (x < a[mid]) 
			high = mid -1;
		else if (x> a[mid])
			low = mid+1;
		else 
			return mid;
		}
		return -1;
	}
