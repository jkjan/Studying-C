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
	scanf("%s", hex);
	printf("%d", htoi(hex));
}


int htoi(char *s) {
	int len = strlen(s);
	int n = 0;
	enum hexagon alpha;
	for (int i = len - 1; i >= 0; i--) {
		if (s[i] >= '0' && s[i] <= '9')
			n += (s[i] - '0')*(int)pow(16, len - i - 1);
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

			}
		
	}

	return n;
}