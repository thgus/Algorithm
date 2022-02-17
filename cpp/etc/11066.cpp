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

		//[DP]������İ��� �˰���
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= n - i; j++) {
				
				//��� x,y��ǥ
				x = j;
				y = i + j;

				// sum[j-1]~sum[i+j] ��� �� ���� ������� ã��
				dp[x][y] = MaxValue;
				for (int k = j; k < i + j; k++) {
					dp[x][y] = min(dp[x][y], dp[x][k] + dp[k + 1][y]);			
				}
				// sum[j-1]~sum[i+j]��ĥ �� ��� ���ϱ�
				dp[x][y] += sum[i + j] - sum[j - 1];
			}

		}
		cout << dp[1][n] << "\n";

	}

	return 0;
}