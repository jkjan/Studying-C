#include "Çì´õ.h"

int main() {

	que im;
	que*acc;

	int cards;

	cin >> cards;

	acc = im.init();

	
	for (int i = 0; i < cards; i++)
		im.in(acc, i + 1);

	while (cards > 1) {
		im.de(acc);
		int what = im.de(acc);
		im.in(acc, what);
		cards--;
	}

	cout << im.de(acc);

	return 0;
}