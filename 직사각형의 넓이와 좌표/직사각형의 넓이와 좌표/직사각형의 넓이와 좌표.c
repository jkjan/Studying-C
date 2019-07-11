#include <stdio.h>
typedef struct sqp {
	int xpos;
	int ypos;
} pos;

typedef struct rec {
	pos leftupper;
	pos rightunder;
} rect;

int width(rect *a) {
	return ((a->rightunder).xpos - (a->leftupper).xpos)*
		((a->rightunder).ypos - (a->leftupper).ypos);
}

int showposition(rect *a) {
	printf("(%d, %d), ", (a->leftupper).xpos, (a->leftupper).ypos);
	printf("(%d, %d), ", (a->leftupper).xpos, (a->rightunder).ypos);
	printf("(%d, %d), ", (a->rightunder).xpos, (a->leftupper).ypos);
	printf("(%d, %d)", (a->rightunder).xpos, (a->rightunder).ypos);
}

int main() {
	rect a = { {0,0}, {100,100} };
	printf("≥–¿Ã : %d", width(&a));
	printf("\n");
	showposition(&a);
}