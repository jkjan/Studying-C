#include <stdio.h>
#include <stdlib.h>

double realadd(double a, double c);
double realmult(double a, double b, double c, double d);
double fakeadd(double b, double d);
double fakemult(double a, double b, double c, double d);

typedef struct complex {
	double real;
	double fake;
} comp;

int main() {
	int i;
	comp *p;
	p = (comp*)malloc(sizeof(comp) * 2);

	double rd, rm, fd, fm;


	for (i = 0; i < 2; i++) {
		printf("복소수 %d (실수부 허수부)입력 : ", i+1);
		scanf("%f %f", &((p + i)->real), &((p + i)->fake));
	}

	puts("\n");
	
	rd = (p->real) + ((p + 1)->real);
	rm = realmult((p->real), (p->fake), ((p + 1)->real), ((p + 1)->fake));
	fd = (p->fake) + ((p + 1)->fake);
	fm = fakemult((p->real), (p->fake), ((p + 1)->real), ((p + 1)->fake));
	
	puts("결과 출력");
	
	printf("복소수의 합 \n");
	printf("실수부 : %.2f    허수부 : %.2f\n", rd, fd);
	printf("복소수의 곱 \n");
	printf("실수부 : %.2f    허수부 : %.2f\n", rm, fm);
	

	free(p);

	return 0;

}

double realadd(double a, double c) {
	return (a + c);
}

double realmult(double a, double b, double c, double d) {
	return (a * c - b * d);
}

double fakeadd(double b, double d) {
	return (b + d);
}

double fakemult(double a, double b, double c, double d) {
	return (b * c + a * d);
}
