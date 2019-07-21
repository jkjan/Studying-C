#include "sparseMatrixStructure.h"
#include <cstdlib>

term* create(int **mat, int size, int max) {
	int b = 1;
	term *a = new term[max];
	a[0].row = a[0].col = size;
	a[0].value = max;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (mat[i][j] != 0) {
				a[b].row = i;
				a[b].col = j;
				a[b].value = mat[i][j];
				b++;
			}	
		}
	}
	return a;
}

int add(term* A, term* B, int size, int max) {
	term *C = new term[max];
	C[0].col = C[0].row = size;
	C[0].value = max;

	for (int i = 1; i < max; i++) {
		
	}
}