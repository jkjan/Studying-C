#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int V, E; // 버텍스, 엣지의 개수
vector<int>* graph; // 그래프
bool* visited; // 방문 여부

void input(); // 그래프를 입력받는 함수
void search(string name, void(*method)(int), int start);  // 탐색하는 함수
void dfs(int v);
void bfs(int v);

int main() {
	input();
	search("DFS", dfs, 0);
	search("BFS", bfs, 0);
	delete[] graph;
	delete[] visited;
	return 0;
}

void search(string name, void(*method)(int), int start) {
	fill_n(visited, V, false); // 방문 배열 초기화
	cout << name << " : " << endl; // 탐색 방법 이름에 맞는 출력
	method(start); // 탐색 후
	cout << endl;  // 한 칸 띄워준다
}

void input() {
	int from, to; // 출발, 도착 버텍스 
	cin >> V >> E; // 버텍스, 엣지의 수 입력
	graph = new vector<int>[V];  // 그래프를 버텍스 수만큼
	visited = new bool[V]; // 방문 배열을 버텍스 수만큼
	for (int i = 0; i < E; i++) {  // 엣지 수만큼 그래프 입력
		cin >> from >> to;
		graph[from].push_back(to); // 방향 없는 그래프이므로 둘 다 넣어준다
		graph[to].push_back(from);
	}
}

void dfs(int v) {
	visited[v] = true; // 방문했다 체크
	for (vector<int>::iterator itor = graph[v].begin(); itor != graph[v].end(); ++itor) { // 해당 버텍스의 인접 리스트를 살피며
		if (!visited[*itor]) { // 아직 방문 안 한 버텍스라면 
			cout << v << " goes to " << *itor << endl; // 방문함을 출력하고
			dfs(*itor); // 그 버텍스에서 위의 과정 반복 (재귀)
		}
	}
}

void bfs(int v) {
	queue<int> willVisit; // 앞으로 방문할 버텍스들을 나타내는 큐
	int nowVisit; // 큐의 순서에 맞게 나와 지금 방문하고 있는 버텍스
	visited[v] = true;
	willVisit.push(v);
	while (!willVisit.empty()) { // 큐가 비지 않았을 동안 (방문할 버텍스 남아있을 동안)
		nowVisit = willVisit.front(); // 큐의 첫번째에 저장된 버텍스를 방문하자
		willVisit.pop();

		// 그리고 그 버텍스의 인접 리스트의 버텍스들을 모두 방문한다 (단, 방문하지 않은 버텍스만)
		for (vector<int>::iterator itor = graph[nowVisit].begin(); itor != graph[nowVisit].end(); ++itor) {
			if (!visited[*itor]) {
				// 방문하지 않은 버텍스라면 방문함을 출력하고 큐에 삽입 후 방문함을 체크
				cout << nowVisit << " goes to " << *itor << endl;
				willVisit.push(*itor);
				visited[*itor] = true;
			}
		}
	}
}