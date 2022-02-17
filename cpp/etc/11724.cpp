/*
11724번: 연결 요소의 개수
https://www.acmicpc.net/problem/11724

*/

#include<iostream>
#include<queue>

using namespace std;

void bfs(bool arr[][1001], bool visit[1001], int n, int v) {
	queue<int> que;
	que.push(v);
	visit[v] = true;

	while (!que.empty()) {
		int p = que.front();
		que.pop();

		for (int i = 1; i <= n; i++) {
			if (arr[i][p]) {
				if (!visit[i]) {
					que.push(i);
					visit[i] = true;
				}
			}
		}

	}

}

int findCC(bool arr[][1001], int n) {
	bool visit[1001] = { false };
	int nCC = 0;

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			nCC++;
			bfs(arr, visit, n, i);
		}
	}
	return nCC;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 정점의 개수 N과 간선의 개수 M
	int n,m;
	cin >> n;
	cin >> m;

	bool arr[1001][1001] = { false };
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u;
		cin >> v;
		arr[u][v] = true;
		arr[v][u] = true;
	}

	cout << findCC(arr, n);

	return 0;
}