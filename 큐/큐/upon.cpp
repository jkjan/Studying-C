#include "quentin.h"

int main() {
	que ass;
	que* acc = &ass;

	acc = ass.init();

	ass.in(acc, 1);
	ass.in(acc, 2);
	ass.in(acc, 3);
	ass.in(acc, 4);

	cout << ass.de(acc);
	cout << ass.de(acc);
	cout << ass.de(acc);
	cout << ass.de(acc);

	return 0;
}