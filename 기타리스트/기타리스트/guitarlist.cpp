#include <iostream>
#include <cstdlib>
#include <math.h>

/*
class tree {
private:
	int a;
	tree* lchild;
	tree* rchild;
public:
	void init();
	void add(int v, int leaf);
};

void tree::init() {
	
}

void tree::add(int v, int leaf) {

}
*/

int leaf;

int main() {
	int N, S, M;
	scanf("%d %d %d", &N, &S, &M); //개수, 시작볼륨, 최대볼륨

	//tree* Tree = (tree*)malloc(sizeof(tree));
	int* list = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++) {
		std::cin >> list[i];
	}

	int *vol = (int*)malloc(sizeof(int)*pow(2, N+1));
	int max = S;
	vol[1] = S;
	int k;
	int V;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < pow(2, i); j++) {
			k = pow(2, i);
			std::cout << k + j << std::endl;

			if (j % 2 == 0 && (V = vol[(k + j) / 2] - list[i - 1]) >= 0) {
				if (V > max)
					max = V;
				vol[k + j] = V;
				std::cout << vol[(k + j) / 2] << "의 아들 " << list[i - 1] << "뺀다? " << V <<  std::endl;
			}

			else if (j % 2 == 0 && (V = vol[(k + j) / 2] + list[i - 1]) <= M) {
				if (V > max)
					max = V;
				vol[k + j] = V;
				std::cout << vol[(k + j) / 2] << "의 아들 " << list[i - 1] << "더한다? " << V << std::endl;
			}
 			//vol[k + j] = (j%2 == 0) ? vol[(k + j)/2] - list[i-1] : vol[(k + j) / 2] + list[i-1];
		}
		std::cout << std::endl;
	}

	for (int i = 1; i < pow(2, N + 1); i++)
		std::cout << vol[i] << ' ';
	std::cout << std::endl;
	std::cout << "최대값 : " << max;
}
