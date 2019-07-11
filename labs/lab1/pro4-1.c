#include <stdio.h>

//declaring functions
int max(int i, int j, int k);
int min(int i, int j, int k);

//commanding what to do
int main () {
	int i = 10;
	int j = 20;
	int k = -30;
	
	printf("Min value is %d\n", max(i, j, k));
	printf("Max value is %d\n", min(i, j, k));

	return 0;
}

//finding max value
int max(int i, int j, int k) {
	int max;
	
	//comparing i with j, and saving the bigger one into max
	max = i > j ? i : j;

	//repeating with max and k
	max = max > k ? max : k;

	//the maximum of i j and k
	return max;
}

//finding min value
int min(int i, int j, int k) {
	int min;

	//comparing i with j, and saving the smaller one into max
	min = i < j ? i : j;

	//repeating with max and k
	min = min < k ? min : k;

	//the maximum of i j and k
	return min;
}



