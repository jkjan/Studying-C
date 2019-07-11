#include <stdio.h>

#include <time.h>

#include <stdlib.h>

#include <conio.h>

#include <Windows.h>



void rotation_right(int m[][3]);

void move_shape(int m[][3]);

void print_shape(int m[][3]);

void move_control(int m[][3]);

void gotoxy(int x, int y);

void print_direction(void);

void stay(int m[][3]);



int x = 35, y = 12;

int inx = 0, iny = 0;



int main(void)

{

	srand((unsigned)time(NULL));

	int shape1[3][3] = { 1, 0, 0, 1, 0, 0, 1, 1, 0 };

	int shape2[3][3] = { 1, 0, 0, 1, 0, 0, 1, 0, 0 };

	int shape3[3][3] = { 1, 0, 0, 1, 1, 0, 1, 0, 0 };

	int shape4[3][3] = { 0, 0, 0, 1, 1, 0, 1, 1, 0 };

	int sel;

	while (1)

	{

		system("cls");

		sel = rand() % 4 + 1;

		switch (sel)

		{

		case 1:

			move_control(shape1);

			break;

		case 2:

			move_control(shape2);

			break;

		case 3:

			move_control(shape3);

			break;

		case 4:

			move_control(shape4);

			break;

		default:

			printf("�߸� �����ϼ̽��ϴ�\n");

			break;

		}

	}

	return 0;

}



/*

���ù� ��� �Լ� print_direction

*/

void print_direction(void)

{

	gotoxy(25, 1);

	printf("ȭ��ǥ: �̵�, �����̽� Ű:ȸ��, ���� �ٲٷ���:ESC");

}



/*

ȭ��ǥ Ű�� �̿��� ������ ���� �̵� �Լ� move_control

*/

void move_control(int m[][3])

{

	char key;

	do

	{

		while (!kbhit())

		{

			system("cls");

			move_shape(m);

		}

		key = getch();

		switch (key)

		{

		case 13: //���� �߰�

			stay(m);

			gotoxy(1, 24);

			return;

		case 32:

			rotation_right(m);

			move_shape(m);

			break;

		case 72:

			inx = 0;

			iny = -1;

			move_shape(m);

			break;

		case 75:

			inx = -1;

			iny = 0;

			move_shape(m);

			break;

		case 77:

			inx = 1;

			iny = 0;

			move_shape(m);

			break;

		case 80:

			inx = 0;

			iny = 1;

			move_shape(m);

			break;

		default:

			break;

		}

	} while (key != 27);

	printf("\n");

}



/*

������ ����ϴ� �Լ� print_shape

*/

void print_shape(int m[][3])

{

	int i, j;

	for (i = 0; i < 3; i++)

	{

		gotoxy(x, y + i);

		for (j = 0; j < 3; j++)

			if (m[i][j] == 1)

				printf("��");

			else

				printf("  ");

		printf("\n");

	}

}



/*

������ �̵���Ű�� �Լ� move_shape

*/

void move_shape(int m[][3])

{

	do

	{

		system("cls");

		print_shape(m);

		print_direction();

		x = x + inx;

		y = y + iny;

		if (y > 23)

			y = 23;

		else if (y < 2)

			y = 2;

		if (x > 75)

			x = 75;

		else if (x < 1)

			x = 1;

		Sleep(100);

	} while (!kbhit());

}



void stay(int m[][3])

{

	system("cls");

	y = 23;

	print_shape(m);

	print_direction();

	Sleep(1000);

}



void gotoxy(int x, int y)

{

	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}



void rotation_right(int m[][3])

{

	int i, j;

	int temp[3][3];

	for (i = 0; i < 3; i++)

		for (j = 0; j < 3; j++)

			temp[j][2 - i] = m[i][j];

	for (i = 0; i < 3; i++)

		for (j = 0; j < 3; j++)

			m[i][j] = temp[i][j];

}