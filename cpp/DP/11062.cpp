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
	cout << dfs1(0, n - 1) << "\n";
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
	}

}

// 근우차례
// 근우는 자신이 선택한 값이 최대가 되도록 한다
int dfs1(int left, int right)
{
	if (dp[left][right] != -1)	return dp[left][right];
	if (left == right)	return vec[left];

	dp[left][right] = max(vec[left]+dfs2(left + 1, right), vec[right]+dfs2(left, right - 1));

	return dp[left][right];
}

// 명우
// 명우 입장에서는 근우가 더 작은 수를 만들도록 할 것임
int dfs2(int left, int right)
{
	if (dp[left][right] != -1)	return dp[left][right];
	if (left == right)	return 0;


	// (3,2,1) 이 구간에서 가질 수 있는 값은 총 6으로 정해져 있음
	// 왼쪽을 고르면 근우가 갖는 예상 값은 2이고 명우는 무조건 4를 얻을 수 있음
	// 오른쪽을 고르면 근우가 갖는 예상 값은 3이고 명우는 무조건 3을 얻을 수 있음
	// 명우가 더 높은 수를 얻으려면 근우가 더 낮은 수를 얻도록 만들어야 함.
	// 따라서 위의 경우에서는 명우는 왼쪽을 선택할 것이다.
	dp[left][right] = min(dfs1(left + 1, right), dfs1(left, right - 1));

	return dp[left][right];
}
