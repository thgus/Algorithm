/*
20056번: 마법사 상어와 파이어볼
https://www.acmicpc.net/problem/20056
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

#define MAX 50
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, mi, k;

struct Node {
	int num = 0;
	int m = 0, s = 0, d = 0;
	int direction[2] = { 0,0 };
};

Node map[MAX + 1][MAX + 1];

void initialize()
{
	cin >> n >> mi >> k;

	int r, c, m, s, d;
	for (int i = 0; i < mi; i++) {
		cin >> r >> c >> m >> s >> d;
		
		map[r-1][c-1].num++;

		map[r-1][c-1].m += m;
		map[r-1][c-1].s += s;
		map[r-1][c-1].d += d;

		map[r-1][c-1].direction[d % 2]++;
	}
}

void merge_fireball(int r, int c)
{
	map[r][c].m /= 5;
	map[r][c].s /= map[r][c].num;

	//4. 질량이 0인 파이어볼은 소멸되어 없어진다.
	if (map[r][c].m == 0) {
		map[r][c].num = 0;
		map[r][c].s = 0;
		map[r][c].d = 0;
		map[r][c].direction[0] = map[r][c].direction[1] = 0;
		return;
	}

	map[r][c].num = 4;
}

int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int next_d[2][4] = { {0,2,4,6},{1,3,5,7} };

void solve()
{
	while (k--)
	{
		Node temp[MAX + 1][MAX + 1];

		//1. 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (map[y][x].num == 1) {
					int ny = y + dy[map[y][x].d] * map[y][x].s;
					int nx = x + dx[map[y][x].d] * map[y][x].s;

					//0 1 2 3 4
					// -10 % 5 = 5  
					if (ny < 0)
						ny = n - (abs(ny) % n);
					ny %= n;

					if (nx < 0)
						nx = n - (abs(nx) % n);
					nx %= n;

					temp[ny][nx].num++;
					temp[ny][nx].d += map[y][x].d;
					temp[ny][nx].m += map[y][x].m;
					temp[ny][nx].s += map[y][x].s;
					temp[ny][nx].direction[map[y][x].d % 2]++;
				}
				else if (map[y][x].num == 4) {
					int next = (map[y][x].direction[0] == 0 || map[y][x].direction[1] == 0) ? 0 : 1;
					for (int i = 0; i < 4; i++)
					{
						int ny = y + dy[next_d[next][i]] * map[y][x].s;
						int nx = x + dx[next_d[next][i]] * map[y][x].s;

						if (ny < 0)
							ny = n - (abs(ny) % n);
						ny %= n;

						if (nx < 0)
							nx = n - (abs(nx) % n);
						nx %= n;

						temp[ny][nx].num++;
						temp[ny][nx].d += next_d[next][i];
						temp[ny][nx].m += map[y][x].m;
						temp[ny][nx].s += map[y][x].s;
						temp[ny][nx].direction[next]++;
					}
				}
			}
		}

		//2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				if (temp[r][c].num >= 2)
				{	
					temp[r][c].m /= 5;
					temp[r][c].s /= temp[r][c].num;

					//4. 질량이 0인 파이어볼은 소멸되어 없어진다.
					if (temp[r][c].m == 0)
					{
						temp[r][c].num = 0;
						temp[r][c].s = 0;
						temp[r][c].d = 0;
						temp[r][c].direction[0] = temp[r][c].direction[1] = 0;
						continue;
					}

					temp[r][c].num = 4;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = temp[i][j];
			}
		}
	}

	//마법사 상어가 이동을 K번 명령한 후, 남아있는 파이어볼 질량의 합을 구해보자.
	int total_m = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			total_m += map[i][j].m * map[i][j].num;
		}
	}
	cout << total_m;
}

int main()
{
	sync_off;

	initialize();
	solve();

	return 0;
}