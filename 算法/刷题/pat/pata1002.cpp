#include <iostream>
using namespace std;

//sample input
//2 1 2.4 0 3.2
//2 2 1.5 1 0.5
//sample output
//3 2 1.5 1 2.9 0 3.2
int main() {
	float arr[1001] = {0};

	int n1, n2;
	cin >> n1;
	for (int i = 1; i <= n1; i++) {
		int ex;
		float co;
		cin >> ex >> co;
		arr[ex] = co;
	}
	cin >> n2;
	for (int i = 1; i <= n2; i++) {
		int ex;
		float co;
		cin >> ex >> co;
		arr[ex] += co;
	}
	int sum = 0;
	for (int i = 0; i < 1001; i++) {
		if (arr[i] != 0)sum++;
	}
	cout << sum;
	for (int i = 1000; i >= 0; i--) {
		if (arr[i] != 0) {
			printf(" %d %.1f", i, arr[i]);
		}
	}
	
	return 0;
}