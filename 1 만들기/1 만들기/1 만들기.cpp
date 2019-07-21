#include <iostream>

using namespace std;

int main() {
	int x;
	int cnt=0;

	cin >> x;

	while (x > 1) {
		if (x % 3 == 0)
			x = x/3;
		else if ((x != 2) && (x % 2 == 0))
			x = x/2;
		else
			x = x- 1;
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}