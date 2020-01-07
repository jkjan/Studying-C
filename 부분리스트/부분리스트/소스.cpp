#include <iostream>

using namespace std;

int max_subsequence(int n, int* S);

int main() {
	int S[] = {5, 15, -30, 10, -5, 40, 10};
	cout << max_subsequence(7, S);
}

int max_subsequence(int n, int* S) {
	int max_so_far = S[0];
	int max_ending_here = S[0];

	for (int i = 1; i < n; i++) {
		max_ending_here += S[i];
		if (S[i] > max_ending_here)
			max_ending_here = S[i];
		if (max_ending_here > max_so_far)
			max_so_far = max_ending_here;
	}
	return max_so_far;
}