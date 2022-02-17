/*
18808번: 스티커 붙이기
https://www.acmicpc.net/problem/18808
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m, k;
vector<vector<vector<bool>>> stickers;

void initialize()
{
	cin >> n >> m >> k;

	int a, b;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		vector<vector<bool>> temp(a, vector<bool>(b));

		int num = 0;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				cin >> num;
				temp[i][j] = (num) ? true : false;
			}
		}

		stickers.push_back(temp);
	}
}

vector<vector<bool>> map;

bool check_space(vector<vector<bool>>& sticker, int y, int x)
{
	int mn = sticker.size();
	int nm = sticker[0].size();

	for (int i = 0; i < mn; i++)
	{
		for (int j = 0; j < nm; j++)
		{
			if (y + i >= n || x + j >= m)    return false;

			if (!sticker[i][j])  continue;
			if (map[y + i][x + j])   return false;
		}
	}

	return true;
}

void fill_space(vector<vector<bool>> & sticker, int  y, int x)
{
	int mn = sticker.size();
	int nm = sticker[0].size();

	for (int i = 0; i < mn; i++)
	{
		for (int j = 0; j < nm; j++)
		{
			if (!sticker[i][j])  continue;
			map[y + i][x + j] = true;
		}
	}
}

void turn_90(vector<vector<bool>> & sticker)
{
	int mn = sticker.size();
	int nm = sticker[0].size();
	vector<vector<bool>> temp(nm, vector<bool>(mn));

	for (int i = 0; i < mn; i++)
	{
		for (int j = 0; j < nm; j++)
		{
			temp[j][mn - i - 1] = sticker[i][j];
		}
	}

	sticker = temp;
}

int cal_space()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j])   cnt++;
		}
	}
	return cnt;
}

void solve()
{
	map.resize(n, vector<bool>(m, false));

	for (int i = 0; i < k; i++)
	{
		vector<vector<bool>> sticker = stickers[i];
		for (int j = 0; j < 4; j++)
		{
			for (int y = 0; y < n; y++)
			{
				for (int x = 0; x < m; x++)
				{
					if (check_space(sticker, y, x))
					{
						fill_space(sticker, y, x);

						goto next;
					}
				}
			}

			turn_90(sticker);
		}

	next:;

	}
}

int main()
{
	sync_off;

	initialize();
	solve();

	cout << cal_space();

	return 0;
}