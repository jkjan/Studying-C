#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <ncurses.h>
#include "kbhit.h"
#include <locale.h>
#include <wchar.h>
#include "blocks.h"

#define WIDTH 12
#define HEIGHT 28

int x;
int y;
int r;
pthread_t tid[3];
int score = 0;
int line[HEIGHT] = {0,};
int speed;
int c,d;
const WINDOW * win;

char*** blockGenerator();


char ***next;
char ***cur;
int cnt=2;

typedef struct _board {
	char c;
	int color;
}board;

board Board[HEIGHT][WIDTH];

/*
typedef struct _TheBlock {

	char m[4][4][4];
	int c;

} TheBlock;*/


void oneline() {
	int i, j, k;
	for (i = HEIGHT-2; i >= 1; i--) {
		if (line[i] >= 10) {
			score += 100;
			for (j = i; j >= 1; j--) {
				line[j] = line[j-1];
				
				for (k = 1; k<=WIDTH-2; k++) {
					Board[j][k] = Board[j-1][k];
				}
			}
		}
	}
}



int collapsetest(int d) {
	int i, j;
	
	switch (d) {
		//when left
		case 1:	
		for (j = 0; j<4; j++) {
			for (i = 1; i<=4; i++) { 
				if (Board[y+i][x-WIDTH+j].c == 2 && (Board[y+i][x-WIDTH-1+j].c == 1 || Board[y+i][x-WIDTH-1+j].c == 3)) {
					return 0;
				}
			}
		}
			break;	

		//when right
		case 2:
		for (j = 3; j >= 0; j--) {
			for (i = 1; i<=4; i++) { 
				if (Board[y+i][x-WIDTH+j].c == 2 && (Board[y+i][x-WIDTH+1+j].c == 1 || Board[y+i][x-WIDTH+1+j].c == 3)) {
					return 0;
				}
			}
		}
			break;

		//when rotate
		case 3:
			for (i = 0; i< 4; i++) {
				for (j = 0; j < 4; j++) {
					if (Board[y+i][x-WIDTH+j].c == 2 && (Board[j+y+1][-(i-3)+x-WIDTH].c == 1 || Board[j+y+1][-(i-3)+x-WIDTH].c == 3)) {
						return 0;
					}
				}
			}
			break;
		//when down
		case 4:
		for (j = 4; j >= 1; j--) {
			for (i = 0; i< 4; i++) {
				if (Board[y + j][x - WIDTH +i].c == 2 && (Board[y + 1 + j][x - WIDTH +i].c == 1 || Board[y + 1 + j][x - WIDTH +i].c == 3))
					return 0;
			}
		}
		break;
	}
	
	return 1;
}

void Boardinit() {  //initiate Board, to avoid incursion
	int i, j;
	for (i = 0; i<HEIGHT; i++) {
			move(i+5, WIDTH-20);
			for (j = 0; j<WIDTH; j++) {
				if (Board[i][j].c == 3) {
					Board[i][j].c = 3;
				}
				else if ((j == 0 || j == WIDTH-1 || i == HEIGHT-1)) {
					Board[i][j].c = 1;

				}
				else {
					Board[i][j].c = 0;
					Board[i][j].color = 0;
				}
			}
		}
}

void printBoard(char ***m) {
	int i=0;
	int j =0;

	while (1) {
		refresh();

		for (i = 0; i < HEIGHT; i++) {
			move(i+2, WIDTH);
			for (j = 0; j<WIDTH; j++) {
				if (Board[i][j].c == 2 || Board[i][j].c == 3) {  //if its a block
					attron(COLOR_PAIR(Board[i][j].color));
					printw("[]");
					attroff(COLOR_PAIR(Board[i][j].color));
				}

				else if (Board[i][j].c == 1 && (i > 7)) {  //if its a wall
					attron(COLOR_PAIR(6));
					printw("XX");
					attroff(COLOR_PAIR(6));
				}
				
				else 			//if its void
					printw("  ");

			}
			printw("\n");
			curs_set(0);
		}
		
		for (i = 0; i<4; i++) {
			move(15+i, 45);
			for (j = 0; j<4; j++) {
				if (m[0][i][j] == 1) {
					attron(COLOR_PAIR(d));
					printw("[]");
					attroff(COLOR_PAIR(d));
				}
				else
					printw("  ");
			}
		}	
		
		win = newwin(5, 10, 15, 45);
		box(win, 0,0);	
		wprintw(win, "starts here");
		mvprintw(18, 50, "%d ", score);
		move(HEIGHT+2 , WIDTH);
		for (j = 0; j< WIDTH; j++) {
			printw("XX");
		}
	usleep(10000);
	}
}

void stamp() {
	int i, j;
	refresh();
	for (i = 1; i <= 4; i++) {
		for (j = 0; j < 4; j++) {
			if (Board[y+ i][x-WIDTH+j].c == 2) {
				Board[y+i][x+j-WIDTH].c= 3;
				Board[y+i][x+j-WIDTH].color= c;
				line[y+i]++;
			}
			
		}
	}
}

void ydown() {
	int s;
	while(1) {
		if (collapsetest(4) == 0) {
			stamp();
			pthread_cancel(tid[1]);	
		}

		else {
			y++;
		}
		
		usleep(1000000-(speed-1)*220000 - s);
		s+=1000;
	}
}

void print_shape(char ***m) {
	int i, j;
	refresh();
	for (i = 0; i < 4; i++) {
		move(y + i, x);
		for (j = 0; j < 4; j++) {
			if (m[r][i][j] == 1) {
				Board[y+i][x+j].c= 2;
				Board[y+i][x+j].color= c;
			}
		}
	}
}

void move_shape(char *** m) {
	do {
		Boardinit();
		oneline();
		print_shape(m);

		usleep(10000);
	} while (!_kbhit());
}

void blockbox(char ***m) {
	int key;
	init_keyboard();
	r = 0;
	y = 2;
	x = 17;

	/*if (cnt == 1) {
		cur = next;
		c = d;
		next = blockGenerator();
		d = rand()%5+1;
		cnt++;
	}*/

	while(collapsetest(4)) {
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

		while (!_kbhit()) {
			move_shape(cur);
		}

		key = _getch();
		switch (key) {
		case 'w':
			if (collapsetest(3)) {
				r = (r == 3 ? 0 : r + 1);
				move_shape(cur);
			}
			break;
		case 'a':
			if (collapsetest(1)) {
				x += -1;	
				move_shape(cur);
			}
			break;
		case 'd':
			if (collapsetest(2)) {
				x += 1;
				move_shape(cur);
			}
			break;
		case 's':
			y += 1;
			move_shape(cur);
			
			break;
		default:
			break;
		}
	}

	cnt--;
	stamp();
	close_keyboard();
	return;
}

char*** blockGenerator() {
	int what = rand()%7;
	//c = rand()%5+1;
	switch(what) {
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

int tetris () {
	initscr();
	srand(time(NULL));
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_YELLOW);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_WHITE, COLOR_CYAN);
	init_pair(5, COLOR_WHITE, COLOR_RED);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);

	cur = blockGenerator();
	c = rand()%5+1;
	next = blockGenerator();
	d = rand()%5+1;
	cnt = 2;

	Boardinit();
	//pthread_t tid[2];
	//pthread_create(&tid[0], NULL, ydown, blockGenerator());
	/*
	while (1) {
		pthread_create(&tid[1], NULL, blockbox, blockGenerator());
		pthread_join(tid[1], NULL);
	}

	pthread_join(tid[0], NULL);	
	*/
	//printBoard();
	
	pthread_create(&tid[0], NULL, printBoard, NULL);
	pthread_create(&tid[2], NULL, ydown, NULL);

	while(1) {
		
		pthread_create(&tid[1], NULL, blockbox, blockGenerator());
		pthread_join(tid[1], NULL);

		if (line[8] >= 1) {

		pthread_cancel(tid[1]);	
		pthread_cancel(tid[2]);	
		pthread_cancel(tid[0]);
		mvprintw(5,10,"you lost");
		
		}
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[2], NULL);
	
	refresh();
	clear();
	endwin();

	return 0;
}

int main ()  {
	setlocale(LC_ALL, "");

	printf("speed 1 to 5 : ");
	scanf("%d", &speed);
	tetris();

}

	
