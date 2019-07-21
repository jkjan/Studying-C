#include <iostream>

using namespace std;

class alpha {
public:
	int s;
	int e;
};

int main() {
	int num;
	int i;

	cin >> num;

	alpha*ship = (alpha*)malloc(sizeof(alpha)*num);

	for (i = 0; i < num; i++) {
		cin >> (ship + i)->s >> (ship + i)->e;
	}


}