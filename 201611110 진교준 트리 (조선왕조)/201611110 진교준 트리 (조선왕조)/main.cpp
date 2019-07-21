#include "choseon_dynasty.h"
#include "kingstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
�ڷῡ�� ������ ������ �����ļ����� �Էµ�����
������ ������ �Ƶ��� ������ �̺�����(���ű�)�� �Ƶ�(������)�� �Ƶ�(�Ｑ�����)�� �Ƶ��
�ڷ��� ��Ģ(���� ������ ����)�� �°� ������ �Ƶ�� �ٲ���ϴ�.
*/

char** cutStrings(int n, char* string) {
	char** cut = new char*[n];
	for (int i = 0; i < n; i++) {
		cut[i] = new char[7];
	}

	int len = strlen(string);

	for (int i = len - 1; i >= 0; i--) {
		if (string[i] == ' ') {
			strcpy(cut[(n--)-1], &string[i+1]);
			string[i] = '\0';
		}
	}

	strcpy(cut[(n--) - 1], string);

	return cut;
}

stack* dynasty;
int kingcnt;
extern char bestKing[7];
extern int kingmade;
extern int upToTwo;

int main() {
	kings* taejo = new kings;
	dynasty = new stack;
	dynasty->init();

	taejo->init();
	
	FILE* fp = fopen("��������.txt", "rt");
	
	char buffer[256];
	int nchildren = 0;
	int len;
	
	while (fscanf(fp, " %[^\n]", buffer) != EOF) {
		//printf("%s \n", buffer);
		for (int i = 0; i < strlen(buffer); i++) {
			if (buffer[i] == ' ')
				nchildren++;
		}

		taejo->insert(nchildren, cutStrings(nchildren+1, buffer));
		nchildren = 0;
	}
	printf("������ ���� ������� ����Ͻÿ�. : \n");
	taejo->treeprint();
	printf("\n\n");

	printf("������ ���� �������� ����Ͻÿ�. : \n");
	while (!dynasty->is_empty()) {
		printf("%s\n", dynasty->pop());
	}

	printf("\n\n");

	printf("������ ���� ��� �� ���ΰ�? \n");
	printf("%d", kingcnt);

	printf("\n\n");

	printf("������ �� �߿��� ������ �ļ��� ���������ΰ�?\n");
	char name[7] = "����";
	taejo->get_daddy(name)->enemies->next->king->treeprint();
	

	//taejo->get_children((char*)"����");

	printf("\n\n");

	printf("���� �ļ��� ���� ���� ���� ���� ���������ΰ�?\n");
	//-> �ڷῡ �ڽ��� ���� ��� (���� �ƴ� �ڽ��� �ڷῡ ����)
	taejo->whosNotKing();

	printf("\n\n");

	printf("���� �ļ��� ���� �� ���� ���� ���� ���� �����ΰ�?\n");
	//�ڷῡ �־��� ��� �̵��� ���� ��
	taejo->theBestKingMaker();
	printf("%s", bestKing);

	printf("\n\n");


	printf("������ ������ ������ ���� �� ����� �����ΰ�?\n");
	taejo->get_enemies((char*)"����");

	printf("\n\n");


	printf("������ ���� ������ ��� ����Ͻÿ�.\n");
	strcpy(name, "����");
	while (strcmp(name, "����") != 0) {
		strcpy(name, taejo->get_daddy(name)->name);
		printf("%s\n", name);
	}
	printf("\n\n");

	printf("���� �ļ��� 2�� �̻� ���� �� ���� �� ���ΰ�?\n");
	printf("%d��\n", upToTwo);
	printf("\n\n");

	printf("������ ������ �� �� �ļ��ΰ�?\n");
	strcpy(name, "����");
	int son = 0;
	while (strcmp(name, "����") != 0) {
		strcpy(name, taejo->get_daddy(name)->name);
		son++;
	}
	printf("%d�� �ļ�\n", son);

	printf("\n\n");
	fclose(fp);
	delete(taejo);
	delete(dynasty);
}