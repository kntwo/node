#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	if (sum < 0) {
		cout << '-';
	}
	vector<int>v;
	while (sum != 0) {
		v.push_back(abs(sum % 10));
		sum = sum / 10;
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (i == 0) {
			cout << v[i];
			break;
		} else if (i % 3 == 0)
			cout << v[i] << ',';
		else
			cout << v[i];
	}
	return 0;

}