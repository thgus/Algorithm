#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define MAX 30*500

int n;
vector<int> weight;

vector<bool> result(MAX + 1, false);

void solve(vector<vector<bool>> &vec, int cur, int depth)
{
	if (vec[cur][depth])	return;
	vec[cur][depth] = true;
	result[cur] = true;

	if (depth == n)	return;

	solve(vec, cur, depth + 1);
	solve(vec, cur + weight[depth], depth + 1);
	solve(vec, abs(cur - weight[depth]), depth + 1);
}

void initialize()
{
	cin >> n;
	weight.resize(n);

	for (int i = 0; i < n; i++)	cin >> weight[i];

	int m;
	cin >> m;

	vector<vector<bool>> vec(MAX + 1, vector<bool>(n + 1, false));
	solve(vec, 0, 0);

	int weight;
	while (m--)
	{
		cin >> weight;

		if (weight > MAX || !result[weight])	cout << "N ";
		else cout << "Y ";
	}
}

int main()
{
	initialize();

	return 0;
}