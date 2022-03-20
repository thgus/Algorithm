// https://yeeybook.tistory.com/137
// https://loosie.tistory.com/212

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> vec;
vector<vector<int>> dp;

int dfs1(int left, int right);
int dfs2(int left, int right);

void solve(int n)
{
	dp.clear();
	dp.resize(n, vector<int>(n, -1));
	dfs1(0, n - 1);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;

		vec.clear();
		vec.resize(n);
		for (int i = 0; i < n; i++)	cin >> vec[i];

		solve(n);

		cout << dp[0][n - 1] << "\n";
	}

}

// 근우. 근우는 큰 값을 고르도록 유도
int dfs1(int left, int right)
{
	if (left == right)
	{
		dp[left][right] = vec[left];
		return dp[left][right];
	}
	//if (left > right)	return 0;

	if (dp[left][right] != -1)	return dp[left][right];

	dp[left][right] = max(vec[left]+dfs2(left + 1, right), vec[right]+dfs2(left, right - 1));

	return dp[left][right];
}

// 명우. 명우 차례에 명우가 더 작은 수를 선택하도록 유도
int dfs2(int left, int right)
{
	//if (left > right)	return 0;
	if (left == right)
	{
		dp[left][right] = 0;
		return 0;
	}
	if (dp[left][right] != -1)	return dp[left][right];

	dp[left][right] = min(dfs1(left + 1, right), dfs1(left, right - 1));

	return dp[left][right];
}
