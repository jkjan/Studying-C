#include <stdio.h>
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
