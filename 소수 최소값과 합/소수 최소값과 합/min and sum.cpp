#include <iostream>

using namespace std;

int find(int n);

int main() {
	int M;
	int N;
	cin >> M;
	cin >> N;
	int i;
	int sum = 0;
	int min=0;
	int cnt=0;
	for (i = M; i <= N; i++) {
		if (find(i)) {
			sum += i;
			if (!min)
				min = i;
		}
		else
			cnt++;
	}

	if (cnt == N-M + 1)
		cout << -1;
	
	else {
		cout << sum << '\n';
		cout << min;
	}
	
	return 0;
}

int find(int n) {
	int i = 1;
	if (n == 1)
		return 0;
	else {
		while (i < n - 1) {
			i++;
			if (!(n%i))
				return 0;
		}
	}
	return 1;
}
