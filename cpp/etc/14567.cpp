/*
14567번: 선수과목
https://www.acmicpc.net/problem/14567
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m;
vector<vector<int>> topology;
vector<int> pre;

void solve()
{
	vector<int> isLearn(n + 1, 0);
	queue<pair<int, int>> que;
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == 0)
		{
			//pre[i] = -1;
			que.push({ i,1 });
			isLearn[i] = 1;
		}
	}

	while (!que.empty())
	{
		int num = que.front().first;
		int time = que.front().second;
		que.pop();

		for (int next : topology[num])
		{
			if ((--pre[next]) == 0)
			{
				que.push({ next,time + 1 });
				isLearn[next] = time + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << isLearn[i] << " ";
	}
}

int main()
{
	sync_off;

	cin >> n >> m;
	topology.resize(n+1);
	pre.resize(n + 1, 0);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		topology[a].push_back(b);
		pre[b]++;
	}

	solve();

	return 0;
}