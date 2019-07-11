#include "treeheader.h"
#include <unistd.h>
#include <pthread.h>

#define MUKCHIBBA 0
#define BASEBALL 1
#define TETRIS 2

void * teaser () { // teaser thread
	curs_set(0);
	int i, a, k;
	char str[] = "  GAME PACK 2019";
	WINDOW* titlewin = newwin(1, 16, 13, 18);

	int len = strlen(str);

	while(1) {  
		a=len-k%(len-1);
			for (i= 0; i<len; i++){ 
			mvwprintw(titlewin, 0, i, "%c", str[(a++)%len]);
			wrefresh(titlewin);
			}
		usleep(500000);  // 0.5 sec
		wclear(titlewin);
		wrefresh(titlewin);

		if (k<len-2)
    			k++;
		else 
    			k=0;
	}
}


void tetrismenu();
int Mukchiba();
void baseball();

extern tnode* root;

void mainmenu() {

	initscr();
	noecho();
	char * choices[4] = {"Mukchibba","Baseball","Tetris", "Maybe later"};
	int choice;
	int highlight = 0;
	int i;

	WINDOW * selectwin = newwin(15, 30, 10, 10);

	box(selectwin, 0, 0);
	wrefresh(selectwin);

	pthread_t title;
	pthread_create(&title, NULL, teaser, NULL);

	mvwprintw(selectwin, 5, 5, "What would you play?");
	wrefresh(selectwin);
	int key;

	keypad(selectwin, true);

	while (1) {  // selection and highlight, same as what i've learned at class
		for (i = 0; i<4; i++) {	
			curs_set(0);
			if (i == highlight)
				wattron(selectwin, A_REVERSE);

			mvwprintw(selectwin, i+8, 15-strlen(*(choices+i))/2, "%s", *(choices+i));
			wattroff(selectwin, A_REVERSE);
			
		}
		
		key = wgetch(selectwin);

		switch(key) { // if the key is up or down
			case KEY_UP :
				if (highlight > 0)
					highlight--;
				else
					highlight = 3;  // plus, it goes backward if theres no up
				break;
			case KEY_DOWN :
				if (highlight < 3)
					highlight++;
				else
					highlight = 0;  //or down
				break;
			default :
				break;
		}
		if (key == 10)
			break;
	}

	if (highlight ==MUKCHIBBA) { // if a player stops at mukchibba and enter
		pthread_cancel(title); // teaser thread cancel
		pthread_join(title, NULL);
		endwin();
		Mukchiba(); //play mukchibba
		return;
	}

	else if (highlight == BASEBALL) { // if a player stops at baseball and enter
		pthread_cancel(title);  //teaser thread cancel
		pthread_join(title, NULL);
		endwin();
		baseball();  //play baseball
		echo();
		return;

	}

	else if (highlight == TETRIS) { // if a player stops at tetris and enter
		clear();
		refresh();
		pthread_cancel(title);
		pthread_join(title, NULL);
		tetrismenu();
		return;
	}

	else { // if a player wants to end the program
		pthread_cancel(title);
		pthread_join(title, NULL);
		wclear(selectwin);	
		box(selectwin, 0, 0);  // new window
		mvwprintw(selectwin, 7, 10, "Good bye!"); // say good bye
		wgetch(selectwin);
		endwin();
		system("clear");
		exit(0);
		return;
	}
	
	getch();

	endwin();

	return;
}

int main ()  {
	root = NULL;
	FILE * tetrisfile = fopen("tetrisscores.txt", "r");  //tetris scores, read it
	int record;
	char ss[10];
	int level;
	if (tetrisfile != NULL) {
		while ((fscanf(tetrisfile, "%s %d %d\n", ss, &level, &record)) != EOF) {
			root = load(root, ss, record, level);
		}
		fclose(tetrisfile);
	}   
	mainmenu();  // start mainmenu

	return 0;
}
