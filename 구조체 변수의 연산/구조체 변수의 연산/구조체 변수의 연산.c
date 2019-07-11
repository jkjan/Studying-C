#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
} Point;


SwapPoint(Point *p1, Point *p2) {
	Point *temp = p1;
	p1 = p2;
	p2 = temp;

}

main() {
	Point pos1 = { 2, 4 };
	Point pos2 = { 5, 7 };

	SwapPoint(&pos1, &pos2);

	printf("%d %d \n", pos1.xpos, pos1.ypos);
	printf("%d %d ", pos2.xpos, pos2.ypos);

	return 0;
}