#include <iostream>
#include <cmath>
using namespace std;

bool isEven(int N);
int tillEven(int N);

int main() {
	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << "Case #" << i+1 << ": " <<tillEven(N);
	}

	return 0;
}

bool isEven(int N) {
	int l = (int)log10(N);
	int temp;
	for (int i = l; i >= 0; i--) {
		temp = (N / (int)pow(10, i));
		if (temp % 2 == 1)
			return false;
	}
	return true;
}

int tillEven(int N) {
	int cnt = 0;
	if (isEven(N))
		return 0;
	while (1) {
		if ((N - cnt >= 0 && isEven(N - cnt)) || isEven(N + cnt))
			break;
		cnt++;
	}
	return cnt;
}
