#include <ncurses.h>
using namespace std;

int main (int argc, char** argv) {

	initscr();

	int x, y;
	
	x= y= 10;
	move(y, x);
	printw("Hello World!");
	refresh();
	int c = getch();
	//clear();
	mvprintw(0,0,"%d", c);
	refresh();
	//clear();
	getch();
	endwin();

	return 0;
}
