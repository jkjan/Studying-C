#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <Windows.h>

int leaf;

int main() {
	int N, S, M;
	scanf("%d %d %d", &N, &S, &M);

	int* list = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++) {
		std::cin >> list[i];
	}

	int *vol = (int*)malloc(sizeof(int)*(int)pow(2, N + 1));
	int max = S;
	vol[1] = S;
	int k;
	int V;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < pow(2, i); j++) {
			k = (int)pow(2, i);
			std::cout << k + j << std::endl;

			if (j % 2 == 0 && (V = vol[(k + j) / 2] - list[i - 1]) >= 0) {
				if (V > max)
					max = V;
				vol[k + j] = V;
			}

			else if (j % 2 == 1 && (V = vol[(k + j) / 2] + list[i - 1]) <= M) {
				if (V > max)
					max = V;
				vol[k + j] = V;
			}
		}
	}

	return 0;
}