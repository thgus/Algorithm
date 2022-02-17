/*
11781번: 퇴근 시간
https://www.acmicpc.net/problem/11781
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m, s, e;
struct Road {
	int dist;
	long long len;
	int traffic_jam;
};
vector<vector<Road>> road;

void initialize()
{
	cin >> n >> m >> s >> e;

	road.resize(n);
	int a, b, c, t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> t1 >> t2;
		road[a - 1].push_back({ b - 1,c * 2,t1 });
		road[b - 1].push_back({ a - 1,c * 2,t2 });
	}

	s *= 2;
	e *= 2;
}

struct Node {
	int dist;
	long long time;
};

void solve()
{
	vector<long long> visited(n, LLONG_MAX);
	queue<Node> que;
	visited[0] = 0;
	que.push({ 0,0 });

	while (!que.empty()) {
		int cur = que.front().dist;
		long long time = que.front().time;
		que.pop();

		if (visited[cur] < time)  continue;

		for (int i = 0; i < road[cur].size(); i++) {
			int next = road[cur][i].dist;
			long long ntime = time + road[cur][i].len;

			if (road[cur][i].traffic_jam) {
				if (time <= s && s < ntime) {
					long long cur_len = s - time;
					long long rest_len = road[cur][i].len - cur_len;

					if ((e - s) / 2 <= rest_len) {
						rest_len -= (e - s) / 2;
						ntime = time + cur_len + (e - s) + rest_len;
					}
					else {
						ntime = time + cur_len + rest_len * 2;
					}

				}
				else if (s <= time && time < e) {
					long long end_len = (e - time) / 2;
					long long rest_len = road[cur][i].len - end_len;

					if (end_len <= road[cur][i].len) {
						ntime = time + (e - time) + rest_len;
					}
					else {
						ntime = time + road[cur][i].len * 2;
					}
				}
			}

			if (visited[next] <= ntime)  continue;
			visited[next] = ntime;
			que.push({ next,ntime });
		}
	}

	long long result = -1;
	for (int i = 0; i < n; i++) {
		result = max(result, visited[i]);
	}

	cout << result / 2;
	if (result % 2 != 0) {
		cout << ".5";
	}

}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}