#include <stdio.h>

#include <stdlib.h>

#include <string.h>



int total = 0;



struct pbook {

	char name[30];

	char num[20];

}num[100];



void load() // 기존 파일 불러오기

{

	char temp[30];





	FILE *file = fopen("phonebook.txt", "rt"); // 읽기모드로 불러오기

	if (file == NULL)

	{

		printf("file open error!\n");

		return;

	}



	while (1)

	{

		if (feof(file) != 0)

			break;



		fgets(temp, sizeof(temp), file); // 첫번째줄의 이름을 읽고

		strcpy(num[total].name, temp); // total번째 구조체의 이름에 저장

		fgets(temp, sizeof(temp), file); // 두번째줄의 번호를 읽고

		strcpy(num[total].num, temp); // total번째 구조체의 번호에 저장

		total++;



	}



	total--; // 마지막에 \n을 읽어들여 하나의 공백이 생기기때문에 공백 삭제



	fclose(file);





}



void save() // 저장 함수

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

		fputs(num[i].name, file); // 이름 먼저 저장

		fputs(num[i].num, file); // 이어 번호 저장

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

	printf("삭제할 사람의 이름 입력 : ");

	fgets(temp, sizeof(temp), stdin);

	for (i = 0; i < total; i++)

	{

		if (strcmp(temp, num[i].name) == 0)

		{

			printf("Name : %s\nTel : %s\n위의 사람을 삭제하시겠습니까?(y/n)", num[i].name, num[i].num);

			scanf("%c", &com);

			if (com == 'y')

			{

				strcpy(num[i].name, num[total - 1].name);

				strcpy(num[i].num, num[total - 1].num);

				printf("삭제되었습니다.\n");

				total--;

				return;

			}

			else if (com == 'n')

			{

				return;

			}



		}

	}

	printf("검색 결과가 없습니다.\n");

}



void Search()

{

	char temp[30];

	int i;

	printf("[Search]\n");

	printf("찾을 사람의 이름 입력 : ");

	fgets(temp, sizeof(temp), stdin);

	for (i = 0; i < total; i++)

	{

		if (strcmp(temp, num[i].name) == 0)

		{

			printf("검색 결과\nName : %s\nTel : %s\n", num[i].name, num[i].num);

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
