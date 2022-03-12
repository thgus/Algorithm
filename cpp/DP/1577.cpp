// https://www.acmicpc.net/problem/1577

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define ll unsigned long long

int n, m;
int k;
vector<vector<int>> construction;

void initialize()
{
	cin >> n >> m;
	cin >> k;

	int a, b, c, d;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b >> c >> d;
		vector<int> temp = { a,b,c,d };
		construction.push_back(temp);
	}
}

void solve()
{
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
	vector<vector<vector<bool>>> notGo(2, vector<vector<bool>>(n + 1, vector<bool>(m + 1, false)));

	for (int i = 0; i < k; i++)
	{
		int a = construction[i][0];
		int b = construction[i][1];
		int c = construction[i][2];
		int d = construction[i][3];

		if (a == c)	// 가로
		{
			if (b > d)
			{
				notGo[0][c][d] = true;
			}
			else
			{
				notGo[0][a][b] = true;
			}
		}
		else // 세로
		{
			if (a > c)
			{
				notGo[1][c][d] = true;
			}
			else
			{
				notGo[1][a][b] = true;
			}
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 && j == 0)	continue;

			ll left, top;
			top = (i - 1 >= 0) ? ((notGo[1][i - 1][j]) ? 0 : dp[i - 1][j]) : 0;
			left = (j - 1 >= 0) ? ((notGo[0][i][j - 1]) ? 0 : dp[i][j - 1]) : 0;

			dp[i][j] = left + top;
		}
	}

	cout << dp[n][m];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	solve();

	return 0;
}