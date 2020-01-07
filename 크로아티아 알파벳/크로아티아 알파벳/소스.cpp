#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
	stack<char> wordstack;
	char word[101];
	scanf("%s", word);
	int len = strlen(word);

	for (int i = 0; i < len; i++) {

		if (word[i] == 'j' && !wordstack.empty() && (wordstack.top() == 'l' || wordstack.top() == 'n')) {
			wordstack.pop();
		}

		if (word[i] == '-' && !wordstack.empty() && (wordstack.top() == 'c' || wordstack.top() == 'd')) {
			wordstack.pop();
		}

		if (word[i] == '=' && !wordstack.empty()) {
			if (wordstack.top() == 's' || wordstack.top() == 'c')
				wordstack.pop();
			else if (wordstack.top() == 'z') {
				wordstack.pop();
				if (!wordstack.empty() && wordstack.top() == 'd')
					wordstack.pop();
			}
		}

		wordstack.push(word[i]);
	}

	printf("%d", wordstack.size());

	return 0;
}