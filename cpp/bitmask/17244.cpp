/*
17244번: 아맞다우산
https://www.acmicpc.net/problem/17244
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
vector<vector<char>> map;
int sy, sx;
int key_max = 0;

void initialize()
{
	cin >> n >> m;
	map.resize(m, vector<char>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				sy = i;
				sx = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'X') {
				map[i][j] = (char)key_max + '0';
				key_max++;
			}
		}
	}
}

struct Node {
	int y, x, key, step;
	bool operator<(const Node i) const {
		return step > i.step;
	}
};

void solve()
{
	priority_queue<Node> que;
	que.push({ sy,sx,0,0 });

	vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1 << key_max, 1e9)));
	dp[sy][sx][0] = 0;

	int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	while (!que.empty()) {
		int cur_y = que.top().y;
		int cur_x = que.top().x;
		int cur_key = que.top().key;
		int cur_step = que.top().step;
		que.pop();

		if (dp[cur_y][cur_x][cur_key] != cur_step)	continue;

		if (map[cur_y][cur_x] == 'E') {
			if (cur_key == (1 << key_max) - 1) {
				cout << cur_step;
				break;
			}
			else {
				continue;
			}
		}
		else if (map[cur_y][cur_x] >= '0' && map[cur_y][cur_x] <= (char)(key_max+'0')) {
			int key = map[cur_y][cur_x] - '0';
			cur_key |= (1 << key);
		}

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + d[i][0];
			int next_x = cur_x + d[i][1];
			if (next_y >= 0 && next_y < m && next_x >= 0 && next_x < n) {
				if (map[next_y][next_x] == '#')  continue;
				if (dp[next_y][next_x][cur_key] > cur_step+1) {
					dp[next_y][next_x][cur_key] = cur_step+1;
					que.push({ next_y,next_x,cur_key,cur_step + 1 });
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