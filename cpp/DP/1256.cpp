#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define INF 1000000000
#define ll long long

using namespace std;

int n, m, k;
void solve()
{
	vector<vector<ll>> dp(n + m + 1, vector<ll>(m + 1));

	for (int i = 0; i <= n + m; i++)	dp[i][0] = 1;

	for (int i = 1; i <= n + m; i++)
	{
		for (int j = 1; j <= m && j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			if (dp[i][j] > INF)	dp[i][j] = INF;
		}
	}

	if (dp[n + m][m] < k)
	{
		cout << "-1";
		return;
	}

	int tm = m;
	for (int i = n + m; i > 0; i--)
	{
		if (dp[i - 1][tm] < k)
		{
			cout << "z";
			k -= dp[i - 1][tm];
			tm--;
		}
		else
		{
			cout << "a";
		}
	}

}

int main()
{
	cin >> n >> m >> k;
	solve();

	return 0;
}