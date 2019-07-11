#include <stdio.h>
#include <stdlib.h>
#include "testing.h"

int main() {
	int tar, result;
	int*test = input();

	bubble(test, quan);

	printf("\n뭘 찾을까요? : ");
	scanf("%d", &tar);

	result = binsch(test, quan, tar, 0, quan-1);

	for (i = 0; i < quan; i++)
		printf("%d ", *(test + i));

	if (result == -1)
		puts("\n\n그런 숫자 없습니다");
	else
		printf("\n\n찾으시는 숫자는 %d번째에 있습니다.", result+1);
}