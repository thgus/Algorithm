#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> topology;
vector<int> pre;

void solve()
{
	// 1번 지점에서 다른 모든 지점에 갈 수 있다.
	// 어느 지점에서 출발하여도 1번 지점을 지나지 않고는 같은 지점으로 돌아올 수 없다.
	// 모든 지점에서 1번 지점으로 갈 수 있다.

	vector<pair<int, string>> dp(n + 1, { 0,"1" });
	queue<int> que;
	que.push(1);

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		if (cur == 1 && pre[cur] == 0)	continue;

		for (pair<int, int> p : topology[cur])
		{
			int next = p.first;
			int ncost = dp[cur].first + p.second;

			if (dp[next].first < ncost)
			{
				dp[next].first = ncost;
				dp[next].second = dp[cur].second + " " + to_string(next);
			}

			if (--pre[next] == 0)
			{
				que.push(next);
			}
		}

	}

	cout << dp[1].first << "\n";
	cout << dp[1].second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> m;

	topology.resize(n + 1);
	pre.resize(n + 1, 0);

	int a, b, c;
	while (m--)
	{
		cin >> a >> b >> c;

		topology[a].push_back({ b,c });
		pre[b]++;
	}

	solve();

	return 0;
}