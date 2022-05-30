/*
25187번: 고인물이 싫어요
https://www.acmicpc.net/problem/25187
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m, q;
vector<int> water_tank;
vector<int> parent;

int find_parent(int i)
{
	if (parent[i] == i)    return i;

	return parent[i] = find_parent(parent[i]);
}

void union_parent(int a, int b)
{
	int ap = find_parent(a);
	int bp = find_parent(b);

	if (ap == bp)  return;

	parent[bp] = ap;
}

void initialize()
{
	cin >> n >> m >> q;

	water_tank.resize(n);
	parent.resize(n);

	for (int i = 0; i < n; i++)    parent[i] = i;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		water_tank[i] = (num) ? 1 : -1;
		// cin >> water_tank[i];
	}

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--; b--;

		int ap = find_parent(a);
		int bp = find_parent(b);
		if (ap == bp)	continue;

		water_tank[ap] += water_tank[bp];
		parent[bp] = ap;
	}
}

void solve()
{
	int num;
	while (q--)
	{
		cin >> num;
		num--;

		int p = find_parent(num);

		int result = (water_tank[p] > 0) ? 1 : 0;

		cout << result << "\n";
	}

}

int main()
{
	sync_off;

	initialize();
	solve();

	return 0;
}