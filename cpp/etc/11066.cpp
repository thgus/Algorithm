#include<iostream>
#include<algorithm>
#include<vector>

#define MaxValue 55555555

using namespace std;

int main() {
	int t;
	cin >> t;

	int n;
	int size;

	int x, y;
	int sum[501];
	sum[0] = 0;

	while(t--) {
		cin >> n;
		int dp[501][501] = { 0 };

		for (int i = 1; i <= n; i++) {
			cin >> size;
			sum[i] = sum[i - 1] + size;
		}

		//[DP]연쇄행렬곱셈 알고리즘
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= n - i; j++) {
				
				//행렬 x,y좌표
				x = j;
				y = i + j;

				// sum[j-1]~sum[i+j] 비용 중 가장 최저비용 찾기
				dp[x][y] = MaxValue;
				for (int k = j; k < i + j; k++) {
					dp[x][y] = min(dp[x][y], dp[x][k] + dp[k + 1][y]);			
				}
				// sum[j-1]~sum[i+j]합칠 때 비용 더하기
				dp[x][y] += sum[i + j] - sum[j - 1];
			}

		}
		cout << dp[1][n] << "\n";

	}

	return 0;
}