#include<iostream>
#include<vector>

#define mod 1000000000

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= n; i++)	dp[1][i] = 1;

	for (int i = 2; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			int sum = 0;
			for (int l= 0; l <= j; l++)
			{
				sum += dp[i - 1][j - l];
				sum %= mod;
			}
			dp[i][j] = sum;
		}
	}

	cout << dp[k][n];

	return 0;
}