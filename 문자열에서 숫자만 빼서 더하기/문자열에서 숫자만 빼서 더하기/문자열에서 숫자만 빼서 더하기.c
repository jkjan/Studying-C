#include <stdio.h>



int main() {
	char str[100];
	fgets(str, 100, stdin);

	int dec = 1 - '1';
	int sum=0;
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			sum += str[i] + dec;
	}

	printf("%d", sum);


}

