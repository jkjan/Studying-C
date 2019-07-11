#include <ncurses.h>
using namespace std;

int main (int argc, char ** argv) {
	initscr();
	int height, width, start_x, start_y;
	height = 10;
	width = 20;
	start_y = start_x = 10;

	WINDOW * win = newwin(height, width, start_y, start_x);
	refresh();
	box(win, 0,0); //draw a box
	mvwprintw(win, 1, 4, "code");
	mvwprintw(win, 3, 4, "data");
	mvwprintw(win, 5, 4, "heap");
	mvwprintw(win, 7, 4, "stack");


	wrefresh(win);
	int c = getch();
	endwin();
	return 0;
}
