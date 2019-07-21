#include "d.h"

int main() {
	ada iii;
	ada* fuck = &iii;

	fuck = iii.init();

	iii.insert(fuck, 5);
	iii.insert(fuck, 2);
	iii.insert(fuck, 1);

	iii.remove(fuck, 2);

	iii.printall(fuck);
	cout << "dd" << endl;
	cout << "sds" << endl;

	delete (fuck);

	return 0;
}