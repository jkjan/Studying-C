#include <ncurses.h>
#include <stdio.h>

int main () {
	initscr();
	noecho();
	cbreak();
	
	int ym, xm;
	getmaxyx(stdscr, ym, xm);
	WINDOW*inputwin = newwin(1, xm-12, ym-5, 5);
	box(inputwin, 0, 0);
	refresh();
	wrefresh(inputwin);

	getch();
	endwin();	
	return 0;
}
