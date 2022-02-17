/*
21757번: 나누기
https://www.acmicpc.net/problem/21757
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec;

void initialize()
{
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
}

void plus_cal(vector<long long>& sum, int k) {
	vector<long long> dp(4, 0);
	dp[0] = 1;
	for (int i = 0; i < n-1; i++) {
		if (sum[i] != 0 && sum[i] % k == 0) {
			int p = sum[i] / k;
			if (p >= 4)    continue;

			dp[p] += dp[p - 1];
		}
	}

	cout << dp[3];
}

void zero_cal(vector<long long>& sum, int k) {
	unsigned long long zero_n = 0;
	for (int i = 0; i < n-1; i++) {
		if (sum[i] == 0) {
			zero_n++;
		}
	}

	zero_n = (zero_n) * (zero_n - 1) * (zero_n - 2) / 6;
	cout << zero_n;
}

void solve()
{
	vector<long long> sum(n, 0);

	sum[0] = vec[0];
	for (int i = 1; i < n; i++) {
		sum[i] += sum[i - 1] + vec[i];
	}

	if (sum[n - 1] == 0) {
		zero_cal(sum, 0);
	}
	else if (sum[n - 1] % 4 != 0) {
		cout << "0";
	}
	else{
		plus_cal(sum, sum[n - 1] / 4);
	}

}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}