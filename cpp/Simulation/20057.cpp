/*
20057번: 마법사 상어와 토네이도
https://www.acmicpc.net/problem/20057
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> map;

float persent[4][5][5] = { {{0,0,2,0,0},{0,10,7,1,0},{5,0,0,0,0},{0,10,7,1,0},{0,0,2,0,0}},
		{{0,0,0,0,0},{0,1,0,1,0},{2,7,0,7,2},{0,10,0,10,0},{0,0,5,0,0}},
		{{0,0,2,0,0},{0,1,7,10,0},{0,0,0,0,5},{0,1,7,10,0},{0,0,2,0,0}},
		{{0,0,5,0,0},{0,10,0,10,0},{2,7,0,7,2},{0,1,0,1,0},{0,0,0,0,0}} };

void initialize()
{
	cin >> n;
	map.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
}

int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };

bool isBoundary(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void print_map()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int tornado(int y, int x, int d)
{
	int out_sand = 0;
	float left_sand = map[y][x];
	int spread_sand = left_sand;

	int sy = y - 2;
	int sx = x - 2;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			float cur = left_sand / 100;
			cur *= persent[d][i][j];


			if (isBoundary(sy + i, sx + j))
			{
				map[sy + i][sx + j] += (int)cur;
			}
			else
			{
				out_sand += (int)cur;
			}

			spread_sand -= (int)cur;
		}
	}

	left_sand = spread_sand;

	sy = y + dy[d];
	sx = x + dx[d];
	if (isBoundary(sy, sx)) {
		map[sy][sx] += left_sand;
	}
	else 
	{
		out_sand += left_sand;
	}

	map[y][x] = 0;

	return out_sand;
}

void solve()
{
	int y, x;
	y = x = n / 2;

	int len = 1;
	int d = 0;

	int out_sum = 0;
	while (x != -1)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= len; j++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (!isBoundary(ny, nx))  goto RESULT;

				out_sum += tornado(ny, nx, d);

				print_map();
				y = ny, x = nx;
			}

			d = (d + 1) % 4;
		}
		len++;
	}

RESULT:
	cout << out_sum;
}

int main()
{
	sync_off;

	initialize();
	solve();

	return 0;
}