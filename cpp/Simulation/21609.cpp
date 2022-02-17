/*
21609번: 상어 중학교
https://www.acmicpc.net/problem/21609
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
vector<vector<int>> vec;

void initialize()
{
	cin >> n >> m;

	vec.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}

}

void print_vec(vector<vector<bool>>& vec) {
	cout << "\n";
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j];
		}
		cout << "\n";
	}
}

void print_vec(vector<vector<int>>& vec) {
	cout << "\n";
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
}

bool comp(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) {
		return true;
	}
	else {
		return false;
	}
}

void clear_rainbow(vector<vector<bool>>& visited) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == 0) {
				visited[i][j] = false;
			}
		}
	}
}

int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
void dfs(vector<vector<bool>>& visited, int &rainbow_size ,int& size, int& y, int& x, int color) {
	queue<pair<int, int>> que;
	que.push({ y,x });
	visited[y][x] = true;

	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();
		size++;

		if (vec[cy][cx] == 0)	rainbow_size++;

		for (int i = 0; i < 4; i++) {
			int ny = cy + d[i][0];
			int nx = cx + d[i][1];

			if (!comp(ny, nx)) continue;
			if (visited[ny][nx]) continue;
			if (vec[ny][nx] == color || vec[ny][nx] == 0) {
				visited[ny][nx] = true;
				que.push({ ny,nx });
			}
		}
	}
}

void clear_dfs(int y, int x) {
	int color = vec[y][x];
	
	queue<pair<int, int>> que;
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	que.push({ y,x });
	visited[y][x] = true;

	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		vec[cy][cx] = -2;

		for (int i = 0; i < 4; i++) {
			int ny = cy + d[i][0];
			int nx = cx + d[i][1];

			if (!comp(ny, nx)) continue;
			if (visited[ny][nx]) continue;
			if (vec[ny][nx] == color || vec[ny][nx] == 0) {
				visited[ny][nx] = true;
				que.push({ ny,nx });
			}
		}
	}
}

void turn_block() {
	vector<vector<int>> temp(n, vector<int>(n,-2));
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			temp[n - 1 - x][y] = vec[y][x];
		}
	}
	vec = temp;
}

void grabity() {
	stack<int> s;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			int cur_num = vec[y][x];
			vec[y][x] = -2;
			if (cur_num == -2) {
				continue;
			}
			else if (cur_num == -1) {
				int index = 1;
				while (!s.empty()) {
					vec[y - index][x] = s.top();
					s.pop();

					index++;
				}
				vec[y][x] = -1;
			}
			else {
				s.push(cur_num);
			}
		}

		int index = 0;
		while (!s.empty()) {
			vec[n -1 - index][x] = s.top();
			s.pop();

			index++;
		}
	}
}

void solve()
{
	long long result = 0;
	while (1) {
		vector<vector<bool>> visited(n, vector<bool>(n, false));

		int max_size, max_y, max_x;
		max_size = max_y = max_x = -1;
		int max_rainbow_size = -1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j])   continue;
				if (vec[i][j]<=0)   continue;

				int total_size = 0;
				int rainbow_size = 0;
				dfs(visited, rainbow_size, total_size, i, j, vec[i][j]);
				clear_rainbow(visited);

				//크기가 가장 큰 블록 그룹을 찾는다. 
				if (max_size <= total_size) {
					//블록 그룹이 여러개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹
					if (max_size == total_size && max_rainbow_size > rainbow_size) {
						continue;
					}

					max_size = total_size;
					max_y = i;
					max_x = j;
					max_rainbow_size = rainbow_size;
				}
			}
		}
		if (max_size <= 1)    break;

		clear_dfs(max_y, max_x);
		result += pow(max_size, 2);
		grabity();
		turn_block();
		grabity();
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