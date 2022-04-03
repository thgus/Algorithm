/*
2632번:피자판매
https://www.acmicpc.net/problem/2632
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ll long long

using namespace std;

int q;
int as, bs;
vector<int> a;
vector<int> b;

void cal_dp(vector<ll>& dp, vector<int> &arr, int s)
{
	for (int i = 0; i < s; i++)
	{
		int index = i;
		ll sum = 0;
		do
		{
			sum += arr[index];
			if (sum > q)	break;

			dp[sum]++;
			index++;
			index %= s;
		} while (index != i);
	}

	ll sum = 0;
	for (int i = 0; i < s; i++)	sum += arr[i];
	if (sum <= q)	dp[sum] -= (s - 1);
}

void solve()
{
	vector<ll> dp1(q+1, 0);
	vector<ll> dp2(q+1, 0);

	cal_dp(dp1, a, as);
	cal_dp(dp2, b, bs);

	ll result = dp1[q] + dp2[q];
	for (int i = 1; i < q; i++)	result += dp1[i] * dp2[q - i];

	cout << result;
}

int main()
{
	sync_off;

	//initialize===========================================
	cin >> q;
	cin >> as >> bs;
	a.resize(as, 0);
	b.resize(bs, 0);

	for (int i = 0; i < as; i++)	cin >> a[i];
	for (int i = 0; i < bs; i++)	cin >> b[i];

	//=====================================================
	solve();

	return 0;
}