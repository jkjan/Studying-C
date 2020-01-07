#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class food {
public:
	int num;
	int time;
	food(int num, int time) {
		this->num = num;
		this->time = time;
	}
};

bool compare(food a, food b) {
	return a.time < b.time;
}

int solution(vector<int> food_times, long long k) {
	int size = food_times.size();

	if (k < size) {
		return k + 1;
	}
	int answer = 0;
	int rot = 0;
	int sizec = size;
	vector<food> organized;
	list<int> indices;
	list<int>::iterator itor;
	int sub;

	int i, j;
	for (i = 0; i < size; i++) {
		organized.push_back(food(i, food_times[i]));
		indices.push_back(i);
	}

	sort(organized.begin(), organized.end(), compare);

	for (i = 0; i < size; i++) {
		if (organized[i].time > 0) {
			sub = organized[i].time;
			rot += sub * sizec;
			//cout << rot << " ~ ";
			for (j = i; j < size; j++) {
				organized[j].time -= sub;
			}

			/*for (j = 0; j < size; j++) {
				cout << organized[j].time << " ";
			}*/
		}

		if (rot > k) {
			//answer = organized[i+1].num + 1;
			//cout << endl;
			//cout << (k - (rot - sub * sizec)) % sizec << endl;

			itor = indices.begin();
			advance(itor, (k - (rot - sub * sizec)) % sizec);
			answer = *itor;
			break;
		}

		else {
			//cout << " -> " << organized[i].num << " delete" << endl;
			itor = indices.begin();
			for (itor = indices.begin(); itor != indices.end(); ++itor) {
				if (*itor == organized[i].num) {
					indices.erase(itor);
					break;
				}
			}
			
			if (k == rot) {
				itor = indices.begin();
				answer = *itor;
			}
		}

		sizec--;
	}

	return answer + 1;
}

int main() {
	vector<int> food_times;
	food_times.push_back(3);
	food_times.push_back(7);
	food_times.push_back(5);
	food_times.push_back(1);
	food_times.push_back(11);

	long long k = 11;
	cout << solution(food_times, k);
}