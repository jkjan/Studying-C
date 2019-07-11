#include <stdio.h>

int s() {
	static int i = 10;
	i+=10;
	return i;
}


int main () {
	printf("%d\n", s());
	printf("%d\n", s());	

	return 0;
}
