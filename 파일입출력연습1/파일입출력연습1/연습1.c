#include <stdio.h>
#include <stdlib.h>

//�л� ������ ������ ����ü ����
typedef struct _info {
	char name[10];
	char sex;
	char loc[10];
	char major[50];
	float score;
	int height;
	int weight;

}info;

int main() {
	FILE*fp = fopen("list.txt", "rt");
	char enter;
	int line = 0;
	int i;

	if (fp == NULL)
		puts("NO FILE EXISTS\n");
	else
		puts("FILE READ SUCCEEDED\n");

	//������ �� �� ����
	while ((enter = fgetc(fp)) != EOF)
		if (enter == '\n') 
			line++;

	//printf("%d", line);

	//���� �޸� �Ҵ��ϱ�
	info* smu = (info*)malloc(sizeof(info)*line);

	rewind(fp);

	//�Է� �ޱ�
	for (i = 0; i < line; i++) {
		fscanf("%s %c %s %s %.2f %d %d", smu->name, smu->sex, smu->loc,
			smu->major, &smu->score, &smu->height, &smu->weight);
		smu++;
	}

	//����ϱ�
	for (i = 0; i < line; i++) {
		printf("%s %c %s %s %.2f %d %d\n", smu->name, smu->sex, smu->loc,
			smu->major, &smu->score, &smu->height, &smu->weight);
		smu++;
	}

	free(smu);
	fclose(fp);


}