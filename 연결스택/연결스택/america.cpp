#include "this.h"

int main() {
	stack ass;
	stack* acc = &ass;

	ass.push(acc, 1);
	ass.push(acc, 2);
	ass.push(acc, 3);
	ass.push(acc, 4);

	cout << ass.pop(acc);
	cout << ass.pop(acc);
	cout << ass.pop(acc);
	cout << ass.pop(acc);

	return 0;
}