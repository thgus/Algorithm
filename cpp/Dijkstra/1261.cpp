/*
1261번: 알고스팟
https://www.acmicpc.net/problem/1261
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 987654321
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
vector<vector<bool>> map;

void initialize()
{
	cin >> m >> n;
	map.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = (str[j]=='1') ? true : false;
		}
	}
}

struct Node
{
	int break_num;
	int y, x;

	bool operator<(const Node n) const
	{
		return break_num > n.break_num;
	}
};

bool isBoundary(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void solve()
{
	priority_queue<Node> pq;
	pq.push({ 0,0,0 });

	vector<vector<int>> visited(n, vector<int>(m, MAX));
	visited[0][0] = 0;

	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };

	while (!pq.empty())
	{
		int break_num = pq.top().break_num;
		int cy = pq.top().y;
		int cx = pq.top().x;
		pq.pop();

		if (visited[cy][cx] > break_num)   continue;
		if (cy == n - 1 && cx == m - 1)
		{
			cout << break_num;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (!isBoundary(ny, nx))   continue;

			int nbreak_num = break_num;
			if (map[ny][nx])
			{
				nbreak_num++;
			}

			if (visited[ny][nx] > nbreak_num)
			{
				visited[ny][nx] = nbreak_num;
				pq.push({ nbreak_num,ny,nx });
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