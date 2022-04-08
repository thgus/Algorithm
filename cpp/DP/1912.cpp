/*
1912번: 연속합
https://www.acmicpc.net/problem/1912
*/

#include <iostream>
#include <vector>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

using namespace std;

void solve()
{
	int n;
	cin >> n;

	ll m = LLONG_MIN;
	vector<ll> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];

		if (m < vec[i])	m = vec[i];
	}

	ll last = LLONG_MIN;
	for (int i = 0; i < n; i++)
	{
		ll cur = vec[i];
		cur += (last == LLONG_MIN) ? 0 : last;
		if (cur > 0)	last = cur;
		else last = LLONG_MIN;

		if (m < last)	m = last;
	}

	cout << m;
}

int main()
{
	sync_off;

	solve();

	return 0;
}