#include <stdio.h>
int main() {
	int series; //입력받을 값
	scanf("%d", &series);
	int film = 6;

	bool six = true; //true -> 10, false -> 9
	int sixdigit = -1;
	int nosix = 0;

	if (series <= 6) {
		switch (series) {
		case 1:
			printf("%d", 666);
			return 0;
		case 2:
			printf("%d", 1666);
			return 0;
		case 3:
			printf("%d", 2666);
			return 0;
		case 4:
			printf("%d", 3666);
			return 0;
		case 5:
			printf("%d", 4666);
			return 0;
		case 6:
			printf("%d", 5666);
			return 0;
		default:
			break;
		}
	}

	while (film <= series) {
		if (six) {
			film += 10;
			sixdigit++;
		}
		else {
			film += 9;
			nosix++;
		}
		six = !six;
	}

	//printf("%d\n", film);

	if (!six) {
		if (sixdigit) {
			printf("%d", sixdigit);
		}
		printf("666%d", 9 - (film - series));
	}

	else {
		printf("%d666", film - (1 + 9 * nosix));
	}
	return 0;
}