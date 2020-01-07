#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define F1 "그래요\n"
#define F2 "음...\n"
#define F3 "ㅎㅎㅎ\n"
#define F4 "미안해\n"
#define F6 "돈이 없어\n"
#define F7 "힘들어\n"
#define F8 "힘들 것 같아\n"
#define F9 "아니야\n"
#define F10 "알았어\n"
#define F11 "ㅋㅋㅋ\n"
#define F12 "모르겠어\n"

void F5(const char* name) {
	printf("그래 %s아\n", name);
}

int main() {
	char message[256];
	char* name[4];
	name[0] = new char[32];
	strcpy(name[0], "두산");
	name[1] = new char[32];
	strcpy(name[1], "성훈");
	name[2] = new char[32];
	strcpy(name[2], "민우");
	name[3] = new char[32];
	strcpy(name[3], "교준");

	bool positive;
	int selector;
	int who;
	srand(time(NULL));

	while (1) {
		positive = rand() % 2;
		who = rand() % 4;
		printf("%s : ", name[who]);
		scanf(" %[^\n]", message);
		printf("현식 : ");
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
