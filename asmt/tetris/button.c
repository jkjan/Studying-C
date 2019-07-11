#include <ncurses.h>
#include <stdio.h>

int main ()  {

	initscr();

	char * choices[3] = {"Tetris","Mukchibba","Baseball"};
	int choice;
	int highlight = 0;

	WINDOW * selectwin = newwin(5, 20, 10, 10);
	refresh();
	box(selectwin, 0, 0);
	wrefresh(selectwin);

	int i, key;

	keypad(selectwin, true);

	while (1) {
		for (i = 0; i<3; i++) {
			if (i == highlight)
				wattron(selectwin, A_REVERSE);
			mvwprintw(selectwin, i+1, 1, "%s", *(choices+i));
			wattroff(selectwin, A_REVERSE);
		}
		
		key = wgetch(selectwin);

		switch(key) {
			case KEY_UP :
				if (highlight > 0)
					highlight--;
				break;
			case KEY_DOWN :
				if (highlight < 2)
					highlight++;
				break;
			default :
				break;
		}
		if (key == 10)
			break;

		//choice = highlight;
	}


	mvprintw(5, 5, "your choice was : %s", choices[highlight]);

	
	getch();

	endwin();

}

   
