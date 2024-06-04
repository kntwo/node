#include <iostream>
using namespace std;
int path[410];
int n;
bool st[30][30];
int row[30], column[30];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void dfs(int x, int y, int step) {
	if (x < 1 || y < 1 || x > n || y > n)
		return;
	if (x == n && y == n) {
		int x[30] = {}, y[30] = {};
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (st[i][j] == true) {
					x[i]++;
					y[j]++;
				}
			}
		for (int i = 1; i <= n; i++)
			if (x[i] != column[i])
				return;
		for (int i = 1; i <= n; i++)
			if (y[i] != row[i])
				return;

		path[step] = n * n - 1;
		for (int i = 1; i <= step; i++) {
			cout << path[i] << ' ';
		}
		exit(0);
	}
	for (int k = 0; k < 4; k++) {
		int tx = x + dx[k], ty = y + dy[k];
		if (st[tx][ty] == false) {
			st[tx][ty] = true;
			path[step] = (x - 1) * n + y - 1;
			dfs(tx, ty, step + 1);
			st[tx][ty] = false;
		}
		cout << 'a';
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> row[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> column[i];
	}
	st[1][1] = true;
	dfs(1, 1, 1);

	return 0;
}