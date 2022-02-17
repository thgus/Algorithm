/*
23087번: 최단최단경로
https://www.acmicpc.net/problem/23087

참고
https://www.acmicpc.net/board/view/76070
*/

#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<climits>

using namespace std;

#define MAX 100000

struct Node
{
	int num;
	long long cost;

	bool operator<(const Node n)const {
		return cost > n.cost;
	}
};

struct Station
{
	int dist;
	long long cost;
};

int n, m;
int x, y;

vector<vector<Station>> route;
long long dist[MAX + 5];
long long transfer[MAX + 5];
long long dp[MAX + 5];

void initialize()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> x >> y;

	route.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		dist[i] = transfer[i] = dp[i] = LLONG_MAX;
	}

	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		route[u].push_back({ v,w });
	}
}

void dijkstra()
{
	priority_queue<Node> pq;

	dist[x] = 0;

	pq.push({ x,0 });
	while (!pq.empty())
	{
		Node cur = pq.top();
		pq.pop();

		if (cur.num == y)	break;

		// 얘 없어서 시간초과 난거였어ㅠ
		if (dist[cur.num] < cur.cost)	continue;

		for (Station station : route[cur.num])
		{
			if (dist[station.dist] > cur.cost+station.cost) {
				dist[station.dist] = cur.cost+station.cost;
				pq.push({ station.dist ,dist[station.dist] });
			}
		}
	}
}

void find_shortest_path()
{
	priority_queue<Node> pq;
	pq.push({ x,0 });

	dp[x] = 1;
	transfer[x] = 0;
	while (!pq.empty())
	{
		Node cur = pq.top();
		pq.pop();

		if (cur.num == y)	break;
		if (dist[cur.num] < cur.cost)	continue;

		for (Station s : route[cur.num])
		{
			if (dist[cur.num] + s.cost != dist[s.dist])	continue;

			if (transfer[s.dist] > cur.cost+1)
			{
				dp[s.dist] = dp[cur.num];

				transfer[s.dist] = cur.cost + 1;
				pq.push({ s.dist ,transfer[s.dist]});
			}
			else if (transfer[s.dist] == cur.cost + 1)
			{
				dp[s.dist] += dp[cur.num];
				dp[s.dist] %= 1000000009;
			}
		}
	}

}

int main()
{
	initialize();
	dijkstra();
	find_shortest_path();

	if (dist[y] == LLONG_MAX)	cout << "-1";
	else
	{
		cout << dist[y] << "\n" << transfer[y] << "\n" << dp[y] % 1000000009;
	}


	return 0;
}