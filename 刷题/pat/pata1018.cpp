#include <iostream>
#include <vector>
using namespace std;
int arr[501][501];
vector<int>map[501];
int cmax, n, sp, m;
int bike[501];
vector<int>path;
int mindis[501];
vector<int>final_path;
int final_send, final_take;

void dfs(int curnode, int curdis, int cursend, int curtake) {
	if (curdis > mindis[curnode])
		return;
	path.emplace_back(curnode);
	if (curnode == sp) {
		if (curdis < mindis[sp] || (curdis == mindis[sp] && cursend < final_send) || (curdis == mindis[sp]
		        && cursend == final_send && curtake < final_take)) {
			mindis[sp] = curdis;
			final_send = cursend;
			final_take = curtake;
			final_path = path;
		}
	} else {
        mindis[curnode]=curdis;
		for (int i : map[curnode]) {
			if (curtake + bike[i] < cmax / 2) {
				dfs(i, curdis + arr[curnode][i], cursend+cmax / 2 - curtake - bike[i], 0);
			} else {
				dfs(i, curdis + arr[curnode][i], cursend, curtake + bike[i] - cmax / 2);
			}
		}
	}
	path.pop_back();
}

int main() {
	cin >> cmax >> n >> sp >> m;
	for (int i = 1; i <= n; i++) {
		cin >> bike[i];
	}
	while (m--) {
		int a, b, len;
		cin >> a >> b >> len;
		arr[a][b] = arr[b][a] = len;
		map[a].emplace_back(b);
		map[b].emplace_back(a);
	}
	for (int i = 0; i < 501; i++)
		mindis[i] = 100000;
	dfs(0, 0, 0, 0);
	cout << final_send << ' ';
	cout << final_path[0];
	for (int i = 1; i < final_path.size(); i++) {
		cout << "->" << final_path[i];
	}
	cout << ' ' << final_take;
	return 0;
}
