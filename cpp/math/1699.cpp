/*
1699번: 제곱수의 합
https://www.acmicpc.net/problem/1699
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
	sync_off;

	int n;
	cin >> n;

	vector<int> dp(n + 1);
	dp[0];
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 1;
		
		int sq = sqrt(i);
		if (sq * sq == i) {
			continue;
		}

		int min_value = 1e9;
		for (int j = 1; j <= sq; j++)
		{
			min_value = min(min_value, dp[j*j] + dp[i - (j*j)]);
		}
		dp[i] = min_value;
	}
	cout << dp[n];

	return 0;
}