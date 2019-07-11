#include "head.h"
#define maxval 100

int sp = 0;
double val[maxval];

void push(double f) {
	if (sp < maxval)
		val[sp++] = f;
	else
		printf("error : stack full, can't push %g\n", f);
}

double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error : stack empty\n");
		return 0.0;
	}
}