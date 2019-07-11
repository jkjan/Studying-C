#include <stdio.h>
#include <limits.h> 

int main () {

	printf("signed char : %d ~ %d\n", CHAR_MIN, CHAR_MAX);
	printf("signed short : %d ~ %d\n", SHRT_MIN, SHRT_MAX);
	printf("signed int : %d ~ %d\n", INT_MIN, INT_MAX);
	printf("signed long : %ld ~ %ld\n", LONG_MIN, LONG_MAX);
	printf("\n\n");
	printf("unsigned char : %d ~ %d\n", 0, UCHAR_MAX);
	printf("unsigned short : %d ~ %d\n", 0, USHRT_MAX);
	printf("unsigned int : %d ~ %u\n", 0, UINT_MAX);
	printf("unsigned long : %d ~ %lu\n", 0, ULONG_MAX);
	
	return 0;
}
