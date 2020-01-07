#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<int> graph[10001];
bool visited[10001];
bool trash[10001];
int N, M, K;
int cnt = 0;

int node(int, int);
void dfs(int);

int main() {
	int r, c;
	int i, j;
	cin >> N >> M >> K;
	N++;
	M++;
	memset(visited, false, sizeof(visited));
	memset(trash, false, sizeof(trash));

	for (i = 1; i < N; i++) {
		for (j = 1; j < M; j++) {
			if (i + 1 < N) {
				graph[node(i, j)].push_back(node(i + 1, j));
				graph[node(i + 1, j)].push_back(node(i, j));
			}

			if (j + 1 < M) {
				graph[node(i, j)].push_back(node(i, j + 1));
				graph[node(i, j + 1)].push_back(node(i, j));
			}
		}
	}

	cout << endl;

	for (i = 0; i < K; i++) {
		cin >> r >> c;
		trash[node(r, c)] = true;
	}
	/*
	for (i = 1; i <= (N - 1)*(M - 1); i++) {
		if (trash[i]) {
			cout << i << " : ";
			for (vector<int>::iterator itor = graph[i].begin(); itor != graph[i].end(); ++itor) {
				if (trash[*itor])
					cout << *itor << ' ';
			}
			cout << endl;
		}
	}
	*/

	int max = 0;
	for (i = 1; i <= (N - 1)*(M - 1); i++) {
		if (!visited[i] && trash[i]) {
			cnt = 0;
			dfs(i);
			max = max > cnt ? max : cnt;
		}
	}

	cout << max;

	return 0;
}

int node(int r, int c) {
	return (r - 1) * N + c;
}

void dfs(int v) {
	visited[v] = true;
	cnt++;

	for (vector<int>::iterator itor = graph[v].begin(); itor != graph[v].end(); ++itor) {
		if (!visited[*itor] && trash[*itor]) {
			dfs(*itor);
		}
	}
}