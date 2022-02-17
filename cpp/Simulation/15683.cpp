/*
15683번: 감시
https://www.acmicpc.net/problem/15683

direction 5같은 경우에는 항상 4방향으로 가니까 백트래킹 안해줘도 되긴 한데 일단 귀찮으니까 통합함.
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
vector<vector<int>> map;

struct Node {
	int num;
	int y, x;
};
vector<Node> cctv;

void initialize()
{
	cin >> n >> m;
	map.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv.push_back({ map[i][j],i,j });
			}
		}
	}
}

int d[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int d2[2][2] = { {0,1},{2,3} };
int d3[4][2] = { {0,2},{2,1},{1,3},{3,0} };
int d4[4][3] = { {0,1,2},{1,2,3},{0,2,3},{0,1,3} };

bool isBoundary(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) {
		return true;
	}
	else {
		return false;
	}
}

void dfs(vector<vector<bool>>& see, int y, int x, int direction) {
	while (isBoundary(y, x) && map[y][x] != 6) {
		see[y][x] = true;
		y += d[direction][0];
		x += d[direction][1];
	}
}

struct List
{
	int direction;
	int y, x;
};

int min_result = 987654321;
void back_tracking(vector<List>& direction_list, int cur) {
	if (cctv.size() == cur) {
		vector<vector<bool>> can_see(n, vector<bool>(m, false));
		for (int i = 0; i < direction_list.size(); i++) {
			int y = direction_list[i].y;
			int x = direction_list[i].x;
			int direction = direction_list[i].direction;

			dfs(can_see, y, x, direction);
		}

		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (can_see[i][j])   continue;
				if (map[i][j])   continue;
				sum++;
			}
		}

		min_result = min(sum, min_result);
		return;
	}

	int y = cctv[cur].y;
	int x = cctv[cur].x;

	switch (cctv[cur].num)
	{
	case 1:
		for (int i = 0; i < 4; i++) {
			direction_list.push_back({ i,y,x });
			back_tracking(direction_list, cur + 1);
			direction_list.pop_back();
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				direction_list.push_back({ d2[i][j],y,x });
			}
			back_tracking(direction_list, cur + 1);
			for (int j = 0; j < 2; j++) {
				direction_list.pop_back();
			}
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				direction_list.push_back({ d3[i][j],y,x });
			}
			back_tracking(direction_list, cur + 1);
			for (int j = 0; j < 2; j++) {
				direction_list.pop_back();
			}
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				direction_list.push_back({ d4[i][j],y,x });
			}
			back_tracking(direction_list, cur + 1);
			for (int j = 0; j < 3; j++) {
				direction_list.pop_back();
			}
		}
		break;
	case 5:
		for (int i = 0; i < 4; i++) {
			direction_list.push_back({ i,y,x });
		}
		back_tracking(direction_list, cur + 1);
		for (int j = 0; j < 4; j++) {
			direction_list.pop_back();
		}
		break;
	}
}

void solve()
{
	vector<List> direction_list;
	back_tracking(direction_list, 0);

	cout << min_result;
}

int main()
{
	sync_off;

	initialize();
	solve();

	return 0;
}