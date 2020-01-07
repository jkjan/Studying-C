#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int N, vector<int> stages);

int main() {
	int N = 4;
	vector<int> stages;

	stages.push_back(4);
	stages.push_back(4);
	stages.push_back(4);
	stages.push_back(4);
	
	solution(N, stages);
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int>::iterator itor;
	multimap<double, int, greater<double> >::iterator mitor;
	multimap<double, int, greater<double> > result;
	double counter[501];
	double total[501];
	int j;
	for (int i = 0; i < N+1; i++) {
		counter[i] = 0;
		total[i] = 0;
	}

	for (itor = stages.begin(); itor != stages.end(); ++itor) {
		counter[*itor]++;
		for (j = *itor; j > 0; j--) {
			total[j]++;
		}
	}

	for (int i = 1; i < N + 1; i++) {
		result.insert(pair<double, int>((counter[i] / total[i]), i));
	}
	
	for (mitor = result.begin(); mitor != result.end(); ++mitor) {
		answer.push_back(mitor->second);
		cout << mitor->second;
	}

	delete(counter);
	return answer;
}