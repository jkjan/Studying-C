#include <stdio.h>
#include <string.h>

void RemoveBSN(char str[]) {
	int len = strlen(str);
	str[len - 1] = 0;    //���� ��ü�� �η� ����.
}

int main() {
	char str[100];
	printf("���ڿ� �Է�: ");
	fgets(str, sizeof(str), stdin);
	printf("���� : %d, ����: %s \n", strlen(str), str);  //���� ���Ͱ� ���Եż� ���� ���ڼ����� �ϳ� �� ����.

	RemoveBSN(str);        //�� : ������ �ϰ� ���� ĥ �ÿ� str�� ������\n\0 �� �����.
	printf("����: %d, ����: %s \n", strlen(str), str);
	return 0;
}