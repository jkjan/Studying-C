#include <stdio.h>

int main() {
	char perID[7];
	char name[10];

	fputs("�ֹι�ȣ �� 6�ڸ� �Է�: ", stdout);
	fgets(perID, sizeof(perID), stdin);

	fputs("�̸� �Է�: ", stdout);
	fgets(name, sizeof(name), stdin);   //�Է��� ��ȸ�� �Ҿ������. �ֳ��ϸ� �տ��� ����6�ڸ� + ���͸� ������ perID�� ũ�Ⱑ 6�̾
										//���Ͱ� ���´�. ���� �� fgets���� �ٷ� ���͸� �о������ ���� �ٲ�� �ȴ�.
	printf("�ֹι�ȣ: %s \n", perID);
	printf("�̸�: %s \n", name);
	return 0;
}