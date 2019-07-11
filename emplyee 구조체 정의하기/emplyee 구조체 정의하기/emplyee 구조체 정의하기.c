#include <Stdio.h>
struct employee {
	char name[20];
	char comp[10];
	char reg[15];
	int salary;
};


int main() {
	struct employee em1;

	fputs("이름을 입력하세요 : ", stdout);
	scanf("%s", &em1.name);

	fputs("직장을 입력하세요 : ", stdout);
	scanf("%s", &em1.comp);

	fputs("주민번호를 입력하세요 : ", stdout);
	scanf("%s", &em1.reg);

	fputs("연봉을 입력하세요 : ", stdout);
	scanf("%d", &em1.salary);

	printf("\n%s \n", em1.name);
	printf("%s \n", em1.comp);
	printf("%s \n", em1.reg);
	printf("%d \n", em1.salary);

	return 0;
}