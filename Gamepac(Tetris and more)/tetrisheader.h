#ifndef TETRISGAME
#define TETRISGAME

#include "treeheader.h"
#include <pthread.h>
#include <unistd.h>

#define WIDTH 12
#define HEIGHT 29

int x;
int y;
int r;
pthread_t tid[4];
int score;
int line[HEIGHT];
int speed;
int c,d;
WINDOW * win[2];
WINDOW*mainwin;
WINDOW*recordboard;
char *next;
char *cur;

tnode * root;

int o;
int highlight;

typedef struct _board {
   char c;
   int color;
}board;

board Board[HEIGHT][WIDTH];

int oneline();
void print_shape();
int collisiontest(int d);
void Boardinit(int real);
void stamp();
char* blockGenerator();
void move_shape();
void* blockbox();
void init_keyboard();
void close_keyboard();
int _kbhit();
int _getch();
void tetris();
void tetrismenu();
void mainmenu();
void *printBoard();
void *ydown();
int spdcnt;
void* comboprint(void *arg);
void speedcontroller (int y, int x);

#endif
