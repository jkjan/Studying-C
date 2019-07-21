#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int num, i, j;

	cin >> num;

	char** words = (char**)malloc(sizeof(char*) * num);

	for (int i = 0; i < num; i++) {
		*(words + i) = (char*)malloc(sizeof(char) * 100);
	}

	for (i = 0; i < num; i++) {
		cin >> *(words + i);
	}
	
	int same = 0;

	int len = strlen(*words);
	char* pattern = (char*)malloc(sizeof(char) * (len+1));
	for (i = 0; i < len; i++)
		*(pattern + i) = '?';
	
	for (i = 0; i < len; i++) {
		same = 0;
		for (j = 0; j < num-1; j++) {
			if (*(*(words + j) + i) != *(*(words + j + 1) + i)) {
				same = 1;
				break;
			}
		}
		if (same == 0)
			*(pattern + i) = *(*(words + j) + i);
	}

	*(pattern + i) = '\0';

	cout << pattern << endl;

	return 0;
}