/*
2206번: 벽 부수고 이동하기
https://www.acmicpc.net/problem/2206

나중에 좀 보완좀 하자
다른 사람들보다 시간이 2~4배나 느려;;
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 987654321

using namespace std;

queue < pair<pair<int, int>, pair<int, int>>> que;
vector<vector<vector<int>>> visited(1001, vector<vector<int>>(1001, vector<int>(2, false)));
vector<vector<bool>> vec(1001, vector<bool>(1001));

int bfs(int n, int m) {
	//first distance, break
	//second  y,x
	que.push({ {1,0},{1,1} });
	visited[1][1][0] = true;
	visited[1][1][1] = true;

	int x, y, distance, bk;
	while (!que.empty()) {
		y = que.front().second.first;
		x = que.front().second.second;
		distance = que.front().first.first;
		bk = que.front().first.second;

		//cout << x << " " << y << " " << distance << " " << bk << "\n";

		if (y == n && x == m) {
			return distance;
		}

		que.pop();

		if ((x - 1) >= 1) {
			if (vec[y][x - 1] && bk == 0 && !visited[y][x-1][1]) {
				que.push({ {distance + 1,bk + 1},{y,x - 1} });
				visited[y][x - 1][1] = true;
			}
			if (!vec[y][x - 1]) {
				if (bk == 0 && !visited[y][x - 1][0]) {
					que.push({ {distance + 1,bk},{y,x - 1} });
					visited[y][x - 1][0] = true;
				}
				else if (bk == 1 && !visited[y][x - 1][1]) {
					que.push({ {distance + 1,bk},{y,x - 1} });
					visited[y][x - 1][1] = true;
				}
			}
		}

		if ((x + 1) <= m) {
			if (vec[y][x + 1] && bk == 0 && !visited[y][x + 1][1]) {
				que.push({ {distance + 1,bk + 1},{y,x + 1} });
				visited[y][x + 1][1] = true;
			}
			if (!vec[y][x + 1]) {
				if (bk == 0 && !visited[y][x + 1][0]) {
					que.push({ {distance + 1,bk},{y,x + 1} });
					visited[y][x + 1][0] = true;
				}
				else if (bk == 1 && !visited[y][x + 1][1]) {
					que.push({ {distance + 1,bk},{y,x + 1} });
					visited[y][x + 1][1] = true;
				}
			}
		}

		if ((y - 1) >= 1) {
			if (vec[y - 1][x] && bk == 0 && !visited[y - 1][x][1]) {
				que.push({ {distance + 1,bk + 1},{y - 1,x} });
				visited[y - 1][x][1] = true;
			}
			if (!vec[y - 1][x]) {
				if (bk == 0 && !visited[y - 1][x][0]) {
					que.push({ {distance + 1,bk},{y - 1,x} });
					visited[y - 1][x][0] = true;
				}
				else if (bk == 1 && !visited[y - 1][x][1]) {
					que.push({ {distance + 1,bk},{y - 1,x} });
					visited[y - 1][x][1] = true;
				}
			}
		}

		if ((y + 1) <= n) {
			if (vec[y + 1][x] && bk == 0 && !visited[y + 1][x][1]) {
				que.push({ {distance + 1,bk + 1},{y + 1,x} });
				visited[y + 1][x][1] = true;
			}
			if (!vec[y + 1][x]) {
				if (bk == 0 && !visited[y + 1][x][0]) {
					que.push({ {distance + 1,bk},{y + 1,x} });
					visited[y + 1][x][0] = true;
				}
				else if (bk == 1 && !visited[y + 1][x][1]) {
					que.push({ {distance + 1,bk},{y + 1,x} });
					visited[y + 1][x][1] = true;
				}
			}

		}

	}
	return -1;
}

int main() {
	sync_off;
	int n, m;
	cin >> n >> m;

	string temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		for (int j = 1; j <= m; j++) {
			if (temp[j - 1] == '1') {
				vec[i][j] = true;
			}
		}
	}
	cout<<bfs(n, m);


	return 0;
}