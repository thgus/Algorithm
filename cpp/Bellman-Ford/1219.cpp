#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

int n, m;
int s, e;
vector<vector<pair<int, int>>> route(101);
vector<int> city(101);

void initialize()
{
	cin >> n >> s >> e >> m;
	
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		route[a].push_back({ b,c });
	}
	for (int i = 0; i < n; i++)	cin >> city[i];
}

vector<long long> visited(101, LLONG_MIN);
bool check_go(int begin)
{
	vector<bool> visited(n, false);
	queue<int> que;

	que.push(begin);
	visited[begin] = true;

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		if (cur == e)	return true;

		for (pair<int,int> p : route[cur])
		{
			if (visited[p.first])	continue;
			visited[p.first] = true;
			que.push(p.first);
		}
	}

	return false;
}

void solve()
{
	visited[s] = city[s];
	for (int i = 0; i < n; i++) {
		for (int cur = 0; cur < n; cur++)
		{
			if (visited[cur] == LLONG_MIN)	continue;

			for (pair<int, int> p : route[cur])
			{
				long long ncost = visited[cur] - (long long)(p.second - city[p.first]);
				if (visited[p.first] >= ncost)	continue;

				visited[p.first] = ncost;
			}
		}
	}

	if (visited[e] == LLONG_MIN)
	{
		cout << "gg";
		return;
	}

	bool isChanged = false;
	for (int cur = 0; cur < n; cur++)
	{
		if (visited[cur] == LLONG_MIN)	continue;

		for (pair<int, int> p : route[cur])
		{
			long long ncost = visited[cur] - (long long)(p.second - city[p.first]);
			if (visited[p.first] >= ncost)	continue;

			if (check_go(cur))	isChanged = true;
		}
	}

	if (isChanged)	cout << "Gee";
	else cout << visited[e];
		
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initialize();
	solve();

	return 0;
}