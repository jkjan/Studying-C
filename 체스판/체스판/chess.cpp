#include <iostream>

using namespace std;

int main() {
	char chess[9][9];
	
	for (int i = 0; i < 8; i++) {
		cin >> *(chess + i);
	}

	int cnt = 0;
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				if (*(*(chess + i) + j) == 'F')
					cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}