#include<iostream>

using namespace std;

int main() {
	int n, m;
	int arr[300][300];
	int max[300][300] = { 0 };

	cin >> n;
	cin >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	max[0][0] = arr[0][0];

	for (int i = 1; i < n; i++) {
		max[i][0] = max[i - 1][0] + arr[i][0];
	}

	for (int j = 1; j < m; j++) {
		max[0][j] = max[0][j - 1] + arr[0][j];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (max[i - 1][j] > max[i][j - 1])
				max[i][j] = arr[i][j] + max[i - 1][j];
			else
				max[i][j] = arr[i][j] + max[i][j - 1];
		}
	}

	cout << max[n - 1][m - 1];

	return 0;
}