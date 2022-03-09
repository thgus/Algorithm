#include<iostream>
#include<vector>

#define ll long long
#define mod 1000000007

using namespace std;

// ���,,, DP������ ������ �ؾ߰ڴ�
// https://blog.naver.com/PostView.nhn?blogId=pasdfq&logNo=222192164666&parentCategoryNo=&categoryNo=13&viewDate=&isShowPopularPosts=true&from=search
// �� �� ???

vector<int> parent;

int find_parent(int i)
{
	if (parent[i] == i)	return i;
	return parent[i] = find_parent(parent[i]);
}

int group = 0;
vector<ll> dp;
void solve(int x, int y)
{
	int px = find_parent(x);
	int py = find_parent(y);
	
	if (px != py)
	{
		group--;
		parent[py] = px;
	}

	cout << dp[group] << "\n";
}

void make_dp(int n)
{
	// dp[i][j]= dp[i-1][j-1] + j*dp[i-1][j]
	//	dp[i-1][j-1] => ���� �߰��� ��� i�� ��� �׷쿡�� ���� ���� ��� i�� �ϳ��� �׷��� �ǰ� ������ i-1������ j-1���� �׷��� ����� ��
	//	dp[i-1][j-1] * j => ���� �߰��� ��� i�� j���� �׷� �� �ϳ��� ���� ��� * i�� ���� ����� �� j����

	vector<ll> last(2, 0);
	
	dp[0] = dp[1] = 1;
	last[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		vector<ll> cur(i + 1);
		cur[1] = cur[i] = 1;
		for (ll j = 2; j < i; j++)
		{
			cur[j] = (last[j - 1] + (j * last[j]) % mod) % mod;
			
			dp[i] += cur[j];
			dp[i] %= mod;
		}

		last = cur;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	parent.resize(n+1);
	dp.resize(n + 1, 2);
	group = n;
	
	make_dp(n);

	for (int i = 1; i <= n; i++)	parent[i] = i;

	int x, y;
	while (m--)
	{
		cin >> x >> y;
		solve(x, y);
	}

	return 0;
}