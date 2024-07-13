#include <iostream>
using namespace std;
#define MAX_SIZE 501
#define INFINITY 32767
//5 6 3 3
//1 2 1 5 3
//0 1 1
//0 2 2
//0 3 1
//1 2 1
//2 4 1
//3 4 1
int n, m, c1, c2;

int cityresnum[MAX_SIZE] = {0};
void dijkstra(int rdlen[][MAX_SIZE], int start, int end) {
	int pathnum[MAX_SIZE] = {0};
	int rescuenum[MAX_SIZE] = {0};
	int dist[MAX_SIZE];
	bool visit[MAX_SIZE] = {false};
	for (int i = 0; i < MAX_SIZE; i++) {
		dist[i] = INFINITY;
		rescuenum[i] = 0;
	}
	rescuenum[start] = cityresnum[start];
	dist[start] = 0;
	pathnum[start] = 1;
	int minnode = start;

	for (int k = 0; k < n; k++) {
		int mindist = INFINITY;
		for (int i = 0; i < MAX_SIZE; i++) {
			if (visit[i] == false && dist[i] < mindist) {
				mindist = dist[i];
				minnode = i;
			}
		}
		visit[minnode] = true;
		for (int i = 0; i < n; i++) {
			int len = dist[minnode] + rdlen[minnode][i];
			if (len <= dist[i] && i != minnode) {
				if (len == dist[i]) {
					pathnum[i] += pathnum[minnode];
					rescuenum[i] = max(rescuenum[i], rescuenum[minnode] + cityresnum[i]);
				} else {
					pathnum[i] = pathnum[minnode];
					rescuenum[i] = rescuenum[minnode] + cityresnum[i];
				}
				dist[i] = len;
			}
		}
	}

	cout << pathnum[end] << ' ' << rescuenum[end];
}

int main() {

	int rdlen[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			rdlen[i][j] = INFINITY;
		}
	}

	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		rdlen[i][i] = 0;
		cin >> cityresnum[i];
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		rdlen[a][b] = c;
		rdlen[b][a] = c;
	}
	dijkstra(rdlen, c1, c2);
	return 0;
}
