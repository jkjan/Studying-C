#include <stdio.h>
#include <limits.h>

int main () {

	int i, j;

	for ( i = 1; i < INT_MAX; i++) {
		j = i;
		i = j;
	}

	printf("auto Done.\n");

	return 0;
}
