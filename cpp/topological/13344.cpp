#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int>> topology;
vector<int> parent;
vector<int> degree;

int find_parent(int num)
{
	if (parent[num] == num)
	{
		return num;
	}
	return parent[num] = find_parent(parent[num]);
}

void merge(int a, int b)
{
	int pa = find_parent(a);
	int pb = find_parent(b);
	if (pa == pb)	return;
	parent[pb] = pa;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	topology.resize(n);
	parent.resize(n);
	degree.resize(n, 0);

	for (int i = 0; i < n; i++)	parent[i] = i;

	int a, b;
	char c;
	int temp;
	vector<pair<int, int>> vec;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> c >> b;
		switch (c)
		{
		case '>':
			temp = a;
			a = b;
			b = temp;
		case '<':
			vec.push_back({ a,b });
			break;
		case '=':
			merge(a, b);
			break;
		}
	}

	for (pair<int, int> p : vec)
	{
		int a = find_parent(p.first);
		int b = find_parent(p.second);

		topology[a].push_back(b);
		degree[b]++;
	}

	queue<int> que;
	int edge_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int pa = find_parent(i);
		if (pa != i)	continue;
		edge_cnt++;
		if (degree[pa] == 0)	que.push(pa);
	}

	int cnt = 0;
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		cnt++;

		for (int next : topology[cur])
		{	
			if (--degree[next] == 0)
			{
				que.push(next);
			}
		}
	}

	//cout << cnt << " " << edge_cnt << "\n";
	if (cnt == edge_cnt)
	{
		cout << "consistent";
	}
	else
	{
		cout << "inconsistent";
	}

	return 0;
}