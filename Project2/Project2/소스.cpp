#include <iostream> 
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int arr[10] = {4, 7, 3, 9, 6, 5, 3, 2, 8, 11};
	int sum = 0;
	double e = 0;

	sort(arr, arr + 10);
	for (int i = 0; i < 10; i++) {
		sum += arr[i];
		cout << arr[i] << ' ';
	}

	e = (double)sum / 10;
	cout << '\n';
	cout << e << '\n';


	double sum2 = 0;
	for (int i = 0; i < 10; i++) {
		sum2 += (arr[i] - e) * (arr[i] - e);
	}

	sum2 /= 9;

	cout << sum2 << '\n';

	cout << sqrt(sum2);
	cout << "\n\n";
	int arr2[10] = {160, 170, 164, 194, 165, 168, 180, 175, 168, 168};
	
	sort(arr2, arr2 + 10);
	for (int i = 0; i < 10; i++) {
		cout << arr2[i] << ' ';
	}

	cout << '\n';

	return 0;
}