/*
14590번: KUBC league (Small)
https://www.acmicpc.net/problem/14590
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

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
	vec.resize(n, vector<bool>(n));

	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			vec[i][j] = (temp) ? true : false;
		}
	}
}

struct Node {
	int player_num;
	int win_player;
	int seq_len;
	string seq;
};

void solve()
{
	queue<Node> que;
	vector<bool> isVisited(1 << n, false);

	int max_seq_len = 1;
	string max_seq = "1 ";

	que.push({ 0,(1 << 0),1,"1 " });
	while (!que.empty()) {
		Node cur = que.front();
		que.pop();

		if (isVisited[cur.win_player])   continue;
		isVisited[cur.win_player] = true;

		if (max_seq_len < cur.seq_len) {
			max_seq_len = cur.seq_len;
			max_seq = cur.seq;
		}

		for (int next_player_num = 0; next_player_num < n; next_player_num++) {
			if (cur.player_num == next_player_num) continue;

			if (~cur.win_player & (1 << next_player_num) && vec[cur.player_num][next_player_num]) {
				int next_win_player = cur.win_player | (1 << next_player_num);
				string next_seq = cur.seq + to_string(next_player_num+1) + " ";
				int next_seq_len = cur.seq_len + 1;
				que.push({ next_player_num,next_win_player,next_seq_len,next_seq });
			}
		}
	}

	cout << max_seq_len << "\n" << max_seq;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}