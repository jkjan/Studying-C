#include <stdio.h>
#include <ncurses.h>

int main () {
	initscr();
	WINDOW*win = newwin(5, 10, 15, 45);
	refresh();
      box(win, 0,0);   
	      wprintw(win, "starts here");
	wrefresh(win);

    //  mvprintw(18, 50, "%d ", score);
	getch();
	clear();
	endwin();
	printf("Hello world\n");
      }
