#include <iostream>
using namespace std;

void output(int i) {
	switch (i) {
		case 0:
			cout << 'W' << ' ';
			break;
		case 1:
			cout << 'T' << ' ';
			break;
		case 2:
			cout << 'L' << ' ';
			break;
	}
}

int main() {
	double arr[3][3];
	double sum = 1;
	int temp[3] = {};
	for (int i = 0; i < 3; i++) {
		double max = 0;
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			if (max < arr[i][j]) {
				max = arr[i][j];
				temp[i] = j;
			}
		}
		sum = sum * max;
	}
	output(temp[0]);
	output(temp[1]);
	output(temp[2]);
	printf("%.2f",  sum * 1.3 - 2);
	return 0;
}