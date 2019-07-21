#include <iostream>
#include "guk.h"
using namespace std;

int main() {
	int size;
	cin >> size;

	guk *G = (guk*)malloc(sizeof(guk)*size);

	printf("입력 시작\n");

	for (int i = 0; i < size; i++) {
		cin >> G[i].name >> G[i].age;
	}

	printf("출력 시작\n");

	for (int i = 0; i < size; i++) {
		cout << G[i].name << ' ' << G[i].age << '\n';
	}
	
	free(G);
}
