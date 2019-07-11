#include <stdio.h>

#include <stdlib.h>

#include <string.h>



int total = 0;



struct pbook {

	char name[30];

	char num[20];

}num[100];



void load() // ���� ���� �ҷ�����

{

	char temp[30];





	FILE *file = fopen("phonebook.txt", "rt"); // �б���� �ҷ�����

	if (file == NULL)

	{

		printf("file open error!\n");

		return;

	}



	while (1)

	{

		if (feof(file) != 0)

			break;



		fgets(temp, sizeof(temp), file); // ù��°���� �̸��� �а�

		strcpy(num[total].name, temp); // total��° ����ü�� �̸��� ����

		fgets(temp, sizeof(temp), file); // �ι�°���� ��ȣ�� �а�

		strcpy(num[total].num, temp); // total��° ����ü�� ��ȣ�� ����

		total++;



	}



	total--; // �������� \n�� �о�鿩 �ϳ��� ������ ����⶧���� ���� ����



	fclose(file);





}



void save() // ���� �Լ�

{

	FILE *file = fopen("phonebook.txt", "wt");

	if (file == NULL)

	{

		printf("file open error!\n");

		return;

	}



	char temp[30];

	int i;



	for (i = 0; i < total; i++)

	{

		fputs(num[i].name, file); // �̸� ���� ����

		fputs(num[i].num, file); // �̾� ��ȣ ����

	}



	printf("Save Complete\n");



	fclose(file);



}





void Insert()

{

	printf("[INSERT]\n");

	printf("Input Name:");

	fgets(num[total].name, sizeof(num[total].name), stdin);

	printf("Input Tel Number:");

	fgets(num[total].num, sizeof(num[total].num), stdin);

	printf("--------> Data Inserted\n");

	total++;

}



void Delete()

{

	char temp[30];

	int i;

	char com;

	printf("[Delete]\n");

	printf("������ ����� �̸� �Է� : ");

	fgets(temp, sizeof(temp), stdin);

	for (i = 0; i < total; i++)

	{

		if (strcmp(temp, num[i].name) == 0)

		{

			printf("Name : %s\nTel : %s\n���� ����� �����Ͻðڽ��ϱ�?(y/n)", num[i].name, num[i].num);

			scanf("%c", &com);

			if (com == 'y')

			{

				strcpy(num[i].name, num[total - 1].name);

				strcpy(num[i].num, num[total - 1].num);

				printf("�����Ǿ����ϴ�.\n");

				total--;

				return;

			}

			else if (com == 'n')

			{

				return;

			}



		}

	}

	printf("�˻� ����� �����ϴ�.\n");

}



void Search()

{

	char temp[30];

	int i;

	printf("[Search]\n");

	printf("ã�� ����� �̸� �Է� : ");

	fgets(temp, sizeof(temp), stdin);

	for (i = 0; i < total; i++)

	{

		if (strcmp(temp, num[i].name) == 0)

		{

			printf("�˻� ���\nName : %s\nTel : %s\n", num[i].name, num[i].num);

		}



	}







}



void Print()

{

	int i;

	printf("[Print All Data]\n");

	for (i = 0; i < total; i++)

		printf("Name: %s\nTel : %s\n", num[i].name, num[i].num);



}





int main()

{

	load();



	int com = 0;

	while (com != 5)

	{

		printf("---------Menu--------\n");

		printf("             1. Insert\n");

		printf("             2. Delete\n");

		printf("             3. Search\n");

		printf("             4. Print All\n");

		printf("             5. Exit\n");

		printf("Choose the item:");

		scanf("%d", &com);

		fflush(stdin);

		switch (com) {

		case 1: Insert();

			break;

		case 2: Delete();

			break;

		case 3: Search();

			break;

		case 4: Print();

			break;

		case 5: save();

			system("pause");

			return 0;

		}



	}



}
