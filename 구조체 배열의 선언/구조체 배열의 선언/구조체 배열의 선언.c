#include <stdio.h>
struct employee {
	char name[20];
	char comp[10];
	char reg[15];
	int salary;
};

int main() {
	struct employee arr[3];
	int i;


	for (i = 0; i < 3; i++) {
		printf("���� %d�� �̸��� �Է��ϼ��� : ", i + 1);
		scanf("%s", &arr[i].name);

		fputs("������ �Է��ϼ��� : ", stdout);
		scanf("%s", &arr[i].comp);

		fputs("�ֹι�ȣ�� �Է��ϼ��� : ", stdout);
		scanf("%s", &arr[i].reg);

		fputs("������ �Է��ϼ��� : ", stdout);
		scanf("%d", &arr[i].salary);

		printf("\n");
	}

	for (i = 0; i < 3; i++) {
		printf("\n���� %d \n", i + 1);
		printf("�̸� : %s\n", arr[i].name);
		printf("���� : %s\n", arr[i].comp);
		printf("�ֹι�ȣ : %s\n", arr[i].reg);
		printf("���� : %d\n", arr[i].salary);
		printf("\n");
	}
	return 0;
}