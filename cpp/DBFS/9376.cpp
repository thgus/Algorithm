/*
9376번: 탈옥
https://www.acmicpc.net/problem/9376

각 지점마다 죄수 1, 죄수 2, 상근이가 문을 연 횟수를 저장해 놓으면 나중에 문을 연 최소 횟수를 파악할 수 있습니다
출처: https://jaimemin.tistory.com/1243 [꾸준함]
이런 생각은 어떻게 하는거야?? 대단하다

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;


bool isBoundary(int y, int x, int n, int m) {
	if (y >= 0 && y < n && x >= 0 && x < m) {
		return true;
	}
	else {
		return false;
	}
}

struct Node {
	int y, x;
	int open_door;
	int division;

	bool operator<(const Node n)const {
		return n.open_door < open_door;
	}
};

void print_vec(vector<vector<vector<int>>> &visited, int n, int m) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (visited[j][k][i] == 1e8) {
					cout << "*";
				}
				else {
					cout << visited[j][k][i];
				}
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

void solve()
{
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<char>> map(n, vector<char>(m));
		vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(3, 1e8)));
		vector<pair<int, int>> prisoner;

		priority_queue<Node> que;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];

				if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					if (map[i][j] == '*')	continue;
					else if (map[i][j] == '#') {
						que.push({ i,j,1,0 });
						visited[i][j][0] = 1;
					}
					else{
						que.push({ i,j,0,0 });
						visited[i][j][0] = 0;
					}
				}
				
				if (map[i][j] == '$') {
					prisoner.push_back({ i,j });
					visited[i][j][prisoner.size()] = 0;
					que.push({ i,j,0,(int)prisoner.size() });
				}

			}
		}

		int d[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
		while (!que.empty()) {
			Node cur = que.top();
			que.pop();

			if (visited[cur.y][cur.x][cur.division] < cur.open_door) {
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int next_y = cur.y + d[i][0];
				int next_x = cur.x + d[i][1];
				if (isBoundary(next_y, next_x, n, m)) {
					if (map[next_y][next_x] == '*') {
						continue;
					}
					else if (map[next_y][next_x] == '#'&&visited[next_y][next_x][cur.division]>cur.open_door+1) {
						visited[next_y][next_x][cur.division] = cur.open_door + 1;
						que.push({ next_y,next_x,cur.open_door + 1,cur.division });
					}
					else if((map[next_y][next_x] == '.'||map[next_y][next_x]=='$')&&visited[next_y][next_x][cur.division] > cur.open_door) {
						visited[next_y][next_x][cur.division] = cur.open_door;
						que.push({ next_y,next_x,cur.open_door,cur.division });
					}
				}
			}

		}
		
		int result = 1e9;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int cur_open_door = 0;
				for (int i = 0; i < 3; i++) {
					cur_open_door += visited[j][k][i];
				}
				if (map[j][k] == '#') {
					cur_open_door -= 2;
				}

				result = min(result, cur_open_door);
			}
		}

		result = min(result, visited[prisoner[0].first][prisoner[0].second][0] + visited[prisoner[1].first][prisoner[1].second][0]);

		cout << result << "\n";

	}
}

int main()
{
	sync_off;
	solve();

	return 0;
}