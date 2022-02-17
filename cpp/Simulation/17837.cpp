/*
17837번: 새로운 게임 2
https://www.acmicpc.net/problem/17837
*/

#include <iostream>
#include <vector>
#include <stack>

#define MAX 1000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct horse {
	int y, x, direction;
};

int n, k;
vector<vector<int>> color;
vector<vector<stack<int>>> map;
vector<horse> horses;

int change_direction(int d) {
	switch (d) {
	case 0:
		return 1;
	case 1:
		return 0;
	case 2:
		return 3;
	case 3:
		return 2;
	}
}

void initialize()
{
	cin >> n >> k;
	color.resize(n, vector<int>(n));
	map.resize(n, vector<stack<int>>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> color[i][j];
		}
	}

	int y, x, d;
	for (int i = 0; i < k; i++) {
		cin >> y >> x >> d;
		horses.push_back({ y-1,x-1,d-1,});
		map[y - 1][x - 1].push(i);
	}
}

void print_map(){
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].size() == 0)	cout << "0 ";
			else {
				cout << map[i][j].top() + 1 << " ";
			}
		}
		cout << "\n";
	}
}

bool isTrue(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) {
		return true;
	}
	else {
		return false;
	}
}

void solve()
{
	int sum = 0;
	int d[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

	while (++sum <= MAX) {
		for (int i = 0; i < horses.size(); i++) {
			int cur_y = horses[i].y;
			int cur_x = horses[i].x;
			int cur_direction = horses[i].direction;

			int next_y = cur_y + d[cur_direction][0];
			int next_x = cur_x + d[cur_direction][1];

			if (!isTrue(next_y, next_x) || color[next_y][next_x] == 2) {
				cur_direction = change_direction(cur_direction);
				horses[i].direction = cur_direction;
				
				next_y = cur_y + d[cur_direction][0];
				next_x = cur_x + d[cur_direction][1];
			}
			
			if (isTrue(next_y, next_x)) {
				if (color[next_y][next_x] == 2)	continue;

				stack<int> move_horse;
				int cur_num = -1;
				while (cur_num != i) {
					cur_num = map[cur_y][cur_x].top();
					move_horse.push(cur_num);
					map[cur_y][cur_x].pop();

					horses[cur_num].y = next_y;
					horses[cur_num].x = next_x;
				}

				if (color[next_y][next_x] == 1) {
					stack<int> temp;
					while (!move_horse.empty()) {
						temp.push(move_horse.top());
						move_horse.pop();
					}
					move_horse = temp;
				}

				while (!move_horse.empty()) {
					map[next_y][next_x].push(move_horse.top());
					move_horse.pop();
				}

				if (map[next_y][next_x].size() >= 4) {
					cout << sum;
					return;
				}
			}
		}
	}

	cout << "-1";
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}