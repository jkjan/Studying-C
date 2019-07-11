#include <stdio.h>

int pbo(int til) {
	if (til < 3)
		return 1;

	return pbo(til - 2) + pbo(til - 1);

}

int main() {
	for (int i=1; i<11; i++)
		printf("%d ", pbo(i));
}