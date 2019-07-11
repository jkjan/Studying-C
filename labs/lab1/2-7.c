#include <stdio.h>
#include <string.h>
#include <math.h>

enum hexagon {
	A = 10,
	B,
	C,
	D,
	E,
	F
};

int htoi(char *s);

int main() {
	char hex[30];
	printf("input hexagon number : ");
	scanf("%s", hex);
	printf("the decimal number is : ");
	printf("%d\n", htoi(hex));
}


int htoi(char *s) {
	int len = strlen(s);
	int n = 0;
	enum hexagon alpha;

	for (int i = len-1; i >= 0; i--) {
		//to clarify that the character is a number or an alphabet
		if (s[i] >= '0' && s[i] <= '9')
			n += (s[i] - 48)*(int)pow(16, len - i - 1);
			// number * 16^n
			
		else if (s[i] >= 'A' && s[i] <= 'F') {
			if (s[i] == 'A') 
				n += A * ((int)pow(16, len - i - 1));
			if (s[i] == 'B')
				n += B * ((int)pow(16, len - i - 1));
			if (s[i] == 'C')

				n += C * ((int)pow(16, len - i - 1));
			if (s[i] == 'D')
				n += D * ((int)pow(16, len - i - 1));
			if (s[i] == 'E')
				n += E * ((int)pow(16, len - i - 1));
			if (s[i] == 'F')
				n += F * ((int)pow(16, len - i - 1));

			// alphabet * 16 ^n



			}
		
	}

	return n;
}
