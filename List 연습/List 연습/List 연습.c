#include <stdio.h>
#include "ArrayList.h"

int main() {
	//ArrayList의 생성 및 초기화 //
	List list;
	int data;
	ListInit(&list);
	int i;
	int sum = 0;
	//5개의 데이터 저장//
	for (i = 1; i <= 9; i++)
		LInsert(&list, i);

	//저장된 데이터의 전체 출력//
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {        //첫번째 데이터 조회  LFirst와 LNext는 1이나 0을 반환
		printf("%d ", data);
		sum += data;

		while (LNext(&list, &data)) {    //두번째 이후의 데이터 조회
			printf("%d ", data);
			sum += data;
		}
	}
	printf("\n\n%d\n\n", sum);

	//숫자 22을 탐색하여 모두 삭제//
	if (LFirst(&list, &data)) {
		if (data %2== 0 || data%3 ==0)
			LRemove(&list);
		while (LNext(&list, &data)) {
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	//삭제 후 남은 데이터 전체 출력
	printf("현재 남은 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}