#include "razor.h"

int main() {
	stack razor;

	stack *cut = razor.init();

	char c;

	int polc = 0;

	int cnt = 0;

	int prev = 0;

	while ((c = getchar()) != '\n') {
		if (c == '(') {
			razor.push(cut, '1');
			polc++;
			prev = 1;
		}

		else if (c == ')') {
			razor.pop(cut);
			polc--;
			if (prev == 1)
				cnt += polc;

			else if (prev == 0)
				cnt += 1;

			prev = 0;
		}
	}

	cout << cnt << endl;
}