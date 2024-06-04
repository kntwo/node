#include <iostream>
#include <queue>
using namespace std;
int arr[60][60];//1代表空地,2代表障碍物
bool st[60][60];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct point {
	int x;
	int y;
	int step;
};
queue<point>t;
/*
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
1 1 4 3
*/
int main() {
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	}
	int startx, starty, endx, endy;
	cin >> startx >> starty >> endx >> endy;
	point start;
	start.x = startx;
	start.y = starty;
	start.step = 0;
	t.push(start);
	st[startx][starty] = true;
	bool flag = false;
	while (!t.empty()) {
		int x = t.front().x, y = t.front().y;
		if (endx == x && endy == y) {
			cout << t.front().step << '\n';
			flag = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (arr[tx][ty] == 1 && st[tx][ty] == false) {
				point temp;
				temp.x = tx;
				temp.y = ty;
				temp.step = t.front().step + 1;
				t.push(temp);
				st[tx][ty] = true;
			}
		}
		t.pop();
	}
	if (flag == false)
		cout << "no anwser!!!";
	return 0;
}