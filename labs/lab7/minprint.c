#include <stdarg.h>
#include <stdio.h>

void minprintf(char *fmt, ...) {
	va_list ap;   //to declare a variable that  will refer to each argument in turn

	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);  //to initialize ap to point to the  first unnamed argument
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch(*++p) {
		case 'd' :
			ival = va_arg(ap, int);  //to return one argument and  steps argument pointer to the next
			printf("%d", ival);
			break;
		case 'f' :
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's' :
			for (sval = va_arg(ap, char*); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap); //clean up
}

int main () {
	minprintf("integer: %d\n", 10);
	minprintf("float print: %f\n", 10.1);
	minprintf("string print: %s\n", "Hello World");

	return 0;
}

