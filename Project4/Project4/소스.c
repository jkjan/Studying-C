#include <stdio.h>

int main() {
	int num = 0;
	char c;

	int aorb = 1;

	double num1 = 0;
	double num2 = 0;

	int cal;

	double dot =1;

	while ((c = getchar()) != EOF) {
		if (c == '.')
			dot = 0.1;

		if (c >= '0' && c <= '9') {
			if (dot == 1) {
				if (aorb) {
					num1 *= 10;
					num1 += c - '0';
				}
				else {
					num2 *= 10;
					num2 += c - '0';
				}
			}

			else if (dot < 1) {
				if (aorb) {
					num1 += (c - '0')*dot;
					dot *= 0.1;
				}

				else {
					num2 += (c - '0')*dot;
					dot *= 0.1;
				}
			}
		}

		else if ((c < '0' || c > '9') && c != '.') {
			if (c == '*')
				cal = 1;
			else if (c == '/')
				cal = 2;
			else if (c == '+')
				cal = 3;
			else if (c == '-')
				cal = 4;
			else if (c == '%')
				cal = 5;

			aorb = 0; 
			dot = 1;
		}

		if (c == '\n') {
			switch (cal) {
			case 1: printf("%g\n", num1*num2);
				break;
			case 2: printf("%g\n", num1 / num2);
				break;
			case 3: printf("%g\n", num1 + num2);
				break;
			case 4: printf("%g\n", num1 - num2);
				break;
			case 5: printf("%d\n", (int)num1%(int)num2);
			}

			num1 = 0;
			num2 = 0;
			aorb = 1;
			dot = 1;
		}
	}
	return 0;
}