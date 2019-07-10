#include <stdio.h>
void main() {
	int arr[][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	int cnt, i, j;

	scanf("%d", &cnt);

	if (cnt % 4 == 0) {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++)
				printf("%2d ", arr[i][j]);
			printf("\n");
		}
	}

	else if (cnt % 4 == 1) {
		for (i = 0; i < 4; i++) {
			for (j = 3; j > -1; j--)
				printf("%2d ", arr[j][i]);
			printf("\n");
		}
	}

	else if (cnt % 4 == 2) {
		for (i = 3; i > -1; i--) {
			for (j = 3; j >= 0; j--)
				printf("%2d ", arr[i][j]);
			printf("\n");
		}
	}


	else if (cnt % 4 == 3) {
		for (i = 3; i > -1; i--) {
			for (j = 0; j < 4; j++)
				printf("%2d ", arr[j][i]);
			printf("\n");
		}
	}

return 0;

}