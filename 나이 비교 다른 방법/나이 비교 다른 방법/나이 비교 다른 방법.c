#include <stdio.h>
#include <string.h>


int main() {
	char ch1[100], ch2[100];
	fgets(ch1, sizeof(ch1), stdin); //�̸��� ���� �Է� �ޱ�
	fgets(ch2, sizeof(ch2), stdin);

	int len1 = strlen(ch1);  //���� ���
	int len2 = strlen(ch2);

	char cdec1[20], cdec2[20];  //���ڸ� ������ �����ϱ� ����
	char *fp1 = cdec1;
	char *fp2 = cdec2;

	for (int i = 0; i < len1; i++) {         //ch1 �迭�� ó������ ������ ������ ��
		if (ch1[i] == ' ') {				 //������ ������
			for (int j = i + 1; j < len1 - 1; j++) {    //�� ���� ���ں��� ����������
				*fp1 = ch1[j];                          //fp1 �ּҰ��� ����, �� cdec1 �迭�� ����.
				fp1++;                                  //fp1 �ּ� �̵�. ch1�� ���� ���� �ޱ� ����.
			}
		}
	}

	for (int i = 0; i < len2; i++) {       //���� ���� ch2���� ���� ����.
		if (ch2[i] == ' ') {
			for (int j = i+1; j < len2-1; j++) {
				*fp2 = ch2[j];
				fp2++;
			}
		}
	}

	*fp1 = '\0';							//cdec1, 2�� �ʱ�ȭ�� �迭 �ƴϹǷ� �񱳽� ������ ���� ���� ���̸� ������ �ٷ� ���������.
	*fp2 = '\0'; 

	// int lenf1 = strlen(cdec1);               ���� �� ���α׷��� ���� �ϼ��������� �ұ��ϰ� 
	// int lenf2 = strlen(cdec2);				len�� ��� �տ��ٰ��� �ּ� ���� ��� �� �߸��� ���� cdec1 �� �ڲ� �ҷ��� Ʋ�� �� �˾���.

/*	for (int i = 0; i < lenf1; i++)
		printf("%c ", cdec1[i]);
	printf("\n");
	for (int i = 0; i < lenf2; i++)
		printf("%c ", cdec2[i]); */

	printf("%d",strcmp(cdec1,cdec2));

	return 0;
}