#include <Stdio.h>
struct employee {
	char name[20];
	char comp[10];
	char reg[15];
	int salary;
};


int main() {
	struct employee em1;

	fputs("�̸��� �Է��ϼ��� : ", stdout);
	scanf("%s", &em1.name);

	fputs("������ �Է��ϼ��� : ", stdout);
	scanf("%s", &em1.comp);

	fputs("�ֹι�ȣ�� �Է��ϼ��� : ", stdout);
	scanf("%s", &em1.reg);

	fputs("������ �Է��ϼ��� : ", stdout);
	scanf("%d", &em1.salary);

	printf("\n%s \n", em1.name);
	printf("%s \n", em1.comp);
	printf("%s \n", em1.reg);
	printf("%d \n", em1.salary);

	return 0;
}