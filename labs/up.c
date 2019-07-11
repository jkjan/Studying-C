#include <stdio.h>
#include <ncurses.h>

int main () {
	initscr();
	noecho();
	cbreak();

	int ym, xm;

	getmaxyx(stdscr, ym, xm);

	WINDOW * inputwin = newwin(3, xm-12, ym-5, 5);
	box(inputwin, 0,0);
	refresh();
	wrefresh(inputwin);

	keypad(inputwin, true);
	int c = wgetch(inputwin);
	if (c == KEY_UP) {
		mvprintw(inputwin, 1, 1, "you pressed up");
		wrefresh(inputwin);
	}

	getch();
	endwin();
}
