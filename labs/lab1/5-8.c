#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick(void *s[], int l, int r, int(*comp)(void *, void *)); 
void swap(void *s[], int a, int b);
int numcmp(char*a, char*b);

int main (int argc, char *argv[] ) {

	int num = 0;

	if (strcmp(*(++argv), "-n") == 0)
		 num = 1;

	char **what = (char**)malloc(sizeof(char*)*(argc-1-num));

	for (int i = 0; i < argc-1; i++)
		*(what+i) = (char*)malloc(sizeof(char)*100);

	for (int i = 0; i < argc - 1-num; i++)
		strcpy(*(what+i), *(argv+num+i));

	quick((void**)what, 0, argc-2, (int(*)(void*, void*))(num ? numcmp : strcmp));

	for (int i = 0; i < argc-1-num; i++)
		printf("%s ", *(what+i+num));

	printf("            %d %d\n", num, argc-1-num);

	return 0;
}

void quick(void *s[], int l, int r, int(*comp)(void *, void *)) {

	int i, last;
	void swap(void *s[], int, int);

	if (l >= r)
		return;
	swap(s, l, (l+r)/2);

	last = l;

	for (i = l + 1; i <= r; i++)
		if ((*comp)(s[i], s[l]) < 0)
			swap(s, ++last, i);
	swap(s, l, last);
	quick(s, l, last-1, comp);
	quick(s, last+1, r, comp);
}

void swap(void *s[], int a, int b) {
	char *temp;
	temp = *(s+a);
	*(s+a) = *(s+b);
	*(s+b) = temp;
}

int numcmp(char*a, char*b) {
	double a1, b2;

	a1 = atof(a);
	b2 = atof(b);
	
	if (a1 > b2)
		return 1;
	else if (a1 < b2)
		return -1;
	else
		return 0;
}
	
