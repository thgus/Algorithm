/*
18808번: 스티커 붙이기
https://www.acmicpc.net/problem/18808
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m, k;
vector<vector<vector<bool>>> stk;
int sum = 0;

void initialize()
{
	cin >> n >> m >> k;

	int r, c;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		vector<vector<bool>> cur(r, vector<bool>(c));
		int temp;
		for (int j = 0; j < r; j++) {
			for (int l = 0; l < c; l++) {
				cin >> temp;
				cur[j][l] = (temp) ? true : false;
			}
		}

		stk.push_back(cur);
	}
}

bool check(vector<vector<bool>>& notbook, vector<vector<bool>>& stk, int sy, int sx) {
	for (int i = 0; i < stk.size(); i++) {
		for (int j = 0; j < stk[i].size(); j++) {
			if (notbook[sy + i][sx + j] && stk[i][j])
				return false;
		}
	}
	return true;
}

void stick_notbook(vector<vector<bool>> & notbook, vector<vector<bool>> & stk, int sy, int sx) {
	for (int i = 0; i < stk.size(); i++) {
		for (int j = 0; j < stk[i].size(); j++) {
			if (stk[i][j]) {
				notbook[sy + i][sx + j] = stk[i][j];
				sum++;
			}
		}
	}
}

void turn90(vector<vector<bool>> & stk) {
	vector<vector<bool>> temp(stk[0].size(), vector<bool>(stk.size(), false));
	int r = stk.size();
	int c = stk[0].size();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[j][r - i - 1] = stk[i][j];
		}
	}
	stk = temp;
}

void print_vec(vector<vector<bool>> & vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j];
		}
		cout << "\n";
	}
}

void solve()
{
	vector<vector<bool>> notbook(n, vector<bool>(m, false));
	for (vector<vector<bool>> cstk : stk) {
		for (int l = 0; l < 4; l++) {
			int r = (int)cstk.size();
			int c = (int)cstk[0].size();

			for (int i = 0; i <= n - r; i++) {
				for (int j = 0; j <= m - c; j++) {
					if (check(notbook, cstk, i, j)) {
						stick_notbook(notbook, cstk, i, j);
						goto CREAL;
					}
				}
			}
			turn90(cstk);
		}
	CREAL:;
	}
	cout << sum;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}