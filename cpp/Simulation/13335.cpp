/*
13335번: 트릭
https://www.acmicpc.net/problem/13335
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, w, l;
vector<int> train;

void initialize()
{
	cin >> n >> w >> l;
	train.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> train[i];
	}
}

struct Node {
	int num;
	int p;
};

void solve()
{
	int time = 1;
	int cur_w = 0;
	int cur = 0;

	deque<Node> que;
	que.push_back({ cur++,0 });
	cur_w += train[0];

	while (!que.empty()) {
		time++;

		for (int i = 0; i < que.size(); i++) {
			que[i].p++;
		}

		if (que.front().p == w) {
			cur_w -= train[que.front().num];
			que.pop_front();
		}
		if (cur != n && cur_w + train[cur] <= l) {
			cur_w += train[cur];
			que.push_back({ cur++,0 });
		}
	}

	cout << time;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}