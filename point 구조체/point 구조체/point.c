#include <stdio.h>
#include "arrlist.h"
#include "point.h"

void set(Point *ppos, int x, int y) {
	ppos->xpos = x;
	ppos->ypos = y;
}

void show(Point *ppos) {
	printf("(%d, %d)", ppos->xpos, ppos->ypos);
}

int comp(Point *pos1, Point *pos2) {
	if ((pos1->xpos == pos2->xpos) && (pos1->ypos == pos2->ypos))
		return 3;
	else if (pos1->xpos == pos2->xpos)
		return 2;
	else if (pos1->ypos == pos2->ypos)
		return 1;
	else
		return 0;
}
