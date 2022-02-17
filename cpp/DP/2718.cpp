/*
2718번: 타일 채우기
https://www.acmicpc.net/problem/2718
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 2147483647
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Node {
	int index;
	int bit;
};

//메모리 초과
int bfs(int n)
{
	int case_num = 0;
	queue<Node> que;
	que.push({ 1,0});

	// bit -> 0:0 / 1:1,2 / 2:2,3 / 3:3,4 / 4:1,4
	while (!que.empty()) {
		int cur_index = que.front().index;
		int cur_bit = que.front().bit;
		que.pop();

		if (cur_index-1 == n) {
			if (cur_bit == 0) {
				case_num++;
				continue;
			}
		}
		else if (cur_index > n) {
			continue;
		}

		switch (cur_bit) {
		case 0:
			que.push({ cur_index + 1,4});
			que.push({ cur_index + 1,3});
			que.push({ cur_index + 2,0});
			que.push({ cur_index + 1,1});
			que.push({ cur_index + 1,0});
			break;
		case 1:
			que.push({ cur_index + 1,0});
			que.push({ cur_index + 1,3});
			break;
		case 2:
			que.push({ cur_index + 1,4});
			break;
		case 3:
			que.push({ cur_index + 1,0});
			que.push({ cur_index + 1,1});
			break;
		case 4:
			que.push({ cur_index + 1,0});
			que.push({ cur_index + 1,2});
			break;
		}
	}
	return case_num;
}

vector<vector<int>> dp(501, vector<int>(5,-1));
int dfs(int cur_index, int cur_bit) {
	if (cur_index == 0) {
		if (cur_bit == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (cur_index < 0) {
		return 0;
	}

	int& cur_num = dp[cur_index][cur_bit];
	if (cur_num != -1)	return cur_num;

	cur_num = 0;

	switch (cur_bit) {
	case 0:
		cur_num += dfs(cur_index - 1, 4);
		cur_num += dfs(cur_index - 1, 3);
		cur_num += dfs(cur_index - 2, 0);
		cur_num += dfs(cur_index - 1, 1);
		cur_num += dfs(cur_index - 1, 0);
		break;
	case 1:
		cur_num += dfs(cur_index - 1, 0);
		cur_num += dfs(cur_index - 1, 3);
		break;
	case 2:
		cur_num += dfs(cur_index - 1, 4);
		break;
	case 3:
		cur_num += dfs(cur_index - 1, 0);
		cur_num += dfs(cur_index - 1, 1);
		break;
	case 4:
		cur_num += dfs(cur_index - 1, 0);
		cur_num += dfs(cur_index - 1, 2);
		break;
	}

	return cur_num;
}


void input()
{
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		//cout << bfs(n) << "\n";
		cout << dfs(n,0) << "\n";
	}
}

int main()
{
	sync_off;
	input();

	return 0;
}