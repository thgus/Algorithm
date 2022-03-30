//https://suhak.tistory.com/77
#include<iostream>
#include<queue>
#include<vector>

#define MOD 1000000007

using namespace std;

vector<long long> dp(2501, 0);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= 2500; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i] = dp[i] + (dp[j] * dp[i - j - 1]);
			dp[i] %= MOD;
		}
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		if (n % 2 == 1)	cout << "0\n";
		else cout << dp[n / 2]<<"\n";
	}

	return 0;
}

