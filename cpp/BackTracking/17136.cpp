/*
17136번: 색종이 붙이기
https://www.acmicpc.net/problem/17136
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<vector<bool>> map(MAX, vector<bool>(MAX));

void initialize()
{
	int temp;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> temp;
			map[i][j] = (temp) ? true : false;
		}
	}
}

void print_vec() {
	cout << "\n";
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
}

bool isBoundary(int y, int x) {
	if (y >= 0 && y < MAX && x >= 0 && x < MAX)    return true;
	return false;
}

bool isCover(int start_y, int start_x, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (!isBoundary(start_y + i, start_x + j) || !map[start_y + i][start_x + j]) {
				return false;
			}
		}
	}

	return true;
}

void cover_map(int start_y, int start_x, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			map[start_y + i][start_x + j] = false;
		}
	}
}

bool check_all_clear() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (map[i][j])	return false;
		}
	}
	return true;
}

int result = 1e9;
void dfs(vector<int> & l, int start_y, int start_x, int num) {
	if (num > result)	return;

	for (int i = start_y; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (!map[i][j]) {
				continue;
			}

			vector<vector<bool>> temp = map;
			bool cover = false;
			for (int k = 4; k >= 0; k--) {
				if (!isCover(i, j, k + 1) || l[k] <= 0)   continue;
				l[k]--;
				cover_map(i, j, k + 1);
								
				dfs(l, i, j, num + 1);

				l[k]++;
				map = temp;

			}

			if (map[i][j])	return;

		}
	}

	result = min(result, num);
}

void solve()
{
	vector<int> l(5, 5);
	dfs(l, 0, 0, 0);

	if (result == 1e9) {
		cout << "-1";
	}
	else {
		cout << result;
	}
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}