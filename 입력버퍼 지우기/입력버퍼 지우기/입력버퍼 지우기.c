#include <stdio.h>
void ClearLineFromReadBuffer() {
	while (getchar() != '\n');  //�Է¹��۰� ���ڿ��� ������ �а� �׳� ����������.
}								//�ֳĸ� int ch = getchar(); �� �� �ϰ� �׳� ��������Ƿ�
								//���ٰ� ����ž� �ϴ��� �� ���Դ�. ���� �ƿ� ������ �� ��.

int main() {
	char perID[7];
	char name[10];

	fputs("�ֹι�ȣ �� 6�ڸ� �Է�: ", stdout);
	fgets(perID, sizeof(perID), stdin);
	ClearLineFromReadBuffer(); //�Է¹��� �����.

	fputs("�̸� �Է�: ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("�ֹι�ȣ: %s \n", perID);
	printf("�̸�: %s \n", name);

}