/*
2156번: 포도주 시식
https://www.acmicpc.net/problem/2156

d[n]=max(d[n-2]+vec[n],d[n-1])
*/

#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 10000
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<int> vec(MAX);

void initialize() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
}

vector<int> dp(MAX);
void solve() {
	dp[0] = vec[0];
	dp[1] = vec[0] + vec[1];
	dp[2] = max(dp[1], max(dp[0] + vec[2], vec[1] + vec[2]));
	//cout<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<" ";
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + vec[i], dp[i - 3] + vec[i - 1] + vec[i]));
		//cout<<dp[i]<<" ";
	}
	cout << dp[n - 1];
}

int main() {
	sync_off;
	initialize();
	solve();

	return 0;
}