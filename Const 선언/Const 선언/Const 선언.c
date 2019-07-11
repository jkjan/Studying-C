#include <stdio.h>
void main() {
	const double PI = 3.1415; //프로그램 중 절대로 바뀔 리 없는 상수 선언.
	double r;
	PI = 33.3; //컴파일조차 안 됨. 오류 방지.
	scanf("%lf", &r);
	printf("circle area %f \n", r*r*PI);
	return 0;
}