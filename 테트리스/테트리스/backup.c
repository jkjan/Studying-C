#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>

int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

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

void print_direction(void) {
	move(1, 25);

	printw("%d %d", x, y);
}

void print_shape(char m[4][4][4]) {
	int i, j;

	for (i = 0; i < 4; i++) {
		move(y + i, x);
		for (j = 0; j < 4; j++) {
			if (m[r][i][j] == 1)
				printw("#");
			else
				printw("  ");
		}
		printf("\n");
	}
}

void print_board(char b[][17]) {
	int i, j;
	int u = 5;

	system("clear");

	for (i = 0; i < 26; i++) {
		move(34, u++);
		for (j = 0; j < 17; j++) {
			if (b[i][j] == 1)
				printf("бс");
			else
				printf("  ");
		}
		printf("\n");
	}

	sleep(100);
}

void move_shape(char m[4][4][4]) {
	do {
		system("clear");
		print_shape(m);
		print_direction();
		//x = x + inx;
		//y = y + iny;

		//if (board[y][x]== 0) 
		//	board[y][x] = 1;

		if (y >= 25) {
			//_endthread();
			y = 25;
		}

		if (x > 75)
			x = 75;
		else if (x < 1)
			x = 1;
		sleep(100);
	} while (!kbhit());
}

void Thread_yDown() {
	while (y < 25) {
		y++;
		sleep(1000);
	}
}

int createbox(char ***m) {
	//_beginthreadex(NULL, 0, Thread_yDown, 0, 0, NULL);

	int key;
	int i = 0;
	mvprintw(10, 10, "yes?");
	do {
		while (!kbhit()) {
			//printf("%d %d", x, y);
			system("clear");
			move_shape(m);
		}

		key = getchar();
		if (key == 224 || key == 0) {
			key = getch();
			switch (key) {
			case 'w':
				//printf("up\n");
				r = (r == 3 ? 0 : r + 1);
				move_shape(m);
				//sleep(100);
				break;
			case 'a':
				//printf("left\n");
				x += -1;
				y += 0;
				move_shape(m);
				break;
			case 'd':
				//printf("right\n");
				x += 1;
				y += 0;
				move_shape(m);
				break;
			case 's':
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

int main() {
	int key;
	/*
		pthread_t gameboard;
		pthread_t makeblock;
		pthread_t ydown;

		srand(time(NULL));

		char ****blocks = (char****)malloc(sizeof(char***) * 7);

		*(blocks) = i_block;
		*(blocks + 1) = t_block;
		*(blocks + 2) = s_block;
		*(blocks + 3) = z_block;
		*(blocks + 4) = l_block;
		*(blocks + 5) = j_block;
		*(blocks + 6) = o_block;

		gotoxy(10, 20);
		//printf("%d", what);

		int what = rand()%7;
		int joinStatus;
		//pthread_create(&gameboard, NULL, print_board, board);
		pthread_create(&makeblock, NULL, createbox, *(blocks+what));
		pthread_create(&ydown, NULL, Thread_yDown, NULL);

		pthread_join(ydown, (void**)&joinStatus);
		//pthread_join(gameboard, (void**)&joinStatus);
		pthread_join(makeblock, (void**)&joinStatus);
		/*
		for (int i = 0; i < 1118; i++) {
			if ((i + 1) % 43 == 0 || i % 43 == 0)
				**(board + i) = 'b';
			else
				**(board + i) = 'a';
		}

		for (int i = 0; i < 43; i++) {
			board[25][i] = 1;
		}

		*/


		/*

		while ((key = getch()) != 27) {
			what = rand() % 7;
			//createbox(*(blocks + what));
			print_board(board);
		}*/


	initscr();

	int x, y;

	x = y = 10;
	move(y, x);
	printw("Hello World!");
	refresh();
	int c = getch();
	clear();
	mvprintw(0, 0, "%d", c);

	refresh();
	clear();

	int joinStatus;
	/*
		pthread_t gameboard;
		pthread_t makeblock;
		pthread_t ydown;



		pthread_create(&makeblock, NULL, createbox, i_block);
		pthread_create(&ydown, NULL, Thread_yDown, NULL);

		pthread_join(ydown, (void**)&joinStatus);
		//pthread_join(gameboard, (void**)&joinStatus);
		pthread_join(makeblock, (void**)&joinStatus);
	*/

	//print_direction();


	while (1) {
		refresh();
		clear();
		print_direction();
		print_shape(i_block);
		if (kbhit()) {
			key = getch();
			switch (key) {
			case 'w':
				//printf("up\n");
				r = (r == 3 ? 0 : r + 1);

				//move_shape(i_block);
				//print_shape(i_block);
				//sleep(100);
				break;
			case 'a':
				//printf("left\n");
				x += -1;
				y += 0;
				mvprintw(10, 10, "a pressed");
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
				y += 5;
				//print_shape(i_block);
				//move_shape(i_block);
				//printf("down\n");
				break;
			default:
				break;
			}
		}
	}


	getch();
	endwin();

	return 0;

	//createbox(l_block);


}

/*
CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
*/