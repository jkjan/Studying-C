#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {	

	//making a seed every single second
	srand(time(NULL));

	for (int i = 0; i < 4; i++) {
		//printing random numbers
		printf("%3d", rand() %10);
	}

	printf("\n");

	return 0;
}
