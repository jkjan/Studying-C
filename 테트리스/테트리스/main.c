#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

int x = 35, y = 0;

int inx = 0, iny = 0;
int r = 0;

char board[26][17] = {
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,

		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,

		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,

		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1



};

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

 void gotoxy(int x, int y) {
	 printf("\033[%d;%df", y, x);
	 fflush(stdout);
 }

 void print_direction(void){
	 gotoxy(25, 1);

	 printf("%d %d", x, y);
}

void print_shape(char m[4][4][4]) {
	int i, j;
	for (i = 0; i < 4; i++) {
		gotoxy(x, y + i);
		for (j = 0; j < 4; j++) {
			if (m[r][i][j] == 1)
				printf("бр");
			else
				printf("  ");
		}
		printf("\n");
	}
	system("cls");
}

void print_board(char b[][17]) {
	int i, j;
	int u=5;

	system("cls");

	for (i = 0; i < 26; i++) {
		gotoxy(34, u++);
		for (j = 0; j < 17; j++) {
			if (b[i][j] == 1)
				printf("бс");
			else
				printf("  ");
		}
		printf("\n");
	}

	Sleep(100);
}

void move_shape(char m[4][4][4]) {
	do {
		system("cls");
		//print_shape(m);
		print_direction();
		//x = x + inx;
		//y = y + iny;

		if (board[y][x]== 0) 
			board[y][x] = 1;

		if (y >= 25) {
			//_endthread();
			y = 25;
		}
		
		if (x > 75)
			x = 75;
		else if (x < 1)
			x = 1;
		Sleep(100);
	} while (!kbhit());
}

unsigned _stdcall Thread_yDown(void *arg) {
	while (y < 25) {
		y++;
		Sleep(1000);
	}
}

int createbox(char ***m) {
	_beginthreadex(NULL, 0, Thread_yDown, 0, 0, NULL);

	int key;
	int i = 0;
	do {
		while (!kbhit()) {
			//printf("%d %d", x, y);
			system("cls");
			move_shape(m);
		}
		
		key = getch();
		if (key == 224 || key == 0) {
			key = getch();
			switch (key) {
				case 72:
					//printf("up\n");
					r = (r == 3 ? 0 : r + 1);
					move_shape(m);
					//Sleep(100);
					break;
				case 75:
					//printf("left\n");
					x += -1;
					y += 0;
					move_shape(m);
					break;
				case 77:
					//printf("right\n");
					x += 1;
					y += 0;
					move_shape(m);
					break;
				case 80:
					y += 5;
					move_shape(m);
					//printf("down\n");
					break;
				default:
						break;
			}
		}		
	} while (y <= 25);

	gotoxy(10, 5);
	printf("end");
	y = 0;
	return 0;
}

/*
int refresh(int signum) {
	static int downcount = 0;
	static int etcount = 0;
	static long speedcount = 0;
	static int countrange = 5;
	static int firststart = 0;

	char ch; 

	srand((unsigned)time(NULL));
	if (firststart == 0) {
		block_number = rand() % 7;
		if (firststart == 0)
	}
}
*/

int main() {
	int key;
	srand(time(NULL));

	gotoxy(10, 20);
	//printf("%d", what);

	int what = rand()%7;
	/*
	for (int i = 0; i < 1118; i++) {
		if ((i + 1) % 43 == 0 || i % 43 == 0)
			**(board + i) = 'b';
		else
			**(board + i) = 'a';
	}
	*/

	/*
	for (int i = 0; i < 43; i++) {
		board[25][i] = 1;
	}
	*/
	
	
	while ((key = getch()) != 27) {
		what = rand() % 7;
		createbox(i_block);
		//print_board(board);
	}
}

/*
CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
*/