#include <stdio.h>

struct point {
	int xpos;
	int ypos;
};

struct circle{
	double radius;
	struct point*center;
};

int main() {
	struct point cen = { 2,7 };
	double rad = 5.5;

	/*
	struct circle ring;
	ring.center = &cen;
	ring.radius = rad;
	*/
	struct circle ring = { rad, &cen }; //위 세줄을 한번에 표현한 것이다.


	printf("원의 반지름 : %g \n", ring.radius);
	printf("원으 중심 [%d, %d] \n", (ring.center) -> xpos, (ring.center)->ypos);
	return 0;
}