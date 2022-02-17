/*
1285번: 동전 뒤집기
https://www.acmicpc.net/problem/1285
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<bool>> vec;

void initialize()
{
	cin >> n;
	char c;

	vec.resize(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == 'H') {
				vec[i][j] = true;
			}
			else {
				vec[i][j] = false;
			}
		}
	}
}

void solve()
{
	int t_coin_size = 1e9;

	for (int i = 0; i < (1 << n); i++) {
		vector<vector<bool>> temp = vec;
		for (int k = 0; k < n; k++) {
			if (!(~i & (1 << k))) {
				for (int l = 0; l < n; l++) {
					(temp[k][l])?temp[k][l] = false:temp[k][l] = true;
				}
			}
		}

		int sum = 0;
		for (int k = 0; k < n; k++) {
			int cur_c = 0;
			for (int l = 0; l < n; l++) {
				if (temp[l][k])	cur_c++;
			}

			sum += min(cur_c, n - cur_c);
		}

		if (sum < t_coin_size) {
			t_coin_size = sum;
		}
	}

	cout << t_coin_size;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}