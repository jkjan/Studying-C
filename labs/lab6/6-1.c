#include <stdio.h>
#include <math.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))



int main () {

	typedef struct _point {
		int x;
		int y;		
	} point;

	point p1 = {10, 20};  
	point p2 = {30, 40};

	int distance  = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2)); // root((a-b)^2 + (c-d)^2)

	printf("%d\n", distance);

	typedef struct _rect {
		point r1;
		point r2;
	} rect;

	rect pa;

	pa.r1.x = min(p1.x, p2.x);  //rect r1 has to be the min value of points
	pa.r1.y = min(p1.y, p2.y);
	pa.r2.x = max(p1.x, p2.x);  //rect r2 has to be the max value of points
	pa.r2.y = max(p1.y, p2.y);

	int width = (pa.r2.x - pa.r1.x) * (pa.r2.y - pa.r1.y);  // (a-b) * (c-d)

	printf("%d\n", width);
	
	return 0;
}
	
