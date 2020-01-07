#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector < vector <int> > graph;
bool* visited;
int a, b; // 촌수를 계산해야 하는 서로 다른 두 사람의 번호
int* distArray;

void bfs(int, deque<int>*);

int main() {
	int n; //전체 사람의 수
	int m; // 부모 자식들 간의 관계의 개수
	int u, v; // 입력되는 부모 번호
	int i; // 반복자

	cin >> n >> a >> b >> m;
	n++;
	distArray = new int[n];
	visited = new bool[n];

	for (i = 0; i < n; i++) {
		graph.push_back(vector<int>());
		visited[i] = false;
		distArray[i] = -1;
	}

	for (i = 0; i < m; i++) {
		cin >> u >> v;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	for (i = 1; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	deque <int> nodeTrace;

	bfs(a, &nodeTrace);

	cout << distArray[b];

	delete(visited);
	delete(distArray);
	return 0;
}

void bfs(int v, deque<int>* nodeTrace) {
	int nextNode;
	int distCnt = 1;
	nodeTrace->push_back(v);
	distArray[v] = 0;

	while (!nodeTrace->empty()) {
		nextNode = nodeTrace->front();
		nodeTrace->pop_front();

		for (vector<int>::iterator itor = graph[nextNode].begin(); itor != graph[nextNode].end(); ++itor) {
			if (!visited[*itor]) {
				distArray[*itor] = distArray[nextNode] + 1;

				if (*itor == b) {
					return;
				}

				visited[*itor] = 1;
				nodeTrace->push_back(*itor);
			}
		}
	}
}