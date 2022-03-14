#include<iostream>
#include<queue>
#include<vector>
#include<climits>

typedef long long ll;

using namespace std;

struct Node
{
	int num;
	ll cost;
	int go_time;
};

int n, m;
vector<vector<Node>> vec;

void dijkstra()
{
	priority_queue<pair<ll, int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({ 0,1 });

	vector<ll> visited(n + 1, LLONG_MAX);
	visited[1] = 0;

	while (!pq.empty())
	{
		ll cost = pq.top().first;
		int num = pq.top().second;
		pq.pop();
		
		if (visited[num] > cost)	continue;
		if (num == n)
		{
			cout << cost;
			break;
		}

		for (Node p : vec[num])
		{
			ll ncost = (((cost - 1) / p.go_time) + 1)*p.go_time;
			ncost += p.cost;

			if (cost == 0)	ncost = p.cost;

			if (visited[p.num] <= ncost)	continue;
			visited[p.num] = ncost;
			pq.push({ ncost,p.num });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vec.resize(n + 1);
	int a, b, t, w;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> t >> w;
		vec[a].push_back({ b,t,w });
	}
	dijkstra();

	return 0;
}