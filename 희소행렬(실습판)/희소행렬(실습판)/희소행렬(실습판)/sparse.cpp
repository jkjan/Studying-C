#include "sparse.h"

void smatrix::print() {
	for (int i = 0; i < this->cnt; i++){
		printf("%2d | %2d %2d %2d\n", i, this->list[i].row, this->list[i].col, this->list[i].val);
	}
	printf("\n");
}

void smatrix::setList(int i, int row, int col, int val) {
	this->list[i].row = row;
	this->list[i].col = col;
	this->list[i].val = val;
}

void smatrix::makeRowTerms() {
	int i;
	this->rowTerms = (int*)malloc(sizeof(int)*this->n);

	for (int j = 0; j < this->n; j++)
		this->rowTerms[j] = 0;

	for (i = 1; i < this->cnt; i++) {
		this->rowTerms[this->list[i].col]++;
	}
}

void smatrix::makeStartPos() {
	int i;
	this->startPos = (int*)malloc(sizeof(int)*this->n);

	this->startPos[0] = 1;
	for (i = 1; i < this->n; i++)
		this->startPos[i] = this->startPos[i - 1] + this->rowTerms[i - 1];
}

void smatrix::convert_to_smatrix(int n, int **mat) {
	int i, j;
	int b = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mat[i][j] != 0) {
				b++;
			}
		}
	}

	this->list = (element*)malloc(sizeof(element)*(b + 1));
	this->list[0].row = this->list[0].col = n;
	this->list[0].val = b;

	b = 1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mat[i][j] != 0) {
				this->setList(b, i, j, mat[i][j]);
				b++;
			}
		}
	}
	this->n = n;
	this->cnt = b;
	this->makeRowTerms();
	this->makeStartPos();
}

void smatrix::fastTranspose(smatrix mat) {
	int i, j;

	this->list = (element*)malloc(sizeof(element)*(mat.cnt));
	this->setList(0, mat.n, mat.n, mat.cnt - 1);

	for (i = 1; i < mat.cnt; i++) {
		j = mat.startPos[mat.list[i].col]++;
		this->setList(j, mat.list[i].col, mat.list[i].row, mat.list[i].val);
	}

	this->n = n;
	this->cnt = mat.cnt;
	this->makeRowTerms();
	this->makeStartPos();
}

void smatrix::fastAdd(smatrix matA, smatrix matB) {
	int i;
	this->list = (element*)malloc(sizeof(element)*(matA.n*matA.n));
	int sA, sB;
	sA = sB = 1;
	int sC=1;
	int arow, brow, acol, bcol, aval, bval;
	while((sA<matA.cnt) && (sB<matB.cnt)) {
		arow = matA.list[sA].row;
		brow = matB.list[sB].row;
		acol = matA.list[sA].col;
		bcol = matB.list[sB].col;
		aval = matA.list[sA].val;
		bval = matB.list[sB].val;

		if (arow > brow) {
			this->setList(sC, brow, bcol, bval);
		}

		else if (arow == brow) {
			if (acol > bcol) {
				this->setList(sC, brow, bcol, bval);
				sB++;
			}
			else if (acol == bcol) {
				this->setList(sC, brow, bcol, aval + bval);
				sA++;
				sB++;
			}
			else {
				this->setList(sC, arow, acol, aval);
				sA++;
			}
		}

		else {
			this->setList(sC, arow, acol, aval);
			sA++;
		}

	sC++;
	}

	this->setList(0, matA.n, matA.n, sC - 1);
	this->n = matA.n;
	this->cnt = sC;
}

void smatrix::fastMult(smatrix matA, smatrix matB) {
	this->list = (element*)malloc(sizeof(matA.cnt*matA.cnt));
	smatrix matBT;
	matBT.fastTranspose(matB);

	int sC = 1;
	int curR = 0;
	int curC = 0;
	int sum = 0;		
	int found = 1;

	while (matBT.list[curC].col != matA.list[curR].col) {
		curC++;
		if (curC > matA.n) {
			curC = 0;
			found = 0;
			break;
		}
	}

	if (found == 1) {
		sum += matBT.list[curC].val * matA.list[curR].val;
	}
	

	setList(sC, curR, curC, sum);

}