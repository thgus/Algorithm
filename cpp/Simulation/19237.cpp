/*
19237번: 어른 상어
https://www.acmicpc.net/problem/19237

냄새는 상어가 이동한 후 없어짐.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Shark {
	int y, x;
	int direction;
	bool isExist = true;
	int priority[4][4];
};

struct Smell {
	int last_time;
	int y, x;
};

int n, m, k;
vector<vector<int>> map;
vector<vector<int>> smell_time;
vector<Shark> shark;
queue<Smell> que;

// 0, 1, 2, 3은 각각 위, 아래, 왼쪽, 오른쪽
// 문제는 1,2,3,4였지만 여기서는 내 편의상 0,1,2,3으로 대체
int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void initialize()
{
	cin >> n >> m >> k;
	map.resize(n, vector<int>(n));
	shark.resize(m + 1);
	smell_time.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j]) {
				shark[map[i][j]].y = i;
				shark[map[i][j]].x = j;
				que.push({ k,i,j });
				smell_time[i][j] = k;
			}
			
		}
	}

	int direction;
	for (int i = 1; i <= m; i++) {
		cin >> direction;
		shark[i].direction = direction - 1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> shark[i].priority[j][k];
				shark[i].priority[j][k]--;
			}
		}
	}

}

void print_vec(vector<vector<int>> vec) {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vec[i][j] == INF) {
				cout << "0";
				continue;
			}
			cout << vec[i][j];
		}
		cout << "\n";
	}
}

void solve()
{
	int cur_time = 0;
	int last_shark = m;
	while (1) {
		if (cur_time > 1000) {
			cout << "-1";
			break;
		}

		if (last_shark == 1) {
			cout << cur_time;
			break;
		}

		cur_time++;
		vector<vector<int>> shark_map(n, vector<int>(n, INF));
		for (int i = 1; i <= m; i++) {
			if (!shark[i].isExist)   continue;
			shark[i].isExist = false;

			int next_y = -1, next_x = -1, direction;
			for (int j = 0; j < 4; j++) {
				int y = shark[i].y + d[shark[i].priority[shark[i].direction][j]][0];
				int x = shark[i].x + d[shark[i].priority[shark[i].direction][j]][1];

				if (y >= 0 && y < n && x >= 0 && x < n) {
					if (map[y][x] == 0) {
						direction = shark[i].priority[shark[i].direction][j];
						next_y = y;
						next_x = x;
						break;
					}
					else if (map[y][x] == i) {
						if (next_y == -1 && next_x == -1) {
							direction = shark[i].priority[shark[i].direction][j];
							next_y = y;
							next_x = x;
						}
					}
				}
			}

			shark[i].y = next_y;
			shark[i].x = next_x;
			shark[i].direction = direction;
			shark_map[next_y][next_x] = min(shark_map[next_y][next_x], i);

		}

		while (!que.empty()) {
			if (que.front().last_time == cur_time) {
				if (smell_time[que.front().y][que.front().x] == cur_time) {
					map[que.front().y][que.front().x] = 0;
				}
				que.pop();
			}
			else {
				break;
			}
		}

		last_shark = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (shark_map[i][j] != INF) {
					que.push({ cur_time + k,i,j });
					map[i][j] = shark_map[i][j];
					last_shark++;
					shark[shark_map[i][j]].isExist = true;
					smell_time[i][j] = cur_time + k;
				}
			}
		}

	}

}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}