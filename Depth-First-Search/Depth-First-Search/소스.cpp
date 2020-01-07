#include <iostream>
#include <vector>

using namespace std;

bool visited[1001];
vector<int> graph[1001];

void dfs(int v);

int main() {
	int N, V;
	int f, t;
	cin >> N >> V;

	for (int i = 0; i < V; i++) {
		cin >> f >> t;
		graph[f].push_back(t);
		graph[t].push_back(f);
	}

	dfs(1);
	return 0;
}

void dfs(int v) {
	visited[v] = true;
	vector<int>::iterator itor;

	for (itor = graph[v].begin(); itor != graph[v].end(); ++itor) {
		if (!visited[*itor]) {
			cout << "visited " << v << " to " << *itor << endl;
			dfs(*itor);
		}
	}
}