/*
14502번: 연구소
https://www.acmicpc.net/problem/14502
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAPMAX 8
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
int p[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
//변수로 계속 배열을 생성해줘서 시간이 늦어지는거 같아
//vector<vector<int>> laboratory(MAPMAX, vector<int>(MAPMAX));

int laboratorySave[MAPMAX][MAPMAX];
int laboratory[MAPMAX][MAPMAX];
vector<pair<int, int>> virous;
int maxSafeZone = -1;

void initialize()
{
	//y x
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			laboratory[i][j] = temp;
			laboratorySave[i][j] = temp;
			if (temp == 2)
			{
				virous.push_back({ i, j });
			}
		}
	}
}

int bfs()
{
	queue<pair<int, int>> que;

	for (int i = 0; i < virous.size(); i++)
	{
		que.push(virous[i]);
	}
	
	int y, _y;
	int x, _x;
	while (!que.empty())
	{
		y = que.front().first;
		x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			_x = x + p[i][1];
			_y = y + p[i][0];

			if (_y >= 0 && _y < n && _x >= 0 && _x < m)
			{
				if (laboratory[_y][_x] != 0)
				{
					continue;
				}
				laboratory[_y][_x] = 2;
				que.push({ _y, _x });
			}
		}
	}

	int safeZone = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (laboratory[i][j] == 0)
			{
				safeZone++;
			}

			laboratory[i][j] = laboratorySave[i][j];
		}
	}

	return safeZone;
}

void setWall(int remWall)
{
	if (remWall == 0)
	{
		int safeZone= bfs();
		if (maxSafeZone < safeZone) {
			maxSafeZone = safeZone;
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (laboratory[i][j] == 0)
			{
				laboratory[i][j] = 1;
				laboratorySave[i][j] = 1;
				setWall(remWall - 1);
				laboratory[i][j] = 0;
				laboratorySave[i][j] = 0;
			}
		}
	}
}

void sol()
{
	setWall(3);
	cout << maxSafeZone;
}

int main()
{
	sync_off;
	initialize();
	sol();

	return 0;
}