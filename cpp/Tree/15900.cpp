/*
15900번: 나무 탈출
https://www.acmicpc.net/problem/15900
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> tree;

int dfs(vector<bool>& visited, int cur, int len) {
	if (cur != 1 && tree[cur].size() == 1) {
		return len;
	}

	visited[cur] = true;
	int node = 0;
	for (int next : tree[cur]) {
		if (visited[next])   continue;
		node += dfs(visited, next, len+1);
	}

	return node;
}

int main()
{
	sync_off;

	cin >> n;
	tree.resize(n + 1);
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	vector<bool> visited(n + 1, false);
	if (dfs(visited, 1, 0) % 2 == 1) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}