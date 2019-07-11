#include "testing.h"

int bubble(int *test, int len) {
	int *fptr;
	int *bptr;
	int temp;

	for (i = len - 1; i > 0; i--) {
		fptr = test;
		bptr = test + 1;

		for (j = 0; j < i; j++) {      //for 쓸 때 i j 쓰지 말자 구분 안 가서 무한루프 생긴다;;; 다신 안 쓴다
			if (*fptr > *bptr) {
				temp = *fptr;
				*fptr = *bptr;
				*bptr = temp;
			}
			fptr++;
			bptr++;
		}
	}
	return 0;
}