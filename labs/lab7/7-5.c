#include <stdio.h>
#include <ctype.h> 

int main () {
	char c;

	int alpha = 0;
	int big = 0;
	int small = 0;
	int num = 0;

	while ((c = getchar())!= EOF) {
		if (isalpha(c))
			alpha++;               //if it is an alphabet
		if (isupper(c))
			big++;                 //if it is a big character
		if (islower(c))
			small++;               //if it is a small character
		if (isdigit(c))
			num++;                 //if it is a number
		if (c == '\n') {
			printf("alphabets = %d, big characters = %d,\n",alpha, big); 
			printf("small characters = %d, numbers = %d\n\n", small, num);
			alpha = big = small = num = 0;
			}
	}

	return 0;
}
