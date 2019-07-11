#include <stdio.h>

int* insert(int*ss, int x) {
	int i;
	for (i = 0; i < 7; i++) {
		if (ss[i] > x)
			break;
	}

	for (int j = 6; j >= i; j--)
		ss[j + 1] = ss[j];
	ss[i] = x;
	return ss;
}

int main() {
	int ddd[10] = { 1, 3, 7, 8, 9, 10, 11};
	
	int* ptr = ddd;
	ptr = insert(ddd, 5);	

	for (int i = 0; i < 8; i++)
		printf("%d\n", ddd[i]);

	return 0;

}