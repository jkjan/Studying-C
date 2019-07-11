
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void mergeSort(char** data, int p, int r);
void merge(char** data, int p, int q, int r);

int main() {
	//initializing a string array
	char*s[] = { "kim", "lee", "park", "choi", "jung", "kang", "cho", "yoon",
				"chang", "yim" }; 
	int i;
	printf("before sort\n");
	for (i = 0; i < 10; i++) {
		printf("%s ", s[i]);
	}

	mergeSort(s, 0, 9);
	
	printf("\n\nnow sorted\n");
	for (i = 0; i < 10; i++) {
		printf("%s ", s[i]);
	}
	return 0;
}
void mergeSort(char** data, int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;

		//recursive call
		mergeSort(data, p, q);
		
		mergeSort(data, q + 1, r);
		
		merge(data, p, q, r);
		
	}
}
void merge(char** data, int p, int q, int r) {
	int i = p, j = q + 1, k = p;
	char **tmp = (char**)malloc(sizeof(char*)*10);// new temp array

	//i and j are splitted , i starting from the beginning and j from the middle
	while (i <= q && j <= r) {

		//saving smaller one into temp
		if (strcmp(data[i], data[j]) < 0) {
			*(tmp+k)= *(data+i);
			k++;
			i++;
		}
		else {
			*(tmp+k)= *(data+j);
			k++;
			j++;
		}
	}

	//saving the rest of strings into temp
	while (i <= q) {
		*(tmp+k)= *(data+i);
		k++;
		i++;
	}

	//saving the rest of strings into temp
	while (j <= r) {
		*(tmp + k)= *(data + j);
		k++;
		j++;
	}

	for (int a = p; a <= r; a++) 
		*(data+a)= *(tmp+a);
}
