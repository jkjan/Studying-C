#ifndef point
#define point

typedef struct p {
	int xpos;
	int ypos;
} Point;

void set(Point *ppos, int xpos, int ypos);
void show(Point *ppos);
int comp(Point *pos1, Point *pos2);

#endif
#pragma once
