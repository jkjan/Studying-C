//============================================================================
// Name        : 6603.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

void combination(int k);

int main() {
	int k = 6;
	while (1) {
		cin >> k;
		if (k == 0) {
			return 0;
		}
		combination(k);
		cout << '\n';
	}
	//int* S = new int[k];

	return 0;
}

void combination(int k) {
	int i;
	vector<int> S(k);
	vector<int> no(k - 5);

	for (i = 0; i < k; i++) {
		cin >> S[i];
	}

	// 0과1을 저장 할 벡터 생성
	vector<bool> ind;

	for (int i = 0; i < 6; i++) {
		ind.push_back(0);
	}

	for (int i = 0; i < k - 6; i++) {
		ind.push_back(1);
	}

	int noI = 0;
	//순열
	do {
		// 출력
		noI = 0;

		for (i = 0; i < k; i++) {
			if (ind[i] == 1) {
				//printf("%d ", S[i]);
				no[noI++] = S[i];
			}
		}
		noI = 0;
		//for (vector<int>::iterator itor = no.begin(); itor != no.end(); ++itor) {
			//cout << *itor << ' ';
		//}

		for (i = 0; i < k; i++) {
			if (S.at(i) != no.at(noI)) {
				printf("%d ", S.at(i));
			}
			else
				noI++;
		}
		printf("\n");
		//no.clear();
	} while (next_permutation(ind.begin(), ind.end()));
}
