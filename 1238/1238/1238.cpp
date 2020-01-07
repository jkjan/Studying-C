#include <stdio.h>
#include <queue>
#include <map>
#include <utility>
#include <vector>

#define INF 1000000000

using namespace std;

map<pair<int, int>, int> weight;
int N, M, X;

int* dijkstra(vector<int>*, bool);
vector<int>* reverse(vector<int>*);

int main() {
	int f, t, c;
	int i;
	pair<int, int> e;
	scanf("%d %d %d", &N, &M, &X);

	N++;

	vector<int>* graph = new vector<int>[N];

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &f, &t, &c);
		e = pair<int, int>(f, t);
		if (weight.count(e) == 0 || (weight.count(e) == 1 && weight[e] > c)) {
			weight[e] = c;
			graph[f].push_back(t);
		}
	}
	
	vector<int>* reversed = reverse(graph);

	int max = 0;
	int sum = 0;
	int path;
	
	int* go = dijkstra(graph, false);
	int* back = dijkstra(reversed, true);

	for (i = 0; i < N; i++) {
		sum = go[i];
		sum += back[i];

		max = max > sum ? max : sum;
	}

	printf("%d", max);

	return 0;
}

int* dijkstra(vector<int>* graph, bool r) {
	int* dist = new int[N];
	pair<int, int> closest;
	pair<int, int> e;
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	int i;

	for (i = 1; i < N; i++) {
		if (!r)
			e = pair<int, int>(X, i);
		else
			e = pair<int, int>(i, X);

		dist[i] = (weight.count(e)) ? weight[e] : INF;
		pq.push(pair<int, int>(dist[i], i));
	}

	dist[X] = 0;

	while (!pq.empty()) {
		closest = pq.top();
		pq.pop();

		for (vector<int>::iterator itor = graph[closest.second].begin(); itor != graph[closest.second].end(); ++itor) {
			if (!r)
				e = pair<int, int>(closest.second, *itor);
			else
				e = pair<int, int>(*itor, closest.second);

			if (dist[*itor] > weight[e] + dist[closest.second]) {
				dist[*itor] = weight[e] + dist[closest.second];
				pq.push(pair<int, int>(dist[*itor], *itor));
			}
		}
	}

	return dist;
}

vector<int>* reverse(vector<int>* graph) {
	vector<int>* reversed = new vector<int>[N];
	int i;
	for (i = 1; i < N; i++) {
		for (vector<int>::iterator itor = graph[i].begin(); itor != graph[i].end(); ++itor) {
			reversed[*itor].push_back(i);
		}
	}
	return reversed;
}