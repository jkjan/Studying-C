#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[1001];
int dfn[1001];
int low[1001];
stack<int> bcc;
int dfnCnt = 0;

void dfs(int, int);

int main() {
	int N, V;
	int d, a;
	memset(dfn, -1, sizeof(dfn));

	cin >> N >> V;

	for (int i = 0; i < V; i++) {
		cin >> d >> a;
		graph[d].push_back(a);
		graph[a].push_back(d);
	}

	dfs(3, -1);

	for (int i = 0; i < N; i++) {
		cout << dfn[i] << ' ';
	}

	return 0;
}

void dfs(int v, int f) {
	dfn[v] = low[v] = dfnCnt++;
	bcc.push(v);

	for (vector<int>::iterator itor = graph[v].begin(); itor != graph[v].end(); ++itor) {
		if (dfn[*itor] == -1) {
			dfs(*itor, v);
			low[v] = low[v] < low[*itor] ? low[v] : low[*itor];
			if (dfn[v] <= low[*itor]) {
				cout << v << " is articulation point" << endl;

				while (bcc.top() != v) {
					cout << bcc.top() << endl;
					bcc.pop();
				}
			}
		}
		else if (*itor != f) {
			low[v] = low[v] < low[*itor] ? low[v] : low[*itor];
		}
	}
}