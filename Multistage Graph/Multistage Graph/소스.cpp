#include <iostream>
#include <algorithm>

#define MAX_INPUT 1000

using namespace std;

int table[MAX_INPUT][MAX_INPUT + 1];
int memo[MAX_INPUT][MAX_INPUT + 1];
int N, T; // 자원 수, 팀 수,
int V(int i, int j);

int main() {
	int i, j; // 반복자
	cin >> N >> T;
	for (i = 0; i < N; i++) {
		for (j = 1; j <= T; j++) {
			cin >> table[i][j];
		}
	}
	for (i = 0; i < MAX_INPUT; i++)
		fill_n(*(memo + i), MAX_INPUT + 1, -1);

	cout << V(1, 0);
}

int V(int i, int j) {
	if (i == T) {
		return table[N-j][i];
	}
	int maxP = 0;
	for (int k = 0; k <= N - j; k++) {
		if (memo[i + 1][j + k] == -1) {
			memo[i + 1][j + k] = V(i + 1, j + k);
		}
		maxP = max(maxP, table[k][i] + memo[i + 1][j + k]);
	}
	return maxP;
}