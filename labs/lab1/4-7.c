#include <stdio.h>

//swapping elem
void swap(double v[], int i, int j){
    double temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
 
void qsort(double v[], int left, int right){
	int i, last;
	void swap(double v[], int i, int j);
	
	if (left >= right)        // do nothin if array contains
		return;                           // fewer than two elem
	swap(v, left, (left + right)/2);                 // move partition elem
	last = left;                                     // to v[0]
	for (i = left+1; i<= right; i++)                 // partition
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);         //restore partition elem

	//recursive call and make it repeat till we got sorted array
	qsort(v, left, last-1);
	qsort(v, last+1, right);
    
}
 
int main(void){
 
    double f[] = {1.1, 9.9, 2.2, 8.8, 3.3, 7.7, 4.4, 6.6, 5.5, 0.0} ;
    int i;

    //print out f[]
    for(i=0; i<10; i++){
        printf("%g ",f[i]);
    }

	printf("\n");
 
    qsort(f, 0, 9);
 
    //print out sorted f[]
    for(i=0; i<10; i++){
        printf("%g ",f[i]);
    }

	printf("\n");
 
    return 0;
}
