#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long int A;
	long long int B;
	long long int C;

	cin >> A >> B >> C;

	cout << (long long int)((long long int)pow(A, B) % C);
	return 0;
}