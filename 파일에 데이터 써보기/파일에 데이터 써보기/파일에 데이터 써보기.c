#include <stdio.h>
<<<<<<< HEAD
int main() {
	FILE *fp = fopen("data.txt", "wt");
	if (fp == NULL) {
		puts("���Ͽ��� ����!");
		return -1; //�������� ���� �ǹ�
	}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	rewind(fp);
	fputc('E', fp);
	fputc('B', fp);
	fputc('C', fp);
	fclose(fp);

	fp = fopen("data.txt", "rt");

	char d[4];
	fscanf(fp, "%s", d);
	printf("%s", d);

	fclose(fp);   //��Ʈ�� ����
	
	return 0;
}
=======

int main() {
	FILE * fp = fopen("data.txt", "wt"); //wt ���� ��Ʈ�� ����
	if (fp == NULL) {
		puts("���� ���� ����");
		return -1;  //�������� ���� �ǹ��ϱ� ���� -1 ��ȯ

	}

	fputs("Addd", fp);
	fputc('B', fp);
	fputc('C', fp);
	fclose(fp);   //��Ʈ�� ����
	return 0;
}
>>>>>>> 0ba30ea316b5ebad600bc13dc6ed51204e5f22f3
