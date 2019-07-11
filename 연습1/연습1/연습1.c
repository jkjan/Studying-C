#include <stdio.h>
#include <stdlib.h>

//�л� ������ ������ ����ü ����
typedef struct _info {
	char name[7];
	char sex;
	char loc[7];
	char major[13];
	float score;
	int height;
	int weight;

}info;

int main() {
	FILE*fp = fopen("list.txt", "rt");
	char enter;
	int line = 0;
	int i;

	//���� ���� ���� ���� Ȯ�� �޽���
	if (fp)
		puts("The file has been successfully opened\n");
	else
		puts("Failed to open the file\n");

	//������ �� �� ����
	while ((enter = fgetc(fp)) != EOF)
		if (enter == '\n')
			line++;
	line += 1; // n���� �� '\n'�� ������ n-1�̹Ƿ� 
	

	//���� �޸� �Ҵ��ϱ�
	info* smu = (info*)malloc(sizeof(info)*line);

	rewind(fp);

	//�Է� �ޱ�
	for (i = 0; i < line; i++) {
		fscanf(fp, "%s %c %s %s %f %d %d", (smu+i)->name, &(smu+i)->sex, (smu+i)->loc,
			(smu+i)->major, &(smu+i)->score, &(smu+i)->height, &(smu+i)->weight);
	}

	//����ϱ�
	for (i = 0; i < line; i++) {
		printf("%s %c %s %s %.2f %d %d\n", (smu+i)->name, (smu+i)->sex, (smu+i)->loc,
			(smu+i)->major, (smu+i)->score, (smu+i)->height, (smu+i)->weight);
	}

	free(smu);
	fclose(fp);

	return 0;
}