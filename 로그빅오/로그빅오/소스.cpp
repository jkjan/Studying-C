#include <iostream>
using namespace std;


void function(int n) {
	int i = 1;
	int cnt = 0;
	while (i < n) {
		int j = n;         
		while (j > 0) {
			j = j / 2;
			cnt++;
		}
		i = 2 * i; 
	} 

	cout << cnt << endl;

}

int main() {
	for (int i = 1; i < 10000; i++)
		function(i);

	return 0;
}