/*
1260번: DFS와 BFS
https://www.acmicpc.net/problem/1260

*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> que;
stack<int> s;

bool visit_dfs[1001] = { false };
bool visit_bfs[1001] = { false };

void dfs(bool vec[][1001], int n, int v) {
	/*
	if (visit_dfs[v])
		return;
	visit_dfs[v] = true;
	cout << v << " ";

	for (int i = 1; i <= n; i++) {
		if (vec[i][v]) {
			dfs(vec, n, i);
		}
	}
	*/
	s.push(v);
	while (!s.empty()) {
		int p = s.top();
		s.pop();
		if (visit_dfs[p])
			continue;
		cout << p << " ";
		visit_dfs[p] = true;
		for (int i = n; i >= 1; i--) {
			if (vec[i][p]) {
				s.push(i);
			}
		}
	}
	
}

void bfs(bool vec[][1001], int n, int v) {
	que.push(v);
	visit_bfs[v] = true;

	while (!que.empty())
	{
		int p = que.front();
		cout << p << " ";
		que.pop();
		for (int i = 1; i <= n; i++) {
			if (visit_bfs[i])
				continue;
			if (vec[i][p]) {
				visit_bfs[i] = true;
				que.push(i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V
	int n, m, v;
	cin >> n;
	cin >> m;
	cin >> v;

	bool vec[1001][1001] = { false };
	int x, y;
	int vx, vy;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		cin >> y;		
		vec[x][y] = true;
		vec[y][x] = true;
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << vec[j][i] << " ";
		}
		cout << "\n";
	}
	*/

	dfs(vec, n, v);
	cout << "\n";
	
	bfs(vec, n, v);

	return 0;
}