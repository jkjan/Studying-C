#include "arggg.h"


void quick(void *s[], int l, int r, int(*comp)(void *, void *)) {

	int i, last;
	void swap(void *s[], int, int);

	if (l >= r)         //if dividing is impossible
		return;     //end sorting 
	swap(s, l, (l+r)/2);

	last = l;

	for (i = l + 1; i <= r; i++)           //sort divided part
		if ((*comp)(s[i], s[l]) < 0)
			swap(s, ++last, i);
	swap(s, l, last);          
	quick(s, l, last-1, comp);   //left part 
	quick(s, last+1, r, comp);   //right part
}

void swap(void *s[], int a, int b) {
	char *temp;
	temp = *(s+a);       //swapping pointers
	*(s+a) = *(s+b);
	*(s+b) = temp;
}

int numcmp(char*a, char*b) {         //numcmp, comparing numbers
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

