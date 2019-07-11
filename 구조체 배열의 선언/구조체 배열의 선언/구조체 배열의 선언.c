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
		printf("직원 %d의 이름을 입력하세요 : ", i + 1);
		scanf("%s", &arr[i].name);

		fputs("직장을 입력하세요 : ", stdout);
		scanf("%s", &arr[i].comp);

		fputs("주민번호를 입력하세요 : ", stdout);
		scanf("%s", &arr[i].reg);

		fputs("연봉을 입력하세요 : ", stdout);
		scanf("%d", &arr[i].salary);

		printf("\n");
	}

	for (i = 0; i < 3; i++) {
		printf("\n직원 %d \n", i + 1);
		printf("이름 : %s\n", arr[i].name);
		printf("직장 : %s\n", arr[i].comp);
		printf("주민번호 : %s\n", arr[i].reg);
		printf("연봉 : %d\n", arr[i].salary);
		printf("\n");
	}
	return 0;
}