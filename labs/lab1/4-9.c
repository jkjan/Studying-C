#include <stdio.h>

#define NUM int
#define OUT printf
#define PI 3.14
#define SQ(X) ((X)*(X))

NUM main () {
	NUM a, b, c;
	a = (NUM)PI;
	b = 25;
	c = a + b;
	OUT("Result %d\n", SQ(c));
	return 0;
}
