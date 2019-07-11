#include "tetrisheader.h"
#include "blocks.h"
#include <math.h>
#include <stdio_ext.h> // __fpurge(stdin)

int collisiontest(int d) {
   int i, j;
   
   switch (d) {
      //when left
      case 1:   
      for (j = 0; j<4; j++) {
         for (i = 1; i<=4; i++) { 											//4x4 square
            if (Board[y+i][x-WIDTH+j].c == 2 && (Board[y+i][x-WIDTH-1+j].c == 1 || Board[y+i][x-WIDTH-1+j].c == 3)) { //it is a block(2) and the left is wall(1) or stamped block(3)?
               return 0;
            }
         }
      }
         break;   

      //when right
      case 2:
      for (j = 3; j >= 0; j--) {
         for (i = 1; i<=4; i++) { 
            if (Board[y+i][x-WIDTH+j].c == 2 && (Board[y+i][x-WIDTH+1+j].c == 1 || Board[y+i][x-WIDTH+1+j].c == 3)) { //it is a block(2) and the right is wall(1) or stamped block(3)?
               return 0;
            }
         }
      }
         break;

      //when rotate
      case 3:
         for (i = 0; i< 4; i++) {
            for (j = 0; j < 4; j++) {
               if (Board[y+i][x-WIDTH+j].c == 2 && (Board[j+y+1][-(i-3)+x-WIDTH].c == 1 || Board[j+y+1][-(i-3)+x-WIDTH].c == 3)) { //it is a block(2) and the rotated is wall(1) or stamped block(3)?
                  return 0;
               }
            }
         }
         break;
      //when down
      case 4:
      for (j = 4; j >= 1; j--) {
         for (i = 0; i< 4; i++) {
            if (Board[y + j][x - WIDTH +i].c == 2 && (Board[y + 1 + j][x - WIDTH +i].c == 1 || Board[y + 1 + j][x - WIDTH +i].c == 3)) //it is a block(2) and the under is wall(1) or stamped block(3)?
               return 0;
         }
      }
      break;
   }
   
   return 1;
}

void Boardinit(int real) {  //initiate Board, to avoid incursion
   int i, j;
   for (i = 0; i<HEIGHT; i++) {
         for (j = 0; j<WIDTH; j++) {
            if (Board[i][j].c == 3) {
		if (real == 0)
               		Board[i][j].c = 3;   // leave stamped block as stamped
		else {
			Board[i][j].c = 0;   // if 1 is transferred as an argument, it initiates the board for real.
			Board[i][j].color = 0;
		}
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


void stamp() {    // to leave a block behind
   int i, j;  
   wrefresh(mainwin);
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

char* blockGenerator() {  // generates a block randomly.
   int what = rand()%7;
   switch(what) {
      case 0:
         return (char*)i_block;
      case 1:
         return (char*)t_block;
      case 2:
         return (char*)s_block;
      case 3:
         return (char*)z_block;
      case 4:
         return (char*)l_block;
      case 5:
         return (char*)j_block;
      case 6: 
         return (char*)o_block;
   }
}

void move_shape() {
   do {   
      Boardinit(0);   //initiate a board
      print_shape();  //print a block
      usleep(33000);
   } while (!_kbhit());
}


void* blockbox() {

int i, j;
	
	WINDOW*pause;
	WINDOW*quit;
	int yIncrease;
   int key;
   r = 0;    //initiate x, y, r
   y = 2;
   x = 17;
      cur = next;  
      c = d;
      next = blockGenerator();   // generates next and cur blocks
      d = rand()%5+1;

	win[0] = newwin(7, 12, 10, 42);
	
      	box(win[0], 0,0);   
	mvwprintw(win[0], 0, 1, "NEXT BLOCK");   // print next block in a window

	for (i = 0; i<4; i++) {
         for (j = 0; j<4; j++) {
            if (*(next +i*4 +j) == 1) {
		if (next == (char*)i_block) {                   // the position should be adjusted because i_block is too long
			  wattron(win[0], COLOR_PAIR(d));
			 mvwprintw(win[0], 3+i, 2+j*2, "[]");
			wattroff(win[0], COLOR_PAIR(d));
			
			}
		else if (next == (char*)o_block) {              // and o_block is too short
			               wattron(win[0], COLOR_PAIR(d));
		   mvwprintw(win[0], 3+i, 4+j*2, "[]");
			              wattroff(win[0], COLOR_PAIR(d));
		}

		else {
               wattron(win[0], COLOR_PAIR(d));
               mvwprintw(win[0], 2+i, 4+j*2, "[]");
               wattroff(win[0], COLOR_PAIR(d));
		}
            }
            
         }
      }
	wrefresh(win[0]);

	yIncrease = pthread_create(&tid[2], NULL, ydown, NULL);
	     pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);  // as default 
   while(1) {

	if (collisiontest(4) ==0) {  // if theres something under the block
		stamp();
			pthread_cancel(tid[2]);
			pthread_join(tid[2], NULL);
		pthread_exit(NULL);
		
	}	

      while (!_kbhit()) {
         move_shape();
      }

      key = _getch();
      switch (key) {
      case 'w':
         if (collisiontest(3)) {   // key w, rotates
            r = (r == 3 ? 0 : r + 1);
            move_shape();
         }
         break;
      case 'a':
         if (collisiontest(1)) {  // key a, move left
            x += -1;   
            move_shape();
         }
         break;
      case 'd':
         if (collisiontest(2)) { // key d, move right
            x += 1;
            move_shape();
         }
         break;
      case 's':
	if (collisiontest(4)) { // key s, move down
         y += 1;
         move_shape();
	break;
	}
	case 'p' :  // key p, pause
		pthread_cancel(tid[0]);
		pause = newwin(5, 11, 15, 19);  //pop a window
		mvwprintw(pause,2,3, "Pause");
		box(pause,0,0);
		wrefresh(pause);
		pthread_cancel(tid[2]);   // cancel ydown
		pthread_join(tid[2], NULL);
		
		while (1) {    // till it gets 'p'
			
			if ((key = getchar()) == 'p') {	//if it gets 'p', 
				wclear(pause);
				wrefresh(pause);
				pthread_create(&tid[0], NULL, printBoard, NULL); // start threads
				yIncrease = pthread_create(&tid[2], NULL, ydown, NULL);
				break;	
			}	
		}

         
         break;

	case 'q' : ////key q, quit
		pthread_cancel(tid[0]); 
		quit = newwin(9, 24, 15, 12); //pop a window
		mvwprintw(quit,2,5, "Are you sure?");
		mvwprintw(quit, 4, 3, "Yes : q");
		mvwprintw(quit, 5, 3, "No : Press Any key");
		box(quit,0,0);
		wrefresh(quit);
		pthread_cancel(tid[2]); //cancel ydown
		pthread_join(tid[2], NULL);
		
		if  ((key = getchar()) == 'q') { // if 'q' again,
			clear();
			refresh();
			tetrismenu();  // back to menu
		}
			

		else {
				__fpurge(stdin);
				wclear(quit);
				wrefresh(quit);
				pthread_create(&tid[0], NULL, printBoard, NULL);
				yIncrease = pthread_create(&tid[2], NULL, ydown, NULL);
				
		
		}
		break;
	default:
		
         break;
      }
   }
}

void tetrismenu() {
	int i;

	WINDOW * tmenu = newwin(15, 30, 10, 10);

	char * choices[4] = {"Description","Game Play","Records","Back"};   //selection
	int choice;
	keypad(tmenu, true);
	
	box(tmenu, 0, 0);
	wrefresh(tmenu);
	curs_set(0);
	int key;
	while (1) {

		mvwprintw(tmenu, 4, 6, "Welcome to Tetris!");

		for (i = 0; i<4; i++) {	
			
			if (i == highlight)
				wattron(tmenu, A_REVERSE);
			mvwprintw(tmenu, i+7, 15-strlen(*(choices+i))/2, "%s", *(choices+i));  // align center
			wattroff(tmenu, A_REVERSE);
			
		}
		
		key = wgetch(tmenu);

		switch(key) {
			case KEY_UP :
				if (highlight > 0)
					highlight--;
				else
					highlight = 3;
				break;
			case KEY_DOWN :
				if (highlight < 3)
					highlight++;
				else
					highlight = 0;
				break;
			default :
				break;
		}
		if (key == 10) //enter
			break;
	}


	if (highlight == 0) { //description
		WINDOW*desc = newwin(25, 55 ,5 ,42);
		box(desc, 0,0);
		mvwprintw(desc, 2, 19, "What is tetris?");
		mvwprintw(desc, 4, 16, "Press any key to exit");
		mvwprintw(desc, 6,2,"Tetris is a video game developed in the Soviet Un-");
		mvwprintw(desc, 7,2,"ion in 1984. The game has a simple goal of destroy-");
		mvwprintw(desc, 8,2,"ing lines of block before it reaches the top.");
		mvwprintw(desc, 9,2,"The line is made up of of a square block.");
		mvwprintw(desc, 10,2,"Tetrominoes is the shape of the 4 connected blocks ");
		mvwprintw(desc, 11,2,"that falls vertically down. The player will ");
		mvwprintw(desc, 12,2,"have to use the tetrominos to create lines that ");
		mvwprintw(desc, 13,2,"fill the box horizontally, this will clear ");
		mvwprintw(desc, 14,2,"the lines of blocks.");
		mvwprintw(desc, 16, 2,"The game continues, the lines of blocks that");
		mvwprintw(desc, 17,2,"is not completely filled will drop down ");
		mvwprintw(desc, 18, 2, "as many lines that were cleared. ");
		mvwprintw(desc, 19, 2, "The game has levels of difficulties which ");
		mvwprintw(desc, 20, 2, "rises as the game is being played.");  //print description about tetris

		wgetch(desc);
		clear();
		refresh();

		tetrismenu();
		return;
	}


	else if (highlight == 1) {   //tetris
		speedcontroller(13,42);
		return;
	}

	else if (highlight == 2) {  //record
		recordboard = newwin(19, 30 ,8 ,42);
		box(recordboard, 0,0);
		mvwprintw(recordboard, 2, 9, "Record Board");
		
		if (root == NULL) {
			mvwprintw (recordboard, 5, 8, "No record yet.");			
			
		}


		else {
		mvwprintw(recordboard, 4, 5, "Press any key to exit");
		mvwprintw(recordboard, 6, 2, "Rank   Name   Level  Score");
		o = 7;
		treeprint(root);
		}


		wrefresh(recordboard);
		o = 7; // the position, and limit the number of records
		treeprint(root);
		wgetch(recordboard);

		clear();
		refresh();

		tetrismenu();
		return;
	}

	else {	//back
		highlight = 0;
		clear();
		refresh();
		mainmenu();
		return ;
	}

}


int oneline() {
   int i, j, k;
	int linecnt = 0;
   for (i = HEIGHT-2; i >= 1; i--) {  // from the floor
      if (line[i] >= WIDTH-2) {       // if the whole line is filled
		linecnt++; 
	for (j = 1; j< 4; j++) {      // if the lines above it are also filled
		if (line[i-j] >= WIDTH-2 )
			linecnt++;
		else
			break;
	}
	break;
      }
   }
	if (linecnt > 0) {   // more than one line is filled
	for (j = i; j-linecnt >= 8; j--) {  
            line[j] = line[j-linecnt];   // move line numbers
            
            for (k = 1; k<=WIDTH-2; k++) {  // and blocks
               Board[j][k] = Board[j-linecnt][k];
            }
         }
	score = score + 100*linecnt+(speed-1)*50; 
	
	

	

	if (linecnt > 1) {  //if more than two lines 

		int *passline = &linecnt;
		score += 50*linecnt;
		pthread_create(&tid[3], NULL, (void*) comboprint, passline);  //print combo for 2 seconds
	}
	
	mvwprintw(win[1], 3, log10(score) >= 3? 2:3, "SCORE : %d", score);  // print score 
		wrefresh(win[1]);
	}
	return linecnt;
}

void* comboprint(void *arg) {
	WINDOW*combowin = newwin(2,30,17, 40);  // invisible win
	int lines = *(int *)arg;
	mvwprintw(combowin,1,1, "%d combo! %d bonus!", lines, 50*lines);   //print combo and bonus score
	wrefresh(combowin);

	sleep(2);  //sleep for 2 seconds
	wclear(combowin);
	wrefresh(combowin);
}


void * printBoard() {
   int i=0;
   int j =0;
	
   while (1) {
      wrefresh(mainwin);
	oneline();

	if (collisiontest(4)==0) {
		stamp();
		pthread_cancel(tid[1]);
		pthread_cancel(tid[2]);	
		pthread_join(tid[2], NULL);
	}


      for (i = 0; i < HEIGHT; i++) {
	//mvwprintw(mainwin, i,1,"%d", line[i]);
         for (j = 0; j<WIDTH; j++) {
            if (Board[i][j].c == 2 || Board[i][j].c == 3) {  //if its a block
               wattron(mainwin, COLOR_PAIR(Board[i][j].color));
               mvwprintw(mainwin, i, 3+j*2, "[]");
               wattroff(mainwin ,COLOR_PAIR(Board[i][j].color));
            }

            else if (Board[i][j].c == 1 && (i > 7)) {  //if its a wall
               wattron(mainwin, COLOR_PAIR(6));
               mvwprintw(mainwin, i, 3+j*2, "XX");
               wattroff(mainwin, COLOR_PAIR(6));
            }
            
            else if (i > 2) {         //if its void
		wattron(mainwin, A_INVIS);
               mvwprintw(mainwin, i, 3+j*2, "  ");
		wattroff(mainwin, A_INVIS);
		}

         }
      }
   
   usleep(33000);
   }
}

void* ydown() {

   while(1) {  
      if (collisiontest(4) == 0) { //if theres something under a block
         stamp();  //stamp and cancel blockbox and himself
         pthread_cancel(tid[1]);
	pthread_exit(NULL);
      }

      else {
         y++;  // if not, increases y
      }
	spdcnt++;

	if (spdcnt == 100 || score/1000 >= speed) {   // if y is increased 100 times and the score is over 1000, 2000, 3000 --
		spdcnt = 0;   
		if (speed < 5) {
			speed ++;  // speed up	
			mvwprintw(win[1], 2, 3, "LEVEL : %d", speed);
			wrefresh(win[1]);
		}
	}
      
      usleep(1000000 - (speed-1)*199999);   // 1, 0.8 0.6 0.4 0.2 ...
   }
}

void print_shape() {
   int i, j;

   for (i = 0; i < 4; i++) {

      for (j = 0; j < 4; j++) {      // print block
         if (*(cur+16*r+i*4+j) == 1) {
            Board[y+i][x+j].c= 2;  //carve 2 on the block, and its color
            Board[y+i][x+j].color= c;
         }
      }
   }
}

void tetris () { // real tetris function
   initscr();
	init_keyboard();
   srand(time(NULL));
	int printingBoard;
	int boxmove;
	for (int i = 0; i< HEIGHT; i++)
		line[i] = 0;

	score = 0;  // init score
	
	mvprintw( 27, 42, "w : Spin");
	mvprintw( 28, 42, "a : Move Left");
	mvprintw( 29, 42, "s : Move Down");
	mvprintw( 30, 42, "d : Move Right");
	mvprintw(31, 42, "p : Pause");
	mvprintw(32, 42, "q : Quit");
	refresh();

if (has_colors()) {
	use_default_colors();
	start_color();
	init_pair(7, COLOR_WHITE, -1);  // default color
}

	attrset(COLOR_PAIR(7));
   init_pair(1, COLOR_WHITE, COLOR_GREEN);  // color pairs
   init_pair(2, COLOR_WHITE, COLOR_YELLOW);
   init_pair(3, COLOR_WHITE, COLOR_BLUE);
   init_pair(4, COLOR_WHITE, COLOR_CYAN);
   init_pair(5, COLOR_WHITE, COLOR_RED);
   init_pair(6, COLOR_WHITE, COLOR_WHITE);
	
   cur = blockGenerator();   //generates current and next block
   c = rand()%5+1;
   next = blockGenerator();
   d = rand()%5+1;
  
   score = 0;

   Boardinit(1); // block init for real 
	
	mainwin = newwin(31, 30, 3, 9);
	box(mainwin, 0, 0);
	wrefresh(mainwin);

	
	win[1] = newwin(6, 16, 20, 40);
	
	box(win[1], 0, 0);
	mvwprintw(win[1], 0, 3, "YOUR SCORE");
	mvwprintw(win[1], 2, 3, "LEVEL : %d", speed);
	mvwprintw(win[1], 3, log10(score) >=3? 2:3, "SCORE : %d", score);
	wrefresh(win[1]);

   printingBoard = pthread_create(&tid[0], NULL, printBoard, NULL);  //create board printing thread


   while(1) {   
      
     boxmove = pthread_create(&tid[1], NULL, blockbox, NULL);    //block box thread
	   

      pthread_join(tid[1], NULL);

      if (line[7] >= 1) {   //if the top line is filled
	 pthread_cancel(tid[1]);   // cancel all threads
      pthread_cancel(tid[2]);   
      pthread_cancel(tid[0]);

	break;
      
      }
   }

	WINDOW*lost = newwin(9, 25, 15, 12);
	box(lost,0,0);

	mvwprintw(lost, 1,9, "YOU LOST");
	if (root == NULL || (root!=NULL && score > root->count))  //if theres no node or the score is the highest
		mvwprintw(lost, 2,6,"Highest Score!!!");
	mvwprintw(lost, 3,(log10(score) >=3? 1:2), "The final score is %d", score);
	mvwprintw(lost, 4,2, "Enter your name : ");

	curs_set(1);
	echo();
	char name[5];

	while(1) {
		mvwscanw(lost, 4, 20, " %s", name);  // till theres no name on the list
		name[4] = '\0';
		if (search(root, name) == 1) {
			mvwprintw(lost, 6,1, "The name already exists");
			mvwprintw(lost, 7,2, "Anything else in mind?");
		}
			
		else {
			break;
		}
		wrefresh(lost);
	}
	noecho();
	curs_set(0);
	root = addtree(root, name, score, speed);  // add the player's score and level
	export(root);

	wclear(lost);
	box(lost, 0, 0);

	char command;
	while (1) {   // ask a player if he's gonna play more or not
	mvwprintw(lost, 1,8, "Want more?");
	mvwprintw(lost, 3,2, "Yes : Y");
	mvwprintw(lost, 4,2, "Another : A ");
	mvwprintw(lost, 5,2, "No : N");	
	
	
	while(1) {
	command = mvwgetch(lost, 6,5);
	if (command == 'Y') { //if he says yes
		 
		wclear(lost);
		
		speedcontroller(15, 12);  //speed adjust, play tetris again
	}
	else if (command == 'N') {  // if he says no
		wclear(lost);
		box(lost, 0, 0);

		mvwprintw(lost, 4,8, "Good bye!");
		wgetch(lost);
		clear();
		refresh();
		echo();
		endwin();
		system("clear");
		exit(0);  //exit
	}
	else if (command == 'A') { //if he wants another one
		close_keyboard();
		clear();
		refresh();
		mainmenu(); //go back to main menu
	}
	else {
		mvwprintw(lost, 6,5, "Wrong choice!");	
	}
	}
	}

   refresh();
   clear();
   endwin();

   return;
}

void speedcontroller (int y, int x) {
		WINDOW*speedcontrol = newwin(9,25 ,y ,x);
		box(speedcontrol, 0,0);
		
		keypad(speedcontrol, true);
		speed = 1;
		int key = 0;
		while (1) {
			wrefresh(speedcontrol);
			mvwprintw(speedcontrol, 1, 10, "Level");
			mvwprintw(speedcontrol, 3, 2, "Use arrows to adjust");
			mvwprintw(speedcontrol, 4, 2, "Backspace to go back");
			mvwprintw(speedcontrol, 6, 10, "< %d >", speed);
			//adjust speed with arrows

			key = wgetch(speedcontrol);
			switch(key) {
				case KEY_LEFT :
					if (speed > 1)
					speed--;
					break;
				case KEY_RIGHT :
					if (speed < 5)
					speed++;
					break;
				default:
					break;

			}
			if (key == 10) {  //if enter
				clear();
				refresh();
				tetris();
				return;
			}
			else if (key == KEY_BACKSPACE) {
				clear();
				refresh();
				tetrismenu(); // or go back to tetrismenu
				return;
				
	
			}
				
		
		}
}

