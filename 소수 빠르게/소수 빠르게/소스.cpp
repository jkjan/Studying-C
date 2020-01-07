#include <iostream>
#include <cstdlib>

int main() {
	int a, b, i;
	scanf("%d %d", &a, &b);
	//t = b - a + 1;
	
	int * arr = new int[b + 1];

	int d = 2;

	for (i = 0; i < b + 1; i++) {
		arr[i] = i;
	}

	if (arr[1] == 1)
		arr[1] = 0;

	while (d <= b) {
		//printf("%d\n", d);
		for (i = a; i <= b; i++) {
			if (arr[i] != 0 && i != d) {
				//printf("%d »èÁ¦\n", i);
				arr[i] = 0;
			}
		}

		//printf("\n");
		d++;
	}

	for (i = a; i <= b; i++)
		if (arr[i] != 0)
			printf("%d\n", arr[i]);

	delete(arr);
	return 0;
}