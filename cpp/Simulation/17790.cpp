/*
17780번: 새로운 게임
https://www.acmicpc.net/problem/17780
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

struct Horse {
	int num;
	int d;
};

struct Node {
	int time;
	int num;
	int y, x;

	bool operator<(const Node n) const {
		if (n.time == time) {
			return n.num < num;
		}
		else {
			return n.time < time;
		}
	}
};

int n, k;
vector<vector<int>> m;
vector<vector<deque<Horse>>> horses;
priority_queue<Node> que;

bool isBoundary(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) {
		return true;
	}
	else {
		return false;
	}
}

void initialize()
{
	cin >> n >> k;
	m.resize(n, vector<int>(n));
	horses.resize(n, vector<deque<Horse>>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	int a, b, c;
	for (int i = 1; i <= k; i++) {
		cin >> a >> b >> c;
		a--; b--;
		horses[a][b].push_back({ i,c });
		que.push({ 1,i,a,b });
	}

}

int turnDirection(int d) {
	switch (d) {
		case 1:
			return 2;
		case 2:
			return 1;
		case 3:
			return 4;
		case 4:
			return 3;
	}
}

void print_vec() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (horses[i][j].empty()) {
				cout << "0";
			}
			else {
				cout << horses[i][j].front().num;
			}
		}
		cout << "\n";
	}
}

void solve()
{
	int d[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };

	while (!que.empty()) {
		Node cur = que.top();
		que.pop();

		if (cur.time > 1000) {
			continue;
		}

		//print_vec();

		Horse cur_horse = horses[cur.y][cur.x].front();
		int next_y = cur.y + d[cur_horse.d][0];
		int next_x = cur.x + d[cur_horse.d][1];
		if (!isBoundary(next_y, next_x) || m[next_y][next_x] == 2) {
			horses[cur.y][cur.x].front().d = turnDirection(horses[cur.y][cur.x].front().d);
			cur_horse = horses[cur.y][cur.x].front();

			next_y = cur.y + d[cur_horse.d][0];
			next_x = cur.x + d[cur_horse.d][1];
		}

		if (!isBoundary(next_y, next_x) || m[next_y][next_x] == 2)	continue;

		if (m[next_y][next_x] == 0) {
			if (horses[next_y][next_x].empty()) {
				que.push({ cur.time + 1,cur.num,next_y,next_x });
			}

			while (!horses[cur.y][cur.x].empty()) {
				horses[next_y][next_x].push_back(horses[cur.y][cur.x].front());
				horses[cur.y][cur.x].pop_front();
			}
		}
		else if (m[next_y][next_x] == 1) {
			if (horses[next_y][next_x].empty()) {
				if (horses[cur.y][cur.x].front().num < horses[cur.y][cur.x].back().num) {
					que.push({ cur.time,horses[cur.y][cur.x].back().num,next_y,next_x });
				}
				else{
					que.push({ cur.time + 1,horses[cur.y][cur.x].back().num,next_y,next_x });
				}
			}

			while (!horses[cur.y][cur.x].empty()) {
				horses[next_y][next_x].push_back(horses[cur.y][cur.x].back());
				horses[cur.y][cur.x].pop_back();
			}
		}

		if (horses[next_y][next_x].size() >= 4) {
			cout << cur.time;
			return;
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