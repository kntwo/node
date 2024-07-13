#include <iostream>
using namespace std;

int arr[100][100];//1表示空地,2表示障碍物
bool st[100][100];//false表示没有标记,true表示被标记
int endx, endy, num = 1000;

int dx[4] = {0, 1, 0, -1};

int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int step) {
	if (x == endx && y == endy) {
		if (step < num)
			num = step;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (arr[tx][ty] == 1 && st[tx][ty] == false) {
			st[tx][ty] = true;
			dfs(tx, ty, step + 1);
			st[tx][ty] = false;
		}
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	st[1][1] = true;
	cin >> endx >> endy;
	dfs(1, 1, 0);
	cout << num << endl;
	system("pause");
	return 0;
}
/*
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
4 3
*/