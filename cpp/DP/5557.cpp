#include<iostream>
#include<vector>

#define ll long long
using namespace std;

int n;
vector<int> vec;

void solve()
{
	vector<vector<ll>> dp(n, vector<ll>(21, 0));
	
	dp[0][vec[0]] = 1;

	for (int i = 1; i < n-1; i++)
	{
		int num = vec[i];
		for (int j = 0; j <= 20; j++)
		{
			if (j + num <= 20)	dp[i][j + num] += dp[i - 1][j];
			if (j - num >= 0)	dp[i][j - num] += dp[i - 1][j];
		}

		int f = 1;
	}

	cout << dp[n-2][vec[n - 1]];
}

int main()
{
	cin >> n;

	vec.resize(n);
	for (int i = 0; i < n; i++)	cin >> vec[i];

	solve();

	return 0;
}