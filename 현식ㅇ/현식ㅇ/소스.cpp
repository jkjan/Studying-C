#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define F1 "�׷���\n"
#define F2 "��...\n"
#define F3 "������\n"
#define F4 "�̾���\n"
#define F6 "���� ����\n"
#define F7 "�����\n"
#define F8 "���� �� ����\n"
#define F9 "�ƴϾ�\n"
#define F10 "�˾Ҿ�\n"
#define F11 "������\n"
#define F12 "�𸣰ھ�\n"

void F5(const char* name) {
	printf("�׷� %s��\n", name);
}

int main() {
	char message[256];
	char* name[4];
	name[0] = new char[32];
	strcpy(name[0], "�λ�");
	name[1] = new char[32];
	strcpy(name[1], "����");
	name[2] = new char[32];
	strcpy(name[2], "�ο�");
	name[3] = new char[32];
	strcpy(name[3], "����");

	bool positive;
	int selector;
	int who;
	srand(time(NULL));

	while (1) {
		positive = rand() % 2;
		who = rand() % 4;
		printf("%s : ", name[who]);
		scanf(" %[^\n]", message);
		printf("���� : ");
		if (positive) {
			selector = rand() % 9 + 1;
			switch (selector) {
			case 1:
				printf(F1);
				break;
			case 2:
				printf(F2);
				break;
			case 3:
				printf(F3);
				break;
			case 4:
				printf(F6);
				break;
			case 5:
				F5(name[who]);
				break;
			case 6:
				printf(F10);
				break;
			case 7:
				printf(F11);
				break;
			case 8:
				printf(F12);
				break;
			case 9 :
				printf("\n");
				break;
			default:
				break;
			}
		}

		else {
			selector = rand() % 5 + 1;
			switch (selector) {
			case 1:
				printf(F7);
				break;
			case 2:
				printf(F8);
				break;
			case 3:
				printf(F9);
				break;
			case 4:
				printf(F4);
				break;
			case 5:
				printf("\n");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}
