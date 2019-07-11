#include <stdio.h>
#include <string.h>

int main() {
	char str1[20];
	char str2[20];
	char str3[20];

	gets(str1, 20, stdin);
	gets(str2, 20, stdin);

	strncpy(str3,str1, sizeof(str1) - 1);
	str3[sizeof(str3) - 1] = 0;

	strcat(str3, str2);

	fputs(str3, stdout);

	return 0;

}