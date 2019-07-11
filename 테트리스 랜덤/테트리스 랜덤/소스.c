#include <time.h>
#include <stdio.h>
#include <Windows.h>

int x = 35;
int y = 0;
int r = 0;

char i_block[4][4][4] = {
			 1, 1, 1, 1,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
			 0, 0, 0, 1,  0, 0, 0, 1,  0, 0, 0, 1,  0, 0, 0, 1,
			 0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  1, 1, 1, 1,
			 1, 0, 0, 0,  1, 0, 0, 0,  1, 0, 0, 0,  1, 0, 0, 0
};

char t_block[4][4][4] = {
			1, 0, 0, 0,  1, 1, 0, 0,  1, 0, 0, 0,  0, 0, 0, 0,
			1, 1, 1, 0,  0, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
			0, 0, 1, 0,  0, 1, 1, 0,  0, 0, 1, 0,  0, 0, 0, 0,
			0, 0, 0, 0,  0, 1, 0, 0,  1, 1, 1, 0,  0, 0, 0, 0
};

char s_block[4][4][4] = {
			1, 0, 0, 0,  1, 1, 0, 0,  0, 1, 0, 0,  0, 0, 0, 0,
			0, 1, 1, 0,  1, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
			0, 1, 0, 0,  0, 1, 1, 0,  0, 0, 1, 0,  0, 0, 0, 0,
			0, 0, 0, 0,  0, 1, 1, 0,  1, 1, 0, 0,  0, 0, 0, 0
};

char z_block[4][4][4] = {
			0, 1, 0, 0,  1, 1, 0, 0,  1, 0, 0, 0,  0, 0, 0, 0,
			1, 1, 0, 0,  0, 1, 1, 0,  0, 0, 0, 0,  0, 0, 0, 0,
			0, 0, 1, 0,  0, 1, 1, 0,  0, 1, 0, 0,  0, 0, 0, 0,
			0, 0, 0, 0,  1, 1, 0, 0,  0, 1, 1, 0,  0, 0, 0, 0
};

char l_block[4][4][4] = {
			1, 0, 0, 0,  1, 0, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,
			1, 1, 1, 0,  1, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
			0, 1, 1, 0,  0, 0, 1, 0,  0, 0, 1, 0,  0, 0, 0, 0,
			0, 0, 0, 0,  0, 0, 1, 0,  1, 1, 1, 0,  0, 0, 0, 0
};

char j_block[4][4][4] = {
			0, 1, 0, 0,  0, 1, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,
			1, 0, 0, 0,  1, 1, 1, 0,  0, 0, 0, 0,  0, 0, 0, 0,
			1, 1, 0, 0,  1, 0, 0, 0,  1, 0, 0, 0,  0, 0, 0, 0,
			1, 1, 1, 0,  0, 0, 1, 0,  0, 0, 0, 0,  0, 0, 0, 0
};

char o_block[4][4][4] = {
			1, 1, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
			1, 1, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
			1, 1, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
			1, 1, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
};
/*
char*** blockGenerator() {
	srand(time(NULL));
	int what = rand()%7;
	switch (what) {
	case 0:
		return i_block;
	case 1:
		return t_block;
	case 2:
		return s_block;
	case 3:
		return z_block;
	case 4:
		return l_block;
	case 5:
		return z_block;
	case 6:
		return o_block;
	}
}
*/
void gotoxy(int x, int y) {
	printf("\033[%d;%df", y, x);
	fflush(stdout);
}

void print_shape(char m[4][4][4]) {
	int i, j;

	for (i = 0; i < 4; i++) {
		gotoxy(x, y+i);
		for (j = 0; j < 4; j++) {
			if (m[r][i][j] == 1)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
	system("cls");
}

int blockbox(char ***m) {
	int key;
	while (y < 25) {
		system("cls");
		//print_direction();
		print_shape(m);
		if (kbhit()) {
			key = getch();
			switch (key) {
			case 'w':
				//printf("up\n");
				r = (r == 3 ? 0 : r + 1);
				//y -= 1;
				//move_shape(i_block);
				//print_shape(i_block);
				Sleep(100);
				break;
			case 'a':
				//printf("left\n");
				x += -1;
				y += 0;
				//mvprintw(10, 10, "a pressed");
				//print_shape(i_block);
				//move_shape(i_block);
				break;
			case 'd':
				//printf("right\n");
				x += 1;
				y += 0;
				//print_shape(i_block);
				//move_shape(i_block);
				break;
			case 's':
				y += 1;
				//print_shape(i_block);
				//move_shape(i_block);
				//printf("down\n");
				break;
			default:
				break;
			}
		}
	}
}

int main() {
	while (1) {
		blockbox(z_block);
	}
}

