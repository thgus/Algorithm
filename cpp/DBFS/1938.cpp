/*
1938번: 통나무 옮기기
https://www.acmicpc.net/problem/1938
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Node {
	int y, x;
	bool isVertical;
};

int n;
vector<vector<char>> vec;
Node start;
Node goal;

void initialize()
{
	cin >> n;
	vec.resize(n, vector<char>(n));

	pair<int, int> s[3];   int s_index = 0;
	pair<int, int> e[3];   int e_index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];

			if (vec[i][j] == 'B') {
				s[s_index].first = i;
				s[s_index].second = j;
				s_index++;
			}
			else if (vec[i][j] == 'E') {
				e[e_index].first = i;
				e[e_index].second = j;
				e_index++;
			}
		}
	}

	bool isStartVert;
	isStartVert = (s[0].second == s[1].second) ? true : false;
	start = { s[1].first,s[1].second,isStartVert };

	bool isEndVert = (e[0].second == e[1].second) ? true : false;
	isEndVert = (e[0].second == e[1].second) ? true : false;
	goal = { e[1].first,e[1].second,isEndVert };

}

bool isBoundary(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) {
		return true;
	}
	else {
		return false;
	}
}

void solve()
{
	vector<vector<bool>> v_visited(n, vector<bool>(n, false));
	vector<vector<bool>> h_visited(n, vector<bool>(n, false));

	if (start.isVertical)    v_visited[start.y][start.x] = true;
	else if (!start.isVertical)  h_visited[start.y][start.x] = true;

	int d[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
	queue<pair<int, Node>> que;
	que.push({ 0,start });
	while (!que.empty()) {
		int time = que.front().first;
		int cy = que.front().second.y;
		int cx = que.front().second.x;
		bool isVertical = que.front().second.isVertical;
		que.pop();

		if (cy == goal.y && cx == goal.x && isVertical == goal.isVertical) {
			cout << time;
			return;
		}

		if (isVertical) {
			if (h_visited[cy][cx])   goto MOVE;
			for (int ny = cy - 1; ny <= cy + 1; ny++) {
				for (int nx = cx - 1; nx <= cx + 1; nx++) {
					if (!isBoundary(ny, nx) || vec[ny][nx] == '1')	goto MOVE;
				}
			}
			h_visited[cy][cx] = true;
			que.push({ time + 1,{cy,cx,false} });
		}
		else {
			if (v_visited[cy][cx])   goto MOVE;
			for (int ny = cy - 1; ny <= cy + 1; ny++) {
				for (int nx = cx - 1; nx <= cx + 1; nx++) {
					if (!isBoundary(ny, nx) || vec[ny][nx] == '1')	goto MOVE;
				}
			}
			v_visited[cy][cx] = true;
			que.push({ time + 1,{cy,cx,true} });
		}

	MOVE:

		for (int i = 0; i < 4; i++) {
			int ny = cy + d[i][0];
			int nx = cx + d[i][1];

			if (!isBoundary(ny, nx) || vec[ny][nx] == '1')  continue;

			if (isVertical && !v_visited[ny][nx]) {
				v_visited[ny][nx] = true;

				if (!isBoundary(ny - 1, nx) || vec[ny - 1][nx] == '1')    continue;
				if (!isBoundary(ny + 1, nx) || vec[ny + 1][nx] == '1')    continue;
				que.push({ time + 1,{ny,nx,true} });
			}

			if (!isVertical && !h_visited[ny][nx]) {
				h_visited[ny][nx] = true;
				if (!isBoundary(ny, nx - 1) || vec[ny][nx - 1] == '1')    continue;
				if (!isBoundary(ny, nx + 1) || vec[ny][nx + 1] == '1')    continue;
				que.push({ time + 1,{ny,nx,false} });
			}
		}
	}

	cout << "0";
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}