//����ó���� ����

#include <stdio.h> //�̰͵� ��ũ�δ�. stdio.h��� ��������� �ڵ带 ����� ���ٳ������ ���̴�. ����� �ڵ尡 ��.��.��.��.��.
#define MAX(a, b) ((a>b) ? (a):(b))


//�������� ����
int main() {
	int num1, num2, max;
	scanf("%d", &num1);
	scanf("%d", &num2);
	max = MAX(num1, num2);

	printf("%d", max);


}