#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int getLastIndex(string, int );
vector<string> solution(vector<string> record);
void add(map<string, string>* uidName, string rec, int e);
string getUserID(string rec, int e);

int main() {
	vector<string> record;
	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");

	solution(record);

	return 0;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<string>::iterator itor;

	map<string, string> uidName;
	int idx = 0;
	string sub;
	string sentence;
	string willAdd;

	for (itor = record.begin(); itor != record.end(); ++itor) {
		sub = itor->substr(0, 5);
		if (sub.compare("Enter") == 0) {
			add(&uidName, *itor, 0);
		}
		else if (sub.compare("Chang") == 0) {
			add(&uidName, *itor, 1);
		}
	}

	for (itor = record.begin(); itor != record.end(); ++itor) {
		willAdd.clear();
		sub = itor->substr(0, 5);
		if (sub.compare("Enter") == 0) {
			sentence = "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
		}
		else if (sub.compare("Leave") == 0) {
			sentence = "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
		}
		else {
			continue;
		}
		willAdd = uidName[getUserID(*itor, 0)];
		willAdd += sentence;
		answer.push_back(willAdd);
	}

	return answer;
}

int getLastIndex(string data, int i) {
	int j;
	for (j = i; data[j] != ' ' && data[j] != NULL; j++) {
	}
	return j;
}

void add(map<string, string>* uidName, string rec, int e) {
	int idx = getLastIndex(rec, 6 + e);
	string userid = getUserID(rec, e);
	string username = rec.substr(idx + 1);
	if (uidName->count(userid) == 0)
		uidName->insert(pair<string, string> (userid, username));
	else {
		uidName->find(userid)->second = username;
	}
}

string getUserID(string rec, int e) {
	int idx = getLastIndex(rec, 6 + e);
	return rec.substr(6 + e, idx - 6 - e);
}