//============================================================================
// Name        : 4963.cpp
// Author      : Kyojun
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cstdlib>

using namespace std;

void print(vector< list<int> > graph);
int dfs(int v, vector< list<int> >* graph);
int getTheNumberOfIslands(int h, int w, int** island);

int* visited;

int main() {
	int w, h;

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;

		int ** island = new int*[h];
		for (int i = 0; i < h; i++)
			island[i] = new int[w];

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> island[i][j];
			}
		}
		getTheNumberOfIslands(h, w, island);
	}

	return 0;
}


int getTheNumberOfIslands(int h, int w, int** island) {
	//don't forget to swap the input numbers
	//int w, h;
	//w = 5, h = 4;
	/*int island[h][w] = {{1, 0, 1, 0, 0},
					{1, 0, 0, 0, 0},
					{1, 0, 1, 0, 1},
					{1, 0, 0, 1, 0}
				   };*/
				   /*for (int i = 0; i<h; i++) {
					  for (int j = 0; j<w; j++)
						 cout << island[i][j] <<' ';
					  cout<<'\n';
				   }*/

	vector< list<int> > graph;
	int node;
	int land = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (island[i][j] == 1) {
				//cout << "at " << i << ", " << j << " : "<< land << '\n';
				graph.push_back(list<int>());
				//cout << '\n';

				if (i > 0) { //there is a space up above
					if (island[i - 1][j] != 0) {
						if (island[i - 1][j] == -1)
							node = 0;
						else
							node = island[i - 1][j];
						graph.at(node).push_back(land);
						graph.at(land).push_back(node);
					}
				}
				if (j > 0) { //there is a space left
					if (island[i][j - 1] != 0) {
						if (island[i][j - 1] == -1)
							node = 0;
						else
							node = island[i][j - 1];
						graph.at(node).push_back(land);
						graph.at(land).push_back(node);
					}
				}
				if (i > 0 && j > 0) { //there is a space
					if (island[i - 1][j - 1] != 0) {
						if (island[i - 1][j - 1] == -1)
							node = 0;
						else
							node = island[i - 1][j - 1];
						graph.at(node).push_back(land);
						graph.at(land).push_back(node);
					}
				}
				if (i > 0 && j < 4) { //there is a space
					if (island[i - 1][j + 1] != 0) {
						if (island[i - 1][j + 1] == -1)
							node = 0;
						else
							node = island[i - 1][j + 1];
						graph.at(node).push_back(land);
						graph.at(land).push_back(node);
					}
				}
				if (land == 0)
					island[i][j] = -1;
				else
					island[i][j] = land;
				land++;
			}
		}
	}
	/*
	   for (int i = 0; i<h; i++) {
			 for (int j = 0; j<w; j++)
				cout << island[i][j] <<' ';
			 cout<<'\n';
	   }*/

	   //cout << '\n';

	   //print(graph);

	   //graph complete

	visited = new int[land];
	for (int i = 0; i < land; i++) {
		visited[i] = 0;
	}

	//visited[0] = 1;
	int cnt = 0;
	for (int i = 0; i < land; i++) {
		if (visited[i] == 0) {
			dfs(i, &graph);
			//printf("\n");
			cnt++;
		}
	}

	cout << cnt;
	int maxGraphSize = sizeof(vector< list<int> >) + (sizeof(list<int>) + sizeof(int) * 8) * 50;
	int maxIslandSize = sizeof(int) * 2500;
	//printf("\nMax graph size %d \n", maxGraphSize);
	//printf("Max island size %d\n", maxIslandSize);
	delete(visited);
	//printf("Max memory size %d byte", maxGraphSize + maxIslandSize);

	return 0;
}

void print(vector< list<int> > graph) {
	int n = graph.size();
	for (int i = 0; i < n; i++) {
		cout << i << " : ";
		for (list<int>::iterator itor = graph.at(i).begin(); itor != graph.at(i).end(); ++itor) {
			cout << *itor << ' ';
		}
		cout << '\n';
	}
}

int dfs(int v, vector< list<int> >* graph) {
	visited[v] = 1;

	for (list<int>::iterator itor = graph->at(v).begin(); itor != graph->at(v).end(); ++itor) {
		if (visited[*itor] == 0) {
			//printf("%d goes to %d\n", v, *itor);
			dfs(*itor, graph);
		}
	}
	return 0;
}