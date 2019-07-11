#include <stdio.h>
int main () { 
	double i;

	//i starts with 0, increases 20 everytime, up to 300
	for (i = 0; i<=300; i+=20) {
		printf("cel : %3.0f\tfah : %6.1f\n", i, 1.8*i+32);
		//print i
	}

	return 0;
}
