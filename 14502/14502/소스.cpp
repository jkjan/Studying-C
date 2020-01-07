#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node {
public:
	int y;
	int x;
	node(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

vector<node> wallCan;
vector<int> graph[81];
vector<int> virus;
int lab[8][8];
int labBack[8][8];
int visited[81];

int N, M; // 세로, 가로
int safeZone = 0; // 안전지역
int safeZoneBack = 0;

int nodeNumConverter(int i, int j);
void dfs(int);
void graphDrawer();
void reset();

int main() {
	int i, j; // 반복자
	int max = 0;
	vector<int>::iterator itor;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> lab[i][j];

			if (lab[i][j] == 0) {
				safeZone++;
				wallCan.push_back(node(i, j));
			}

			if (lab[i][j] == 2) {
				virus.push_back(nodeNumConverter(i, j));
			}
		}
	}

	graphDrawer();

	bool* com = new bool[safeZone];
	
	for (i = 0; i < safeZone - 3; i++) {
		com[i] = 0;
	}

	for (i = safeZone - 3; i < safeZone; i++) {
		com[i] = 1;
	}

	do {
		reset();

		for (i = 0; i < safeZone; i++) {
			if (com[i]) {
				labBack[wallCan[i].y][wallCan[i].x] = 1;
				visited[nodeNumConverter(wallCan[i].y, wallCan[i].x)] = 2;
			}
		}

		for (itor = virus.begin(); itor != virus.end(); ++itor) {
			if (visited[*itor] > 0) {
				dfs(*itor);
			}
		}

		max = safeZoneBack - 3 > max ? safeZoneBack - 3 : max;

	} while (next_permutation(com, com+safeZone));

	cout << max;

	return 0;
}

int nodeNumConverter(int i, int j) {
	return i * M + j;
}

void dfs(int v) {
	visited[v] *= -1;

	for (vector<int>::iterator itor = graph[v].begin(); itor != graph[v].end(); ++itor) {
		if (visited[*itor] == 1) {
			safeZoneBack--;
			dfs(*itor);
		}
	}
}

void graphDrawer() {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (j < M - 1) {
				graph[i*M + j].push_back(i*M + j + 1);
				graph[i*M + j + 1].push_back(i*M + j);
			}
			if (i < N - 1) {
				graph[i*M + j].push_back((i + 1)*M + j);
				graph[(i + 1)*M + j].push_back(i*M + j);
			}
		}
	}
}

void reset() {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			labBack[i][j] = lab[i][j];
			visited[nodeNumConverter(i, j)] = lab[i][j]+1;
		}
	}

	safeZoneBack = safeZone;
}