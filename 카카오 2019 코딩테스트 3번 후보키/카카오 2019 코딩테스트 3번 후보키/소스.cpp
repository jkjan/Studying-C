#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <set>

using namespace std;
int answer = 0;
int column;
int attribute[8];
set< vector <int> > keys;

void candidateKeys(vector<vector<string> > relation, int canCnt);
bool findKeys(vector<vector<string> > relation, vector<int> candidate);
bool minimal(vector<int> candidate);

int solution(vector<vector<string> > relation) {
	column = relation[0].size();
	int i;

	for (i = 0; i < column; i++) {
		attribute[i] = i;
	}

	for (i = 1; i <= column; i++) {
		candidateKeys(relation, i);
	}

	cout << answer;

	return answer;
}

void candidateKeys(vector<vector<string> > relation, int canCnt) {
	bool com[8];
	int i;
	vector<int> candidate;

	for (i = 0; i < column - canCnt; i++) {
		com[i] = false;
	}

	for (int j = i; j < column; j++) {
		com[j] = true;
	}

	do {
		for (i = 0; i < column; i++) {
			if (com[i]) {
				candidate.push_back(attribute[i]);
			}
		}

		if (!minimal(candidate)) {
			candidate.clear();
			continue;
		}

		if (findKeys(relation, candidate)) {
			answer++;
			keys.insert(candidate);
		}

		candidate.clear();
	} while (next_permutation(com, com + column));
}

bool findKeys(vector<vector<string> > relation, vector<int> candidate) {
	set<string> counter;
	string add;
	int i, j;
	bool flag = true;

	for (i = 0; i < relation.size(); i++) {
		if (!flag)
			break;

		for (j = 0; j < candidate.size(); j++) {
			add += relation[i][candidate[j]];
			add += "|";
		}

		if (counter.count(add) == 0) {
			counter.insert(add);
			add.clear();
		}

		else {
			flag = false;
			break;
		}
	}

	return flag;
}

bool minimal(vector <int> candidate) {
	int keynum = candidate.size();
	vector<int> sch;
	bool flag = true;
	int i, j, k;
	for (i = 1; i < keynum; i++) {
		if (!flag) {
			break;
		}

		bool com[8];

		for (j = 0; j < keynum - i; j++) {
			com[j] = false;
		}

		for (k = j; k < keynum; k++) {
			com[k] = true;
		}

		do {
			for (k = 0; k < keynum; k++) {
				if (com[k]) {
					sch.push_back(candidate[k]);
				}
			}
			
			if (keys.count(sch) == 1) {
				flag = false;
				break;
			}
			sch.clear();

		} while (next_permutation(com, com + keynum));
	}

	return flag;
}

int main() {
	vector<vector<string> > relation;
	relation.push_back(vector<string>());
	relation.push_back(vector<string>());
	relation.push_back(vector<string>());
	relation.push_back(vector<string>());
	relation.push_back(vector<string>());
	relation.push_back(vector<string>());

	relation[0].push_back("100");
	relation[0].push_back("ryan");
	relation[0].push_back("music");
	relation[0].push_back("2");

	relation[1].push_back("200");
	relation[1].push_back("apeach");
	relation[1].push_back("math");
	relation[1].push_back("2");

	relation[2].push_back("300");
	relation[2].push_back("tube");
	relation[2].push_back("computer");
	relation[2].push_back("3");

	relation[3].push_back("400");
	relation[3].push_back("con");
	relation[3].push_back("computer");
	relation[3].push_back("4");

	relation[4].push_back("500");
	relation[4].push_back("muzi");
	relation[4].push_back("music");
	relation[4].push_back("3");

	relation[5].push_back("600");
	relation[5].push_back("apeach");
	relation[5].push_back("music");
	relation[5].push_back("2");

	solution(relation);

	return 0;
}