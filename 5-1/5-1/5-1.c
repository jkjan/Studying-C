#include <stdio.h>

int main() {
	int a[] = {1, 2, 3, 4, 5}
	;
	int *p = a;
	int i;

	//printf with a[i] and for()
	for (i = 0; i < 5; i++) 
		printf("%d ", a[i]);    //printing a's elements of its ith index
	
	printf("\n");
	i = 0;

	//printf with p and while()
	while (i < 5) {
		printf("%d ", *p);
		p++;    //to show that this printf is using pointer access method
		i++;    //to give an ending condition
	}

	return 0;

}