#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m, k;

void initialize()
{
	cin >> n >> m >> k;
}

void solve()
{
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	dp[0][1] = 1;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	if (k == 0)
	{
		cout << dp[n][m];
	}
	else
	{
		int ylen = ((k - 1) / m) + 1;
		int xlen = ((k - 1) % m) + 1;

		cout << dp[ylen][xlen] * dp[n - ylen+1][m - xlen+1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	solve();

	return 0;
}