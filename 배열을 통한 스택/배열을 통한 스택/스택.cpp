#include "Çì´õ.h"

int main() {
	stack ass;
	stack*acc = &ass;

	acc = ass.init();

	ass.push(acc, 1);
	cout << ass.ipi(acc);


	ass.push(acc, 2);
	ass.push(acc, 3);
	ass.push(acc, 4);

	cout << '\n' <<ass.ipi(acc) <<endl;

	cout << "fuck" << endl;

	cout << ass.pop(acc);
	cout << ass.pop(acc);
	cout << ass.pop(acc);
	cout << ass.pop(acc);

	return 0;
}