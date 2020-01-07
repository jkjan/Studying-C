#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

bool* visited;
vector < vector <int> > graph;
map < pair<int, int>, int> food;

int getWorm();
void dfs(int);
int surroundCheck(int, int, int*);

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cout << getWorm() << endl;
		graph.clear();
		food.clear();
	}

	return 0;
}

void dfs(int v) {
	visited[v] = true;
	for (vector< int >::iterator itor = graph[v].begin(); itor != graph[v].end(); ++itor) {
		if (!visited[*itor]) {
			dfs(*itor);
		}
	}
}

int surroundCheck(int y, int x, int* checker) {
	pair<int, int> pos = pair<int, int>(y + checker[0], x + checker[1]);
	return food.count(pos) ? food[pos] : -1;
}

int getWorm() {
	int N, M, K; //세로 길이, 가로 길이, 음식물 쓰레기의 개수
	int r, c; //음식물 좌표
	int i, j; // 반복자
	int max = 0;
	int posNum;
	int checker[4][2] = {
		{-1 , 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};

	cin >> N >> M >> K;

	visited = new bool[K];

	for (i = 0; i < K; i++) {
		graph.push_back(vector< int >());
		visited[i] = false;
	}

	for (i = 0; i < K; i++) {
		cin >> r >> c;
		food[pair<int, int>(r, c)] = i;
		for (j = 0; j < 4; j++) {
			if ((posNum = surroundCheck(r, c, checker[j])) != -1) {
				graph[i].push_back(posNum);
				graph[posNum].push_back(i);
			}
		}
	}

	int cnt = 0;
	for (i = 0; i < K; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	delete(visited);
	return cnt;
}