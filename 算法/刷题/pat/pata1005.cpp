#include <iostream>
#include <string>
using namespace std;

int main() {
	string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		sum = sum + n[i] - 48;
	}
	string str = to_string(sum);
	for (int i = 0; i < str.size(); i++) {
		if (i == str.size() - 1) {
			cout << arr[str[i] - 48];
		} else {
			cout << arr[str[i] - 48] << ' ';
		}

	}
	return 0;
}