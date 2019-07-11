#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand((int)time(NULL));

	int comp, user;
	int draw = 0, win = 0, result = 0;
	
	printf("가위 = 0, 바위 = 1, 보 = 2 \n");


	while (result != 1) {
		comp = rand() % 2;
		scanf("%d", &user);

		if (user == comp) {
			printf("무승부\n\n");
			draw += 1;
		}

		else if ((user == 0 && comp == 2) || (user == 1 && comp == 0) || (user == 2 && comp == 1)) {
			printf("이겼습니다.\n\n");
			win += 1;
		}

		else
			result += 1;
	}

	printf("수고하셨습니다. \n전적 : %d승 %d무", win, draw);

}