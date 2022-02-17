/*
20304번: 비밀번호 제작
https://www.acmicpc.net/problem/20304
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
	sync_off;

	int n, m;
	cin >> n >> m;

	int max_bit = log2(n) + 1;

	queue<pair<int, int>> que;
	vector<bool> visited(n + 1, false);
	int temp;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		que.push({ 0,temp });
		visited[temp] = true;
	}

	int result = -1;
	while (!que.empty()) {
		int cur_bit = que.front().second;
		int cur_len = que.front().first;
		que.pop();

		result = max(result, cur_len);

		for (int bit = 0; bit < max_bit; bit++) {
			int next_num = cur_bit;
			if (cur_bit & (1 << bit)) {
				next_num -= (1 << bit);
			}
			else {
				next_num += (1 << bit);
			}

			if (next_num > n)  continue;
			if (visited[next_num])   continue;
			visited[next_num] = true;
			que.push({ cur_len + 1, next_num });
		}
	}
	cout << result;

	return 0;
}