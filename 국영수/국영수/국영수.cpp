#include <iostream>
#include "guk.h"
using namespace std;

int main() {
	int size;
	cin >> size;

	guk *G = (guk*)malloc(sizeof(guk)*size);

	printf("�Է� ����\n");

	for (int i = 0; i < size; i++) {
		cin >> G[i].name >> G[i].age;
	}

	printf("��� ����\n");

	for (int i = 0; i < size; i++) {
		cout << G[i].name << ' ' << G[i].age << '\n';
	}
	
	free(G);
}
