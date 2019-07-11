#include <stdio.h>

int main () {
	float fahr, celsius;            //data type , variable declaration
	int lower, upper, step;



	//assignments
	lower = 0;   // lower limit of temp table     <- comments
	upper = 300; // upper limit
	step = 20;  // step size

	fahr = lower;

	//loop
	while (fahr <= upper) {
		celsius =(5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);     // \t = tap	
		fahr += step;
	}

	return 0;
}
