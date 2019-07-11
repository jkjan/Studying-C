#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Mukchiba();
int Random();
void Lose(int* pturn);
void Win(int* pturn, int* w, int* l);

void mainmenu();
void gamefinish();


int Mukchiba()
{	
	system("clear");

    int player;
    int computer;
    int w = 0;
    int l = 0;
    int* pw = &w;
    int* pl = &l;
    int turn = 0; /*The initial value of the turn variable declaration to determine the order is zero.*/
    int* pturn = &turn;
    
    printf("!!!~~~Mukchiba Game~~~!!!\n\n");
    
    do{
       printf("Enter one of 1(Rock), 2(scissors), 3(paper), 4(Exit)\n\n");
       printf("Enter a number: ");
       fflush(stdin);
       scanf("%d", &player); /*Receive input from the user*/

       computer = Random(); /*Randomly receive input from the computer*/
       
       if (player == 1){
           if(computer == 1){
                printf("Player = Rock\nComputer = Rock\n\n");
                Win(&turn, &w, &l);
           }
           else if(computer == 2){
                 printf("Player = Rock\nComputer = Scissors\n\n");
                 turn = 1;
                 Lose(&turn);
                 
           }
           else if(computer == 3){
                 printf("Player = Rock\nComputer = Paper\n\n");
                 turn = 2;
                 Lose(&turn);
                 
           }
       }
       else if(player == 2){
            if(computer == 1){
                  printf("Player = Scissors\nComputer = Rock\n\n");
                  turn = 2;
                  Lose(&turn);
                  
             }
             else if(computer == 2){
                  printf("Player = Scissors\nComputer = Scissors\n\n");
                  Win(&turn, &w, &l);
             }
             else if(computer == 3){
                  printf("Player = Scissors\nComputer = Paper\n\n");
                  turn = 1;
                  Lose(&turn);
             }               
       }
       else if(player == 3){
             if(computer == 1){
                  printf("Player = Paper\nComputer = Rock\n\n");
                  turn = 1;
                  Lose(&turn);
             }
             else if(computer == 2){
                  printf("Player = Paper\nComputer = Scissors\n\n"); 
                  turn = 2;
                  Lose(&turn);
             }
             else if(computer == 3){
                  printf("Player = Paper\nComputer = Paper\n\n");
                  Win(&turn, &w, &l);
             }
       }
       else if(player == 4){ /*At the end of the game, print the number of wins and losses for the player.*/
              printf("Number of times a player wins : %d\nNumber of times a player loses : %d\n", *pw, *pl);

		gamefinish();
		
              //return 0;
       }
       else
           printf("Please re-enter\n\n");
      }while(1);
     return 0;
}

int Random()
{
    int s = 0;
    
    srand(time(NULL)); /*Set the random value to time.*/
    s = rand() % 3 + 1; /*S divided by 3 and remaining + 1, values from 1 to 3.*/
    
    return s;
}

void Lose(int* pturn)
{
   if(*pturn == 1) /*If turn is 1, player attacks*/
        printf("Player's attack!\n\n");
 
   else if(*pturn ==2) /*If turn is 2, computer attacks*/
        printf("Computer's attack!\n\n");
}

void Win(int* pturn, int* pw, int* pl)
{
   if(*pturn == 0){ /*If turn is 0, Play rock, paper, scissors again.*/
      printf("Please play rock, paper, scissors again\n\n");
   }

   else if(*pturn == 1){ /*If turn is 1, player wins*/
        (*pw)++; /*an increase in the number of wins*/
        printf("Player wins!!!\n\n");
       *pturn = 0; /*Initialize turn to zero*/
   }
   else if(*pturn == 2){ /*If turn is 2, computer wins*/
       (*pl)++; /*an increase in the number of losses*/
       printf("Computer wins!!!\n\n");
       *pturn = 0; /*Initialize turn to zero*/
       
   }
   return;
}
