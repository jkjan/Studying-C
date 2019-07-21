#include <iostream>
#include <stdlib.h>
using namespace std;

int find(int n);

int main() {
	int i;
	int num;
	int cnt = 0;
	cin >> num;
	int*tot = (int*)malloc(sizeof(int)*num);

	for (i = 0; i < num; i++) {
		cin >> tot[i];
	}

	for (i = 0; i < num; i++) {
		if (find(tot[i]))
			cnt++;
	}

	cout << cnt;

	free(tot);

	return 0;
}

int find(int n) {
	int i=1;
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

