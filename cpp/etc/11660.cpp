/*
11660번: 구간 합 구하기 5
https://www.acmicpc.net/problem/11660
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	sync_off;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(1025,vector<int>(1025,0));
	vector<vector<int>> sum(1025, vector<int>(1025, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> vec[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + vec[i][j];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] - (sum[x1-1][y2] + sum[x2][y1-1]) + sum[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}