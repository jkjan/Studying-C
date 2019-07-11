#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 /*
 stdlib.h 헤더는 랜덤한 값을 나타내기 위해 사용
 time.h 헤더는 time 함수를 사용하기 위해 사용 */
void baseball();
void mainmenu();

void gamefinish() {
	printf("More games?\n\nYes : Y\nNo : N\n");
		char g;
		while(1) {
		scanf(" %c", &g);
			switch(g) {
			case 'Y' : mainmenu();
				break;
			case 'N' :
				system("clear");
				printf("Good bye!\n");				
				exit(0);
			}
		}
}

void baseball() {
   system("clear");
   printf("\n[ BASEBALL GAME ]\n");
   printf("\n----------------------------------------------\n");
   printf("[ How to Play?  ]\n");
   printf("\n\t1. Enter three numbers\n\tex) 3 4 5\n\n\t2. Then, computer prints out the result three types:\n\tball : correct number, but incorrect place\n\tstrike : both numbers and positions are correct\n\tout : all three numbers you entered are incorrect\n\n\t3. Repeat and find the answer\n");

      int a, b, c; //정답 숫자
      int aa, bb, cc; //사용자가 입력하는 숫자

      int ball = 0; //ball 갯수
      int str = 0; //strike 갯수

      int i, ia, ii; //반복문에 사용됨

      srand((unsigned int)time(NULL));

   for (ii = 0; 1; ii++) {

      a = rand() % 9+1;
      b = rand() % 9+1;
      c = rand() % 9+1;
   
      
      for (ia = 0; 1; ia++) {
         if (a == b) {
            b = rand() % 9+1;
         }
         else if (a == c) {
            c = rand() % 9+1;
         }
         else if (b == c) {
            b = rand() % 9+1;
         }

         if (b != c && a != b && a != c) {
            break;
         }
      }
   

    printf("\n----------------------------------------------\n");
    printf("[  Game Start!  ]\n");
	printf("%d %d %d\n", a, b, c);
   for (i = 0; 1; i++) {
      printf("\n 세가지 숫자를 입력하세요. ( 예. 1 2 3 )");
	printf("\n 0 0 0을 입력하면 나갑니다. : ");
      scanf("%d%d%d", &aa, &bb, &cc);
	if ((aa == bb)&&(bb == cc)&&(cc == 0)) {
		gamefinish();
	}
      
         if (aa == b || aa == c) {
            ball += 1;
         }
         else if (aa == a) {
            str += 1;
         }
         

         if (bb == a || bb == c) {
            ball += 1;
         }
         else if (bb == b) {
            str += 1;
         }
      
      
         if (cc == a || cc == b) {
            ball += 1;
         }
         else if (cc == c) {
            str += 1;
         }
      

         if (str == 3) {
            printf("\n\t 정답입니다!!! \n\n\n");
            str = 0;
            break;
         }
         else if (str >= 1 && ball >= 1) {
            printf("\n\t%dball / %dstrike", ball, str);
            ball = 0;
            str = 0;
         }
         else if (ball == 0 && str >= 1) {
            printf("\n\t%dstrike", str);
            str = 0;
         }
         else if (ball >= 1 && str == 0) {
            printf("\n\t%dball", ball);
            ball = 0;
         }
         else {
            printf("\n\tOut");
         }
      }



      if ((aa == bb) | (bb == cc) | (cc == aa)) {
         break;}
         
      
   }
}
