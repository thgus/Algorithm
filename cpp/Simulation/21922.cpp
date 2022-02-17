/*
21922번: 학부 연구생 민상
https://www.acmicpc.net/problem/21922
*/


#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<bool>> visited;
queue<pair<int, int>> start;

void initialize()
{
	cin >> n >> m;
	visited.resize(n, vector<bool>(m,false));
	map.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				visited[i][j]=true;
				start.push({ i,j });
			}
		}
	}
}

//0: 위, 1:왼쪽, 2:아래, 3:오른쪽
int d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int next_dir[5][4] = { {0,1,2,3},{0,-1,2,-1},{-1,1,-1,3},{3,2,1,0},{1,0,3,2} };

void solve()
{
	while (!start.empty()) {
		int sy = start.front().first;
		int sx = start.front().second;
		start.pop();

		for (int i = 0; i < 4; i++) {
			int dir = i; 
			int cy = sy + d[i][0];
			int cx = sx + d[i][1];
			
			while (cy >= 0 && cy < n && cx >= 0 && cx < m) {
				if(map[cy][cx]==9)	break;
				visited[cy][cx]=true;
				if(map[cy][cx]){
					dir=next_dir[map[cy][cx]][dir];
					if(dir==-1)	break;
				}
				cy=cy+d[dir][0];
				cx=cx+d[dir][1];
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(visited[i][j])	result++;
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