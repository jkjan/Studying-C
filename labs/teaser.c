#include <ncurses.h>
#include <stdio.h>
#include <string.h>

int main () {
	initscr();
	int yMax;
	int xMax;
	getmaxyx(stdscr, yMax, xMax);

	char str[]= "Save the world";

	int i = 0;
	int len = strlen(str);

	while(1) {
		if (i >= len)
			i==0;
		move(yMax/2, xMax/2+i);
		printw("%c", str[i]);
		i++;
	}
}
