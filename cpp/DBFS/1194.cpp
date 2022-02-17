/*
1194번: 달이 차오른다, 가자.
https://www.acmicpc.net/problem/1194
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
vector<pair<int, int>> start;

void initialize()
{
	cin >> n >> m;
	char c;
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = 0; j < m; j++) {
			cin >> c;
			temp.push_back(c);

			if (c == '0') {
				start.push_back({ i,j });
				temp[j] = '.';
			}
		}
		map.push_back(temp);
	}
}

struct Node {
	int y, x, key, time;
	bool operator < (const Node& n) const {
		return time > n.time;
	}
};

void solve()
{
	int result = -1;
	bool isEscap = false;
	int d[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

	int alphabet = (1 << 6);
	vector<vector<vector<int>>> mapscore(alphabet, vector<vector<int>>(n, vector<int>(m, 2e9)));

	priority_queue<Node> que;

	for (int i = 0; i < start.size(); i++) {
		que.push({ start[i].first,start[i].second,0,0 });
		mapscore[0][start[i].first][start[i].second] = 0;
	}

	while (!que.empty()) {
		auto a = que.top();
		int cury = a.y;   int curx = a.x;   int curkey = a.key;   int curtime = a.time;
		que.pop();

		if (map[cury][curx] == '1') {
			result = curtime;
			break;
		}

		if (mapscore[curkey][cury][curx] != curtime) {
			continue;
		}


		for (int i = 0; i < 4; i++) {
			int nexty = cury + d[i][0];
			int nextx = curx + d[i][1];
			int nextkey = curkey;

			if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < m) {
				if (map[nexty][nextx] == '#') {
					continue;
				}
				else if (map[nexty][nextx] >= 'a' && map[nexty][nextx] <= 'f') {
					int index = map[nexty][nextx] - 'a';
					nextkey |= (1 << index);
				}
				else if (map[nexty][nextx] >= 'A' && map[nexty][nextx] <= 'F') {
					int index = map[nexty][nextx] - 'A';
					if ((curkey & (1 << index)) == 0) {
						continue;
					}
				}

				if (mapscore[nextkey][nexty][nextx] > curtime + 1) {
					mapscore[nextkey][nexty][nextx] = curtime + 1;
					que.push({ nexty,nextx,nextkey,curtime + 1 });
				}
			}
		}
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