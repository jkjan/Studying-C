#include <stdio.h>
#include <math.h>
#include <string.h>


int main() {
	int i=0; 
	char * a = (char*)malloc(sizeof(char) * 3);
	char * b = (char*)malloc(sizeof(char) * 3);
	int ifa = 1;

	char c;
	int cal;

	while ((c = getchar()) != EOF) {
		while (c >= '0' && c <= '9' && ifa == 1) {
			ifa = 1;
			strcpy(a + i, c);
			i++;
		}
	}

	printf("%d", atoi(a));


	/*
	while (1) {
		while ((c = getchar()) != EOF) {
			while (c >= '0' && c <= '9' && ifa == 1) {
				ifa = 1;
				a[i] = c;
				i++;
			}

			ifa = 0;
			i = 0;

			if (c == '/')
				cal = 1;
			else if (c == '*')
				cal = 2;
			else if (c == '%')
				cal = 3;
			else if (c == '+')
				cal = 4;
			else if (c == '-')
				cal = 5;

			while (c >= '0' && c <= '9' && ifa == 0) {
				ifa = 0;
				b[i] = c;
				i++;
			}

			ifa = 1;
			i = 0;
		}

		switch (cal) {
		case 1: printf("%d\n", atoi(a) / atoi(b));
		case 2: printf("%d\n", atoi(a) * atoi(b));
		case 3: printf("%d\n", atoi(a) % atoi(b));
		case 4: printf("%d\n", atoi(a) + atoi(b));
		case 5: printf("%d\n", atoi(a) - atoi(b));
		}

		if (c == EOF)
			return 0;

	}

		
		a *= pow(10, (cnt - 2));

		cnt = 0;

		

		ifa = 0;

		while (c >= '0' && c <= '9' && ifa == 0) {
			ifa = 0;
			cnt--;
			b += (c - '0')*pow(10, cnt);
		}

		b *= pow(10, (cnt - 2));

		cnt = 0;


		printf("%d\n", a / b); 
		switch (cal) {
		case 1: printf("%d\n", a / b);
		case 2: printf("%d\n", a * b);
		case 3: printf("%d\n", a % b);
		case 4: printf("%d\n", a + b);
		case 5: printf("%d\n", a - b);
		}*/

	}
	
