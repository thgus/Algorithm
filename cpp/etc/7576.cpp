#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int box[1000][1000];
int check[1000][1000] = { 0 };

int N, M;

int MAX() {
	int maxnum = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (box[j][i] == 0)
				return -1;
			else if (check[j][i] > maxnum)
				maxnum = check[j][i];
		}
	}

	return maxnum - 1;
}

int main() {

	queue<pair<int, int>> q;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> box[j][i];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (box[j][i] == 1) {
				q.push(make_pair(j, i));
				check[j][i] = 1;
			}
		}
	}

	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (box[nx][ny] == 0 && check[nx][ny] == 0) {
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
					box[nx][ny] = 1;
				}
				else if (box[nx][ny] == -1 && check[nx][ny] == 0) {
					check[nx][ny] = -1;
				}
			}
		}

	}

	cout << MAX();

	return 0;
}
