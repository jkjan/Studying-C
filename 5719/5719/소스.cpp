#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

#define INF 1000000000

using namespace std;

class edge {
public:
	int node;
	int weight;
	edge(int node, int weight) {
		this->node = node;
		this->weight = weight;
	}
	edge() {};
};

bool operator < (edge a, edge b) {
	return a.weight > b.weight;
}

int makeGraph(int N, int M);
int dijkstra(list<edge>* graph, int S, int D);

int main(int argc, char** argv) {
	int N, M;
	cin >> N >> M;
	cout << makeGraph(N, M);
	return 0;
}

int makeGraph(int N, int M) {
	list<edge> graph[500];
	int i;
	int U, V, P;
	int S, D;
	cin >> S >> D;
	for (i = 0; i < M; i++) {
		cin >> U >> V >> P;
		graph[U].push_back(edge(V, P));
	}
	return dijkstra(graph, S, D);
}

int dijkstra(list<edge>* graph, int S, int D) {
	list<edge> path[500];
	int dist[500];
	priority_queue<edge> pq;
	edge close;
	list<edge>::iterator itor;
	list<edge>::iterator ritor;

	fill_n(dist, 500, INF);
	dist[S] = 0;
	pq.push(edge(S, 0));

	while (!pq.empty()) {
		close = pq.top();
		pq.pop();
		for (itor = graph[close.node].begin(); itor != graph[close.node].end(); ++itor) {
			if (dist[itor->node] > dist[close.node]+ itor->weight) {
				dist[itor->node] = dist[close.node] + itor->weight;
				path[itor->node].resize(path[close.node].size());
				path[itor->node].assign(path[close.node].begin(), path[close.node].end());
				path[itor->node].push_back(edge(close.node, itor->node));
				pq.push(edge(itor->node, dist[itor->node]));
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		cout << i << " : ";
		for (list<edge>::iterator itor = path[i].begin(); itor != path[i].end(); ++itor) {
			cout << "(" << itor->node << "-" << itor->weight << ")" << ' ';
		}
		cout << endl;
	}

	for (itor = path[D].begin(); itor != path[D].end(); ++itor) {
		for (ritor = graph[itor->node].begin(); ritor != graph[itor->node].end(); ritor++) {
			if (ritor->node == itor->weight) 
				graph[itor->node].erase(ritor++);
		}
	}

	cout << endl;

	for (int i = 0; i < 7; i++) {
		cout << i << " : ";
		for (list<edge>::iterator itor = graph[i].begin(); itor != graph[i].end(); ++itor) {
			cout << "(" << itor->node << ", " << itor->weight << ")" << ' ';
		}
		cout << endl;
	}

	return dist[D];
}
