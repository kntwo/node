#include <iostream>
using namespace std;
int arr[110][110];
int n;

void sanjiao() {
	int dp[110][110];
	dp[1][1] = arr[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
		}
	}
	if (n % 2 == 0) {
		cout << max(dp[n][n / 2], dp[n][n / 2 + 1]);
	} else {
		cout << dp[n][n / 2 + 1];
	}
	return ;
}

int main() {
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	sanjiao();
	return 0;
}