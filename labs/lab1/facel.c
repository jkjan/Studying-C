#include <stdio.h>

int main () {
	int fahr, celsius;            //data type , variable declaration
	int lower, upper, step;



	//assignments
	lower = 0;   // lower limit of temp table     <- comments
	upper = 300; // upper limit
	step = 20;  // step size

	fahr = lower;

	//loop
	while (fahr <= upper) {
		celsius =5*(fahr-32) /9;
		printf("%d\t%d\n", fahr, celsius);     // \t = tap	
		fahr += step;
	}

	return 0;
}
