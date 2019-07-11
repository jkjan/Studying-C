#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
} Point;

typedef struct circle {
	Point cen;
	double rad;
} Circle;

void ShowCircleInfo(Circle *cptr) {
	printf("%d, %d \n", (cptr->cen).xpos, (cptr->cen).ypos);
	printf("%g \n", cptr->rad);
}

int main() {
	Circle c1 = { {1,2}, 3.5 };
	Circle c2 = { {2,3}, 5 };
	ShowCircleInfo(&c1);
	ShowCircleInfo(&c2);

	return 0;
}