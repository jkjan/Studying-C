#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int V, E; // ���ؽ�, ������ ����
vector<int>* graph; // �׷���
bool* visited; // �湮 ����

void input(); // �׷����� �Է¹޴� �Լ�
void search(string name, void(*method)(int), int start);  // Ž���ϴ� �Լ�
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
	fill_n(visited, V, false); // �湮 �迭 �ʱ�ȭ
	cout << name << " : " << endl; // Ž�� ��� �̸��� �´� ���
	method(start); // Ž�� ��
	cout << endl;  // �� ĭ ����ش�
}

void input() {
	int from, to; // ���, ���� ���ؽ� 
	cin >> V >> E; // ���ؽ�, ������ �� �Է�
	graph = new vector<int>[V];  // �׷����� ���ؽ� ����ŭ
	visited = new bool[V]; // �湮 �迭�� ���ؽ� ����ŭ
	for (int i = 0; i < E; i++) {  // ���� ����ŭ �׷��� �Է�
		cin >> from >> to;
		graph[from].push_back(to); // ���� ���� �׷����̹Ƿ� �� �� �־��ش�
		graph[to].push_back(from);
	}
}

void dfs(int v) {
	visited[v] = true; // �湮�ߴ� üũ
	for (vector<int>::iterator itor = graph[v].begin(); itor != graph[v].end(); ++itor) { // �ش� ���ؽ��� ���� ����Ʈ�� ���Ǹ�
		if (!visited[*itor]) { // ���� �湮 �� �� ���ؽ���� 
			cout << v << " goes to " << *itor << endl; // �湮���� ����ϰ�
			dfs(*itor); // �� ���ؽ����� ���� ���� �ݺ� (���)
		}
	}
}

void bfs(int v) {
	queue<int> willVisit; // ������ �湮�� ���ؽ����� ��Ÿ���� ť
	int nowVisit; // ť�� ������ �°� ���� ���� �湮�ϰ� �ִ� ���ؽ�
	visited[v] = true;
	willVisit.push(v);
	while (!willVisit.empty()) { // ť�� ���� �ʾ��� ���� (�湮�� ���ؽ� �������� ����)
		nowVisit = willVisit.front(); // ť�� ù��°�� ����� ���ؽ��� �湮����
		willVisit.pop();

		// �׸��� �� ���ؽ��� ���� ����Ʈ�� ���ؽ����� ��� �湮�Ѵ� (��, �湮���� ���� ���ؽ���)
		for (vector<int>::iterator itor = graph[nowVisit].begin(); itor != graph[nowVisit].end(); ++itor) {
			if (!visited[*itor]) {
				// �湮���� ���� ���ؽ���� �湮���� ����ϰ� ť�� ���� �� �湮���� üũ
				cout << nowVisit << " goes to " << *itor << endl;
				willVisit.push(*itor);
				visited[*itor] = true;
			}
		}
	}
}