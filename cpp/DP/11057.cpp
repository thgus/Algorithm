#include<iostream>
#include<vector>

#define MOD 10007

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> dp(10, 1);
	for (int i = 1; i < n; i++)
	{
		vector<int> temp(10, 0);
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				temp[j] += dp[k];
				temp[j] %= MOD;
			}
		}

		dp = temp;
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += dp[i];
		result %= MOD;
	}
	cout << result;

	return 0;
}

