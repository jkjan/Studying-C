#include <stdio.h>

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