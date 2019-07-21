#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct _alpha {
	int a;
	int c;
} alpha;

int main() {
	int num;

	cin >> num;

	int i;

	char **words = (char**)malloc(sizeof(char*)*num);

	for (int i = 0; i < num; i++) {
		*(words + i) = (char*)malloc(sizeof(char) * 100);
	}

	for (i = 0; i < num; i++) {
		cin >> *(words+i);
	}
	
	int cnt = 0;
	alpha* list = new alpha[26];

	for (int i = 97; i <= 122; i++) {
		*(list + i-97) = { i, 0 };
	}

	int fail;
	for (int i = 0; i < num; i++) {
		for (int i = 97; i <= 122; i++) {
			(list + i-97)->c = 0;
		}

		fail = 0;
		for (int j = 1; j < strlen(*(words + i)); j++) {
			if ((list + (int)*(*(words + i) + j) - 97)->c == -1) {
				fail = 1;
				break;
			}

			if (*(*(words + i) + j) != *(*(words + i) + j - 1)) {
				(list + (int)*(*(words + i) + j-1) - 97)->c = -1;
			}

		}
		if (fail != 1)
			cnt++;
	}

	cout << cnt;

	return 0;
}