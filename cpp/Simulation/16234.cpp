/*
16234번: 인구 이동
https://www.acmicpc.net/problem/16234
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define MAX 50
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, l, r;
vector<vector<int>> vec;

void initialize()
{
	cin >> n >> l >> r;
	vec.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}
}

bool isBoundary(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) {
		return true;
	}
	else {
		return false;
	}
}

int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
void open_border(vector<int> route[][MAX]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			route[i][j].clear();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + d[k][0];
				int nx = j + d[k][1];
				if (!isBoundary(ny, nx))  continue;
				int sub = abs(vec[i][j] - vec[ny][nx]);
				
				if (l <= sub && sub <= r) {
					route[i][j].push_back(k);
				}
			}
		}
	}
}

int bfs(bool visited[][MAX], vector<int> route[][MAX], int sy, int sx) {
	queue<pair<int, int>> que;
	que.push({ sy,sx });

	queue<pair<int, int>> list;

	int world = 0;
	int sum = 0;

	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();
		
		if (visited[cy][cx])	continue;
		visited[cy][cx] = true;

		list.push({ cy,cx });
		sum += vec[cy][cx];
		world++;

		for (int direction : route[cy][cx]) {
			int ny = cy + d[direction][0];
			int nx = cx + d[direction][1];

			que.push({ ny,nx });
		}
	}

	while (!list.empty()) {
		int cy = list.front().first;
		int cx = list.front().second;
		vec[cy][cx] = sum / world;
		list.pop();
	}

	return world - 1;
}

void print_vec() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve()
{
	int result = 0;
	while (1) {
		vector<int> route[MAX][MAX];
		open_border(route);

		bool visited[MAX][MAX];
		for (int i = 0; i < MAX; i++) {
			memset(visited[i], false, sizeof(bool) * MAX);
		}

		int num = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (visited[y][x])   continue;
				num += bfs(visited, route, y, x);
			}
		}

		if (num == 0)  break;
		result++;
	}
	cout << result;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}