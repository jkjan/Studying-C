
#include<stdio.h>
#include<stdlib.h>
#include<string.h> //To use the string functions like strcmp and strcpy

#define MAX 10  // This is the default size of every string 

void Merge(char* arr[], int low, int mid, int high) //Merging the Array Function
{
	int nL = mid - low + 1;
	int nR = high - mid;

	char** L = (char**)malloc(sizeof(char *)*nL);
	char** R = (char**)malloc(sizeof(char *)*nR);
	int i;

	for (i = 0; i < nL; i++){
		L[i] = (char*)malloc(sizeof(arr[low + i]));
		strcpy(L[i], arr[low + i]);
	}

	for (i = 0; i < nR; i++) {
		R[i] = (char*)malloc(sizeof(arr[mid + i + 1]));
		strcpy(R[i], arr[mid + i + 1]);
	}

	int j = 0;
	int k;
	i = 0;
	k = low;

	while (i < nL&&j < nR) {
		if (strcmp(L[i], R[j]) < 0)
			strcpy(arr[k++], L[i++]);
		else 
			strcpy(arr[k++], R[j++]);
	}
	
	while (i < nL)
		strcpy(arr[k++], L[i++]);
	while (j < nR)
		strcpy(arr[k++], R[j++]);

}


void MergeSort(char* arr[], int low, int high) //Main MergeSort function
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		Merge(arr, low, mid, high);
	}
}


int main()
{
	int i;
	int size=10;  //This is the String array size
	
	char*arr[] = { "kim", "lee", "park", "choi", "jung", "kang", "cho",
			 "yoon", "chang", "yim" }; //Creating required string array
	
	MergeSort(arr, 0, size - 1);
	for (i = 0; i < size; i++)
		printf("%s ->", arr[i]);
	return 0;
}
