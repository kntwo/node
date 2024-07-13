#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// root node 00
int N, M; 
long long S;

int weigh[100] = {0};
vector<int>child[100];
vector<int>path;
vector<vector<int>>alpath;
void dfs(int curnode, long long curweigh) {
	if (child[curnode].size() == 0 && curweigh != S)
		return;
	path.emplace_back(weigh[curnode]);
	if (curweigh == S && child[curnode].size() == 0) {
		alpath.emplace_back(path);
	} else {
		for (vector<int>::iterator it = child[curnode].begin(); it != child[curnode].end(); it++) {
			dfs(*it, curweigh + weigh[*it]);
		}
	}
	path.pop_back();
}
bool cmp(vector<int> &a, vector<int> &b) {
	int a_len = a.size();
	int b_len = b.size();
	int min_len = min(a_len, b_len);
	for (int i = 0; i < min_len; i++) {
		if (a[i] != b[i]) {
			return a[i] > b[i];
		}
	}
	if (a_len != b_len)
		return a.size() > b.size();
	return false;
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++) {
		cin >> weigh[i];
	}
	while (M--) {
		int index, num;
		cin >> index >> num;
		while (num--) {
			int childindex;
			cin >> childindex;
			child[index].emplace_back(childindex);
		}
	}
	dfs(0, weigh[0]);
	sort(alpath.begin(), alpath.end(),cmp);
	for (int i = 0; i < alpath.size(); i++) {
		for (int j = 0; j < alpath[i].size(); j++) {
			if (j < alpath[i].size() - 1) {
				cout << alpath[i][j] << ' ';
			} else {
				cout << alpath[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
