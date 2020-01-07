#include <iostream>
#include <set>
#include <queue>
#include <utility>
#include <map>

#define INF 100000000

using namespace std;

set<int>* graph;
int* dist;
bool* visited;
int from, to;
int N, M;
map<pair<int, int>, int> distChart;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

void dijkstra();

int main() {
	int depart, arrive, cost;
	int i;
	pair<int, int> edge;

	cin >> N >> M;
	N++;
	dist = new int[N];
	graph = new set<int>[N];
	visited = new bool[N];

	for (i = 0; i < M; i++) {
		cin >> depart >> arrive >> cost;
		edge = pair<int, int>(depart, arrive);
		if (distChart.count(edge) == 0 || (distChart.count(edge) == 1 && distChart[edge] > cost)) {
			distChart[edge] = cost;
			graph[depart].insert(arrive);
		}
	}

	cin >> from >> to;

	for (i = 1; i < N; i++) {
		visited[i] = false;
		edge = pair<int, int>(from, i);
		if (from == i)
			dist[i] = 0;
		else
			dist[i] = (distChart.count(edge) == 1) ? distChart[edge] : INF;
		pq.push(pair<int, int>(dist[i], i));
	}

	dijkstra();

	cout << dist[to];

	return 0;
}

void dijkstra() {
	pair<int, int> closest;
	pair<int, int> edge;

	while (!pq.empty()) {
		closest = pq.top();
		pq.pop();
		visited[closest.second] = true;

		for (set<int>::iterator itor = graph[closest.second].begin(); itor != graph[closest.second].end(); ++itor) {
			edge = pair<int, int>(closest.second, *itor);
			if (dist[*itor] > dist[closest.second] + distChart[edge]) {
				dist[*itor] = dist[closest.second] + distChart[edge];
				pq.push(pair<int, int>(dist[*itor], *itor));
			}
		}
	}
}