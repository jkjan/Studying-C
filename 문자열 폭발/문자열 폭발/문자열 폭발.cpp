#include <iostream>
#include <cstring>

int main() {
	char* na = (char*)malloc(sizeof(char) * 1000001);
	char* ba = (char*)malloc(sizeof(char) * 37);

	scanf(" %s", na);
	scanf(" %s", ba);

	int nlen = strlen(na);
	int blen = strlen(ba);

	char* bombed = (char*)malloc(sizeof(char) * 1000001);

	int cur = 0;
	int same = 0;

	for (int i = 0; i < nlen; i++) {
		*(bombed + cur) = *(na + i);
		cur++;

		if (*(na + i) == *(ba + blen - 1) && (cur >= blen)) {
			for (int j = 0; j < blen; j++) {
				if (*(bombed + cur -1 - j) != *(ba + blen - 1 - j)) {
					same = 1;
					break;
				}
			}

			if (same == 0) {
				cur -= blen;
			}

			same = 0;
		}
	}
	
	*(bombed + cur) = '\0';

	if (cur == 0)
		printf("FRULA");
	else
		printf("%s", bombed);
	return 0;
}