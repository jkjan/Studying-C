#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector <int> > reverse(vector  <vector <int > > board);

int solution(vector  <vector <int > > board, vector<int> moves) {
	int answer = 0;
	stack <int> baguni;
	vector  <vector <int > > reversed = reverse(board);

	vector<int>::iterator itor;
	int i;


	for (i = 0; i < moves.size(); i++) {
		itor = reversed[moves[i] - 1].begin();
		while (*itor == 0 && itor != reversed[moves[i] - 1].end()) {
			advance(itor, 1);
		}

		//cout << *itor << endl;
		*itor = 0;

		if (!baguni.empty()) {
			if (baguni.top() == *itor) {
				baguni.pop();
				answer++;
				continue;
			}
		}
		baguni.push(*itor);
	}

	return answer;
}

vector< vector <int> > reverse(vector  <vector <int > > board) {
	vector< vector <int> > reversed;

	int i, j;

	for (i = 0; i < board.size(); i++) {
		reversed.push_back(vector<int>());
	}

	for (i = 0; i < board.size(); i++) {
		for (j = 0; j < board[i].size(); j++) {
			reversed[j].push_back(board[i][j]);
		}
	}

	return reversed;
}




int main() {
	vector < vector <int> > test;
	test.push_back(vector<int>());
	test.push_back(vector<int>());
	test.push_back(vector<int>());
	test.push_back(vector<int>());
	test.push_back(vector<int>());

	test[0].push_back(0);
	test[0].push_back(0);
	test[0].push_back(0);
	test[0].push_back(0);
	test[0].push_back(0);

	test[1].push_back(0);
	test[1].push_back(0);
	test[1].push_back(1);
	test[1].push_back(0);
	test[1].push_back(3);

	test[2].push_back(0);
	test[2].push_back(2);
	test[2].push_back(5);
	test[2].push_back(0);
	test[2].push_back(1);

	test[3].push_back(4);
	test[3].push_back(2);
	test[3].push_back(4);
	test[3].push_back(4);
	test[3].push_back(2);

	test[4].push_back(3);
	test[4].push_back(5);
	test[4].push_back(1);
	test[4].push_back(3);
	test[4].push_back(1);

	vector<int> moves;

	moves.push_back(1);
	moves.push_back(5);
	moves.push_back(3);
	moves.push_back(5);
	moves.push_back(1);
	moves.push_back(2);
	moves.push_back(1);
	moves.push_back(4);

	cout << solution(test, moves);

	return 0;
}