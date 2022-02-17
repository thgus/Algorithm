/*
14554번: The Other Way
https://www.acmicpc.net/problem/14554
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m, s, e;
vector<vector<pair<int, long long>>> vec;

void initialize()
{
	cin >> n >> m >> s >> e;
	vec.resize(n);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		vec[a-1].push_back({ b-1,c });
		vec[b-1].push_back({ a-1,c });
	}
}

struct Node {
	int num;
	long long len;

	bool operator<(const Node node) const {
		return node.len < len;
	}
};

void solve()
{
	long long mod = 1000000009;

	vector<long long> visited(n, LLONG_MAX);
	vector<long long> dp(n, 0);
	priority_queue<Node> pq;
	pq.push({ s - 1,0 });
	visited[s - 1] = 0;
	dp[s - 1] = 1;

	while (!pq.empty()) {
		int cur = pq.top().num;
		long long cost = pq.top().len;
		pq.pop();

		if (cur == e - 1) {
			break;
		}


		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			long long ncost = vec[cur][i].second + cost;

			if (visited[next] > ncost) {
				visited[next] = ncost;
				dp[next] = 0;
				dp[next] += dp[cur];
				dp[next] %= mod;

				pq.push({ next,ncost });
			}
			else if (visited[next] == ncost) {
				dp[next] += dp[cur];
				dp[next] %= mod;
			}
		}
	}

	
	cout << dp[e - 1];
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}