#include<iostream>
#include<vector>

using namespace std;

#define  mod 1000000003
#define ll long long

int n, k;

void solve()
{
	if (k == 1)
	{
		cout << n;
		return;
	}

		
	vector<vector<ll>> dp(n+1, vector<ll>(n + 1, 0));
	// �Ϸķ� �ټ����� ���ڿ��� ������ ���ڸ� �����ϰ� �̱� ����� ��
	// 1. ù��°�� ����
	// 2. ù��°�� �Ȼ���

	dp[1][1] = 1;
	dp[2][1] = 2;

	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			ll a, b;
			a = b = 0;

			a = (j - 1 == 0) ? 1 : dp[i - 2][j - 1];
			if (i - 2 >= j) {
				b = dp[i - 1][j];
			}

			dp[i][j] = (a + b) % mod;
		}

	}

	
	cout << (dp[n - 1][k] + dp[n - 3][k - 1]) % mod;

}

int main()
{
	cin >> n >> k;
	solve();

	return 0;
}