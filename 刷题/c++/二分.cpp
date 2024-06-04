#include <bits/stdc++.h>
using namespace std;
int len, n, m;
int stone[50005];

bool check(int d) {
	int num = 0;
	int pos = 0;
	for (int i = 1; i <= n; i++)
		if (stone[i] - pos < d)
			num++;
		else
			pos = stone[i];
	if (num <= m)
		return true; //×î¶ÌÌøÔ¾¾àÀëÌ«Ð¡ÁË
	else
		return false;
}

int main() {
	cin >> len >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> stone[i];
	int l = 0, r = len, mid;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l << endl;
	return 0;
}