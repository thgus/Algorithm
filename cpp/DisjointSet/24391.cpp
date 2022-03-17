#include<iostream>
#include<vector>
#include<queue>

#define MAX 100000
using namespace std;

int n, m;
int parent[MAX + 1];

int find_parent(int a)
{
	if (parent[a] == a)	return a;
	return parent[a] = find_parent(parent[a]);
}

void make_union(int a, int b)
{
	int pa = find_parent(a);
	int pb = find_parent(b);

	if (pa == pb)	return;
	else if(pa<pb)	parent[pb] = pa;
	else parent[pa] = pb;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)	parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		make_union(a, b);
	}

	int next;
	
	int arr[MAX + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> next;
		arr[i] = find_parent(next);
	}

	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] != arr[i])	cnt++;
	}
	cout << cnt;
}