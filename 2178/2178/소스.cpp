//============================================================================
// Name        : 2178.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 100000000

using namespace std;

int N, M;
int cnt = 1;
int** maze;
vector<int>* graph;

void check(int i, int j);
int bfs();

int main() {
	int i, j;
	char path;
	cin >> N >> M;
	maze = new int*[N];

	graph = new vector<int>[N *M+1];

	for (i = 0; i < N; i++) {
		maze[i] = new int[M];
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> path;
			maze[i][j] = path - '0';

			if (maze[i][j] == 1) {
				maze[i][j] = cnt;
				check(i, j);
				cnt++;
			}
		}
	}

	cout << bfs();

	return 0;
}

void check(int i, int j) {
	if (i - 1 >= 0) {
		if (maze[i - 1][j] != 0) {
			graph[maze[i - 1][j]].push_back(cnt);
			graph[cnt].push_back(maze[i - 1][j]);
		}
	}

	if (j - 1 >= 0) {
		if (maze[i][j - 1] != 0) {
			graph[maze[i][j - 1]].push_back(cnt);
			graph[cnt].push_back(maze[i][j - 1]);
		}
	}
}

int bfs() {
	queue<int> next;
	int n;
	next.push(1);
	int* dist = new int[cnt];
	bool* visited = new bool[cnt];

	for (int i = 1; i < cnt; i++) {
		dist[i] = 1;
		visited[i] = false;
	}

	visited[1] = true;

	while (!next.empty()) {
		n = next.front();
		next.pop();

		for (vector<int>::iterator itor = graph[n].begin(); itor != graph[n].end(); ++itor) {
			if (!visited[*itor]) {
				dist[*itor] = dist[n] + 1;
				visited[*itor] = true;
				next.push(*itor);
			}
		}
	}

	return dist[cnt-1];
}
