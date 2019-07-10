#include <stdio.h>
void main() {
	int wid;
	scanf("%d", &wid);

	int snail[5][5];
	int i, j, k, cnt;

	cnt = 1;

	for (k = 0; k < wid/2; k++) {
		for (i = k; i < wid - k; i++) {        //첫째줄 12345
			snail[k][i] = cnt;
			cnt++;
		}

		for (i = k+1; i < wid - k-1; i++) {  //오른쪽 56789
			snail[i][wid - k - 1] = cnt;
			cnt++;
		}

		for (i = wid - 1 - k; i > -1; i--) {      // 13 12 11 10 아래
			snail[wid - k - 1][i] = cnt;
			cnt++;
		}

		for (i = wid-k-2; i >0; i--) {  //왼쪽
			snail[i][k] = cnt;
			cnt++;
		}
	}

	for (i = 0; i < wid; i++) {
		for (j = 0; j < wid; j++) {
			printf("%d ", snail[i][j]);
		printf("\n");
		}
	}


}