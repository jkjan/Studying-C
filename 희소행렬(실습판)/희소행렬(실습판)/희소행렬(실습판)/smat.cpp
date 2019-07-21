#include "sparse.h"
#include <time.h>

int n;
int **matA;
int **matB;
int **matC;

int **matAT;
int **matBT;
int **matCT;

smatrix smatA;
smatrix smatB;
smatrix smatC;

smatrix smatAT;
smatrix smatBT;
smatrix smatCT;

extern void load(FILE *fpA, FILE *fpB);
extern int **transpose(int n, int **mat);
extern int **add(int n, int **matA, int **matB);
extern int **mult(int n, int **matA, int **matB);
extern void print(int**mat);

int main() {
	//1. load
	FILE *fpA = fopen("matA\\test.txt", "r+t");
	FILE *fpB = fopen("matB\\test2.txt", "r+t");

	load(fpA, fpB);
	//matA와 matB에 행렬이 저장
	fclose(fpA);
	fclose(fpB);

	printf("A : \n");
	print(matA);
	printf("B : \n");
	print(matB);

	//matA -> smatA, matB -> smatB
	smatA.convert_to_smatrix(n, matA);
	printf("sparse A : \n");
	smatA.print();
	for (int i = 0; i < smatA.n; i++) {
		printf("%d ", smatA.rowTerms[i]);
	}
	printf("\n");
	for (int i = 0; i < smatA.n; i++) {
		printf("%d ", smatA.startPos[i]);
	}
	printf("\n");
	printf("\n");

	smatB.convert_to_smatrix(n, matB);
	printf("sparse B : \n");
	smatB.print();
	for (int i = 0; i < smatB.n; i++) {
		printf("%d ", smatB.rowTerms[i]);
	}
	printf("\n");
	for (int i = 0; i < smatB.n; i++) {
		printf("%d ", smatB.startPos[i]);
	}
	printf("\n");
	printf("\n");

//2. transpose
	//2-1. ordinary transpose
	printf("transposed A : \n");
	matAT = transpose(n, matA);
	print(matAT);

	//2-2. fast transpose
	printf("transposed sparse A : \n");
	smatAT.fastTranspose(smatA);
	smatAT.print();

//3. add
	//3-1. ordinary add
	printf("A + B = \n");
	matC = add(n, matA, matB);
	print(matC);

	//3-2. fast add
	smatC.fastAdd(smatA, smatB);
	printf("sparse A + B = \n");
	smatC.print();

//4. multiply
	//4-1. ordinary multiply
	printf("A * B = \n");
	matC = mult(n, matA, matB);
	print(matC);

	//4-2. fast multiply
	//smatC.fastMult(smatA, smatB);
	printf("sparse A * B = \n");


	//5 time difference


	//system("pause");
	
	free(matA);
	free(matB);
	free(matC);
	free(smatA.list);
	free(smatB.list);
	free(smatA.rowTerms);
	free(smatB.rowTerms);
	free(smatA.startPos);
	free(smatB.startPos);

	return 0;
}