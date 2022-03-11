#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>

#define ll long long

using namespace std;

int n, m, k;
vector<vector<int>> topology;
vector<ll> time;
vector<int> degree;

int start, last;
vector<int> vec;
ll result = LLONG_MAX;

ll go()
{
	vector<long long> spend_time(n + 1, -1);
	vector<int> s_degree = degree;

	queue<int> que;
	que.push(start);
	spend_time[start] = 0;

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		ll next_spend_time = spend_time[cur] + time[cur];
		for (int i = 0; i < k; i++)
		{
			if (vec[i] == cur)
			{
				next_spend_time -= time[cur];
				break;
			}
		}

		for (int next : topology[cur])
		{
			spend_time[next] = max(spend_time[next], next_spend_time);
			if (--s_degree[next] == 0)
			{
				que.push(next);
			}
		}
	}

	return spend_time[last] + time[last];
}

void dfs(int depth, int s)
{
	if (depth == k)
	{
		ll t = go();
		result = min(result, t);
		return;
	}

	for (int i = s; i <= n; i++)
	{
		if (i == start || i == last)	continue;
		
		vec.push_back(i);
		dfs(depth + 1, i + 1);
		vec.pop_back();
	}
}

void get_se()
{
	for (int i = 1; i <= degree.size(); i++)
	{
		if (degree[i] == 0) 
		{
			start = i;
			break;
		}
	}

	vector<int> s_degree = degree;

	queue<int> que;
	que.push(start);
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		last = cur;
		
		for (int next : topology[cur])
		{
			if (--s_degree[next] == 0)
			{
				que.push(next);
			}
		}
	}

}

void solve()
{
	get_se();
	dfs(0, 1);

	cout << result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	topology.resize(n + 1);
	time.resize(n + 1);
	degree.resize(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> time[i];
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		topology[a].push_back(b);
		degree[b]++;
	}

	solve();

	return 0;
}