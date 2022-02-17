/*
12094번: 2048 (Hard)
https://www.acmicpc.net/problem/12094
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 20
#define MAX 10
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> map;
vector<int> depth(11,0);

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

bool check_same(int save[][MAXN]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (save[i][j] != map[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void reset(int save[][MAXN]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = save[i][j];
		}
	}
}

void dfs(int time, int& max_result)
{
	int save[MAXN][MAXN];

	int cur_max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			save[i][j] = map[i][j];
			cur_max = max(cur_max, map[i][j]);
		}
	}
	
	if (cur_max <= depth[time]) return;
	if (time == MAX)
	{
        //depth가 MAX까지 갔을 때 최대 값에 따른 각 깊이 값을 저장
        //어차피 탐색은 MAX까지 밖에 못하므로 
        //이 이후로 부터는 가장 큰 MAX 깊이보다 값이 작거나 같으면 탐색 할 필요 없음.
        //예를 들면 MAX깊이에서 값이 1024라면 MAX-1깊이에서 MAX값은 512 혹은 1024가 나왔을 것이다.
        //  ( 이보다 작은 값이 나오면 다음 깊이에서 1024라는 값 자체가 나올 수 없음 )
        // MAX-2 깊이에서 MAX값은 256, 512, 1024 일 것이고....
        //이후 탐색 중 MAX-2깊이에서 MAX값이 256으로 나왔다면, 어차피 다음 MAX깊이에서 나올 수 있는 최대값은 1024이므로 탐색할 필요 없다.
        //탐색할 필요가 있는 것은 MAX-2깊이 기준으로 256보다 큰 값이 나왔을 때!
        if(depth[time]<cur_max){
            while (time > 0)
            {
                depth[time] = cur_max;
                cur_max /= 2;
                time--;
            }
        }
        return;
	}

	//위 : 0
	for (int i = 0; i < n; i++)
	{
		int index = -1;
		int num = -1;
		for (int j = 0; j < n; j++)
		{
			if (map[j][i] == 0)
				continue;
			if (num == map[j][i])
			{
				map[index][i] *= 2;
				num = -1;
			}
			else
			{
				index++;
				num = map[j][i];
				map[index][i] = num;
			}
			max_result = max(max_result, map[index][i]);
		}
		for (int j = index + 1; j < n; j++)
		{
			map[j][i] = 0;
		}
	}
	if (!check_same(save))
	{
		dfs(time + 1, max_result);
		reset(save);
	}

	//오른쪽 : 1
	for (int i = 0; i < n; i++)
	{
		int index = n;
		int num = -1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (map[i][j] == 0)
				continue;
			if (num == map[i][j])
			{
				map[i][index] *= 2;
				num = -1;
			}
			else
			{
				index--;
				num = map[i][j];
				map[i][index] = num;
			}
			max_result = max(max_result, map[i][index]);
		}

		for (int j = index - 1; j >= 0; j--)
		{
			map[i][j] = 0;
		}
	}
	if (!check_same(save))
	{
		dfs(time + 1, max_result);
		reset(save);
	}

	//아래 : 2
	for (int i = 0; i < n; i++)
	{
		int index = n;
		int num = -1;
		for (int j = n - 1; j >= 0; j--)
		{
			if (map[j][i] == 0)
				continue;
			if (num == map[j][i])
			{
				map[index][i] *= 2;
				num = -1;
			}
			else
			{
				index--;
				num = map[j][i];
				map[index][i] = num;
			}
			max_result = max(max_result, map[index][i]);
		}

		for (int j = index - 1; j >= 0; j--)
		{
			map[j][i] = 0;
		}
	}
	if (!check_same(save))
	{
		dfs(time + 1, max_result);
		reset(save);
	}

	//왼쪽 : 3
	for (int i = 0; i < n; i++)
	{
		int index = -1;
		int num = -1;
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0)
				continue;
			if (num == map[i][j])
			{
				map[i][index] *= 2;
				num = -1;
			}
			else
			{
				index++;
				num = map[i][j];
				map[i][index] = num;
			}
			max_result = max(max_result, map[i][index]);
		}

		for (int j = index + 1; j < n; j++)
		{
			map[i][j] = 0;
		}
	}
	if (!check_same(save))
	{
		dfs(time + 1, max_result);
		reset(save);
	}
}

void solve()
{
	int max_result = 0;
	dfs(0, max_result);
	cout << max_result;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}