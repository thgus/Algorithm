/*
1149번: RGB거리
https://www.acmicpc.net/problem/1149
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	sync_off;

	int n;
	vector<vector<int>> cost;	
	vector<vector<int>> dp;
	vector<int> temp(4);
	
	cost.push_back(temp);
	dp.push_back(temp);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> temp[1] >> temp[2] >> temp[3];
		cost.push_back(temp);
	}

	//dp[1]
	temp[1] = cost[1][1]; temp[2] = cost[1][2]; temp[3] = cost[1][3];
	dp.push_back(temp);

	for (int i = 2; i <= n; i++) {
		temp[1] = min(dp[i - 1][2], dp[i - 1][3]) + cost[i][1];
		temp[2] = min(dp[i - 1][1], dp[i - 1][3]) + cost[i][2];
		temp[3] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][3];
		dp.push_back(temp);
	}

	/* i-2를 고려할 필요가 없지
	//dp[2]
	temp[1] = min(cost[1][2], cost[1][3]) + cost[2][1];
	temp[2] = min(cost[1][1], cost[1][3]) + cost[2][2];
	temp[3] = min(cost[1][1], cost[1][2]) + cost[2][3];
	dp.push_back(temp);
	// RB->G, RG->B, GB->R
	int case1, case2, case3;
	for (int i = 3; i <= n; i++) {
		case1 = min(cost[i - 2][1], cost[i - 2][3]) + cost[i - 1][2];
		case2 = min(cost[i - 2][1], cost[i - 2][2]) + cost[i - 1][3];
		case3 = min(cost[i - 2][2], cost[i - 2][3]) + cost[i - 1][1];
		temp[1] = min(case1, case2) + dp[i - 3][1] + cost[i][1];
		temp[2] = min(case2, case3) + dp[i - 3][2] + cost[i][2];
		temp[3] = min(case1, case3) + dp[i - 3][3] + cost[i][3];
		dp.push_back(temp);
	}
	*/
	/*
	for (int i = 1; i < dp.size(); i++) {
		cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << "\n";
	}
	*/

	int result = min(dp[n][1], min(dp[n][2], dp[n][3]));
	cout << result;
	
	return 0;
}