/*
10875번: 뱀
https://www.acmicpc.net/problem/10875
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int l;
queue<pair<int, char>> que;

void initialize()
{
	cin >> l;
	int n;
	cin >> n;

	int t;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> t >> c;
		que.push({ t,c });
	}
}

int d[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int change_direction(char c, int d) {
	switch (d) {
	case 0:
		if (c == 'L')  return 1;
		else if (c == 'R') return 3;
	case 1:
		if (c == 'L')  return 2;
		else if (c == 'R') return 0;
	case 2:
		if (c == 'L')  return 3;
		else if (c == 'R') return 1;
	case 3:
		if (c == 'L')  return 0;
		else if (c == 'R') return 2;
	}
}

vector<vector<bool>> visited;
void print_visited() {
	cout << "\n";
	for (int i = 0; i < visited.size(); i++) {
		for (int j = 0; j < visited[i].size(); j++) {
			cout << visited[i][j];
		}
		cout << "\n";
	}
}

int right(vector<pair<int, pair<int, int>>> & vertical, vector<pair<int, pair<int, int>>> & horizon, int n, int mul, int y, int& x) {
	int result = INT_MAX;
	int start_x = x; int end_x = x + d[0][1] * mul;

	if (end_x >= n) {
		result = min(result, (n - x));

		end_x = n - 1;
	}

	for (int i = 0; i < vertical.size(); i++) {
		int w = vertical[i].first;
		int start_y = vertical[i].second.first;
		int end_y = vertical[i].second.second;
		if (start_x < w && w <= end_x) {
			if (start_y <= y && y <= end_y) {
				result = min(result, w - x);

				end_x = w;
			}
		}
	}

	for (int i = 0; i < horizon.size(); i++) {
		int h = horizon[i].first;
		int hs = horizon[i].second.first;
		int he = horizon[i].second.second;
		if (h == y) {
			if (hs <= end_x && end_x <= he) {
				result = min(result, hs - x);

				end_x = hs;
			}
		}
	}

	/*
	for (int i = start_x; i <= end_x; i++) {
		visited[y][i] = true;
	}
	print_visited();
	*/

	horizon.push_back({ y,{start_x,end_x} });
	x = end_x;
	return result;
}

int left(vector<pair<int, pair<int, int>>> & vertical, vector<pair<int, pair<int, int>>> & horizon, int n, int mul, int y, int& x) {
	int result = INT_MAX;
	int start_x = x + d[2][1] * mul; int end_x = x;

	if (start_x < 0) {
		result = min(result, x + 1);

		start_x = 0;
	}

	for (int i = 0; i < vertical.size(); i++) {
		int w = vertical[i].first;
		int start_y = vertical[i].second.first;
		int end_y = vertical[i].second.second;

		if (start_x <= w && w < end_x) {
			if (start_y <= y && y <= end_y) {
				result = min(result, x - w);

				start_x = w;
			}
		}
	}

	for (int i = 0; i < horizon.size(); i++) {
		int h = horizon[i].first;
		int hs = horizon[i].second.first;
		int he = horizon[i].second.second;
		if (h == y) {
			if (hs <= start_x && start_x <= he) {
				result = min(result, x - he);

				start_x = he;
			}
		}
	}

	/*
	for (int i = start_x; i <= end_x; i++) {
		visited[y][i] = true;
	}
	print_visited();
	*/

	horizon.push_back({ y,{start_x,end_x} });
	x = start_x;
	return result;
}

int up(vector<pair<int, pair<int, int>>> & vertical, vector<pair<int, pair<int, int>>> & horizon, int n, int mul, int& y, int x) {
	int result = INT_MAX;
	int start_y = y + d[1][0] * mul;  int end_y = y;

	if (start_y < 0) {
		result = min(result, y + 1);

		start_y = 0;
	}

	for (int i = 0; i < horizon.size(); i++) {
		int h = horizon[i].first;
		int start_x = horizon[i].second.first;
		int end_x = horizon[i].second.second;

		if (start_y <= h && h < end_y) {
			if (start_x <= x && x <= end_x) {
				result = min(result, y - h);

				start_y = h;
			}
		}
	}

	for (int i = 0; i < vertical.size(); i++) {
		int w = vertical[i].first;
		int ws = vertical[i].second.first;
		int we = vertical[i].second.second;
		if (w == x) {
			if (ws <= start_y && start_y <= we) {
				result = min(result, y - we);

				start_y = we;
			}
		}
	}

	/*
	for (int i = start_y; i <= end_y; i++) {
		visited[i][x] = true;
	}
	print_visited();
	*/

	vertical.push_back({ x,{start_y,end_y} });
	y = start_y;

	return result;
}

int down(vector<pair<int, pair<int, int>>> & vertical, vector<pair<int, pair<int, int>>> & horizon, int n, int mul, int& y, int x) {
	int result = INT_MAX;
	int start_y = y;  int end_y = y + d[3][0] * mul;

	if (end_y >= n) {
		result = min(result, n-y);

		end_y = n - 1;
	}

	for (int i = 0; i < horizon.size(); i++) {
		int h = horizon[i].first;
		int start_x = horizon[i].second.first;
		int end_x = horizon[i].second.second;

		if (start_y < h && h <= end_y) {
			if (start_x <= x && x <= end_x) {
				result = min(result, h - y);

				end_y = h;
			}
		}
	}

	for (int i = 0; i < vertical.size(); i++) {
		int w = vertical[i].first;
		int ws = vertical[i].second.first;
		int we = vertical[i].second.second;
		if (w == x) {
			if (ws <= end_y && end_y <= we) {
				result = min(result, ws - y);

				end_y = ws;
			}
		}
	}

	/*
	for (int i = start_y; i <= end_y; i++) {
		visited[i][x] = true;
	}
	print_visited();
	*/

	vertical.push_back({ x,{start_y,end_y} });
	y = end_y;

	return result;
}

void solve()
{
	int direction = 0;
	int y = l, x = l;
	int n = l * 2 + 1;

	//visited.resize(n,vector<bool>(n,false));

	vector<pair<int, pair<int, int>>> horizon;
	vector<pair<int, pair<int, int>>> vertical;

	int result = INT_MAX;
	long long time = 0;
	while (!que.empty()) {
		int mul = que.front().first;
		char c = que.front().second;
		que.pop();

		switch (direction) {
		case 0:
			result = right(vertical, horizon, n, mul, y, x);
			break;
		case 1:
			result = up(vertical, horizon, n, mul, y, x);
			break;
		case 2:
			result = left(vertical, horizon, n, mul, y, x);
			break;
		case 3:
			result = down(vertical, horizon, n, mul, y, x);
			break;
		}

		if (result != INT_MAX) {
			time += result;
			cout << time;
			return;
		}

		time += mul;
		direction = change_direction(c, direction);
	}

	switch (direction) {
	case 0:
		result = right(vertical, horizon, n, n, y, x);
		break;
	case 1:
		result = up(vertical, horizon, n, n, y, x);
		break;
	case 2:
		result = left(vertical, horizon, n, n, y, x);
		break;
	case 3:
		result = down(vertical, horizon, n, n, y, x);
		break;
	}

	time += result;
	cout << time;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}