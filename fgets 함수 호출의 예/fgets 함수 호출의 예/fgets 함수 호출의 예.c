#include <stdio.h>
int main() {
	char str[100];
	int i;

	for (i = 0; i < 3; i++) {
		fgets(str, sizeof(str), stdin);    //�� 6���ڸ� ����. �� �̻� �Է½ÿ��� ������ ����.
		printf("Read %d : %s \n", i + 1, str);   //������ �� �� �ȴ�. �Է¹��� ���� + \n
	}
	return 0;
}