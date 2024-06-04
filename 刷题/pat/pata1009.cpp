#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
#define MAX_SIZE 1001
//input sample
//2 1 2.4 0 3.2
//2 2 1.5 1 0.5
//output sample
//3 3 3.6 2 6.0 1 1.6

int main() {
	double arr[MAX_SIZE] = {0};
	double arr1[MAX_SIZE] = {0};
	int k;
	cin >> k;
	while (k--) {
		int ex;
		double co;
		cin >> ex >> co;
		arr[ex] = co;
	}
	cin >> k;
	while (k--) {
		int ex;
		double co;
		cin >> ex >> co;
		for (int i = 0; i < MAX_SIZE; i++) {
			int index = i + ex;
			double temp = arr[i] * co;
			arr1[index] = temp + arr1[index];
		}
	}
	int sum = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		if (arr1[i] != 0)
			sum++;
	}
	cout << sum;
	for (int i = MAX_SIZE - 1; i >= 0; i--) {
		if (arr1[i] != 0) {
			printf(" %d %.1f", i, arr1[i]);
		}
	}
	return 0;
}