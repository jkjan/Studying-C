#include "poly.h"
#include <math.h>

void poly::add(poly* A, poly* B) {
	this->zero();

	hang* curA = A->head->next;
	hang* curB = B->head->next;

	while (curA != NULL && curB != NULL) {
		if (curA->exp > curB->exp) {
			this->insert(curA->coef, curA->exp);
			curA = curA->next;
		}

		else if (curA->exp == curB->exp) {
			if (curA->coef + curB->coef != 0)
				this->insert(curA->coef + curB->coef, curA->exp);
			curA = curA->next;
			curB = curB->next;
		}

		else {
			this->insert(curB->coef, curB->exp);
			curB = curB->next;
		}
	}

	while (curA != NULL) {
		this->insert(curA->coef, curA->exp);
		curA = curA->next;
	}
	
	while (curB != NULL) {
		this->insert(curB->coef, curB->exp);
		curB = curB->next;
	}
	
	this->degree = this->head->next->exp;
}

void poly::multi(poly* A, poly *B) {
	this->zero();
	hang*curA = A->head->next;
	hang*curB = B->head->next;

	while (curA != NULL) {
		while (curB != NULL) {
			if (curA->coef * curB->coef != 0)
				this->insert(curA->coef * curB->coef, curA->exp + curB->exp);
			curB = curB->next;
		}

		curA = curA->next;
		curB = B->head->next;
	}

	this->degree = this->head->next->exp;
}

void poly::pprint() {
	hang * cur = this->head->next;
	
	if (this->isZero()) {
		printf("0\n\n");
		return;
	}

	while (cur != NULL) {
		if (cur->coef != 0) {
				if (cur->coef < 0) {
					if (cur->exp == this->leadExp())
						printf("-");
					else
						printf(" - ");
				}
				if (abs(cur->coef) != 1)
					printf("%d", abs(cur->coef));

			if (cur->exp != 0) {
				printf("x");

				if (cur->exp < 0)
					printf("^(%d)", cur->exp);

				else if (cur->exp != 1)
					printf("^%d", cur->exp);
			}
		}

		if (cur->next != NULL && cur->next->coef > 0)
			printf(" + ");

		cur = cur->next;
	}
	printf("\n\n");
}