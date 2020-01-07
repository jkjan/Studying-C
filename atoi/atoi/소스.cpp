#include <iostream>
using namespace std;

int main() {
	char string[32];
	int ecx = 0;
	int eax;

	while (1) {
		eax = getchar();
		string[ecx] = eax;
		ecx++;
		if (eax == '\n')
			break;
	}
	
	string[ecx-1] = 0;
	ecx--;
	cout << string << endl;
	cout << ecx << endl;
	eax = 0;
	int ebx = 0;
	int edx = 10;

	while (1) {
		if (ebx == ecx)
			break;
		eax += string[ebx] - '0';
		eax *= edx;
		ebx++;
	}

	eax /= edx;
	cout << eax;

	return 0;
}