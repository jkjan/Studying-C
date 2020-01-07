#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int);

int main() {
	int N, V;
	int f, t;
	int i;
	cin >> N >> V;

	for (i = 0; i < V; i++) {
		cin >> f >> t;
		graph[f].push_back(t);
		graph[t].push_back(f);
	}

	dfs(1);

	return 0;
}

void dfs(int v) {
	visited[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]]) {
			cout << v << " to " << graph[v][i] << endl;
			dfs(graph[v][i]);
		}
	}

	for (vector<int>::iterator itor = graph[v].begin(); itor != graph[v].end(); ++itor) {
		if (!visited[*itor]) {
			cout << v << " to " << *itor << endl;
			dfs(*itor);
		}
	}
}