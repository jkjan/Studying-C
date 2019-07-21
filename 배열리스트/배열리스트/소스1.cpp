#include "d.h"

int main() {
	ada iii;
	ada* fuck = &iii;

	fuck = iii.init();

	iii.insert(fuck, 5);
	iii.insert(fuck, 2);
	iii.insert(fuck, 1);
	iii.insert(fuck, 8);
	iii.insert(fuck, 3);
	iii.insert(fuck, 5);

	iii.remove(fuck, 3);

	iii.printall(fuck);
	cout << "dd" << endl;

	cout << "dsdsdsd"<<endl;
	return 0;
}