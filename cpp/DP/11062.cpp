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

// �ٿ�����
// �ٿ�� �ڽ��� ������ ���� �ִ밡 �ǵ��� �Ѵ�
int dfs1(int left, int right)
{
	if (dp[left][right] != -1)	return dp[left][right];
	if (left == right)	return vec[left];

	dp[left][right] = max(vec[left]+dfs2(left + 1, right), vec[right]+dfs2(left, right - 1));

	return dp[left][right];
}

// ���
// ��� ���忡���� �ٿ찡 �� ���� ���� ���鵵�� �� ����
int dfs2(int left, int right)
{
	if (dp[left][right] != -1)	return dp[left][right];
	if (left == right)	return 0;


	// (3,2,1) �� �������� ���� �� �ִ� ���� �� 6���� ������ ����
	// ������ ���� �ٿ찡 ���� ���� ���� 2�̰� ���� ������ 4�� ���� �� ����
	// �������� ���� �ٿ찡 ���� ���� ���� 3�̰� ���� ������ 3�� ���� �� ����
	// ��찡 �� ���� ���� �������� �ٿ찡 �� ���� ���� �򵵷� ������ ��.
	// ���� ���� ��쿡���� ���� ������ ������ ���̴�.
	dp[left][right] = min(dfs1(left + 1, right), dfs1(left, right - 1));

	return dp[left][right];
}
