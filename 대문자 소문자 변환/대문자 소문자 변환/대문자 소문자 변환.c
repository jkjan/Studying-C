#include <stdio.h>

char convert(char c) {
	int diff = 'a' - 'A';

	if (c >= 'a' && c <= 'z')
		return (c - diff);
	else if (c >= 'A' && c <= 'Z')
		return (c + diff);
	else
		return -1;
		
}


int main() {
	int ch;
	ch = getchar();

	
	ch = convert(ch);

	if (ch == -1)
		printf("유효한 값을 입력해주세요.");
	else
		putchar(ch);
	return 0;
}