#include "testing.h"

int bubble(int *test, int len) {
	int *fptr;
	int *bptr;
	int temp;

	for (i = len - 1; i > 0; i--) {
		fptr = test;
		bptr = test + 1;

		for (j = 0; j < i; j++) {      //for �� �� i j ���� ���� ���� �� ���� ���ѷ��� �����;;; �ٽ� �� ����
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