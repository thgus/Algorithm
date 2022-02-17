/*
2579번: 계단 오르기
https://www.acmicpc.net/problem/2579

탐색 문제인줄알았능네 dp문제였어;; dp 넘 어렵다.
탐색으로 하면 시간 너무 오래 걸려;
계단을 오르는 2가지 경우
1. 계단을 1칸 올라감 (이는 3칸 이상 연속된 계단 이용 X)
2. 계단을 2칸 올라감
	노트에 정리해놓음
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> stairs;
	stairs.push_back(0);
	int n, score;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score;
		stairs.push_back(score);
	}

	vector<int> dp;
	dp.push_back(stairs[0]);
	dp.push_back(stairs[1]);		 //1
	if (n >= 2) {
		dp.push_back(stairs[1] + stairs[2]); //2
	}
	if (n >= 3) {
		dp.push_back(max(stairs[1] + stairs[3], stairs[2] + stairs[3])); //3
	}
	for (int i = 4; i <= n; i++) {
		dp.push_back(max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]));
	}
	cout << dp[n];

	return 0;
}