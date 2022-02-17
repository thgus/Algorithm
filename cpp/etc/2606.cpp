/*
2606번: 바이러스
https://www.acmicpc.net/problem/2606
*/
#include<iostream>
#include<queue>

using namespace std;

bool arr[101][101] = { false };
bool visit[101] = { false };
queue<int> que;

int dfs(int c) {
	int vn = -1;
	que.push(1);

	while (!que.empty()) {
		int p = que.front();
		que.pop();
		if (visit[p])
			continue;

		visit[p] = true;
		//cout << p << "\n";
		vn++;
		for (int i = 1; i <= c; i++) {
			
			if (arr[p][i]) {
				que.push(i);
			}
			else if (arr[i][p]) {
				que.push(i);
			}
		}

	}

	return vn;
}

int main() {
	int c, n;
	cin >> c;
	cin >> n;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cin >> y;
		arr[x][y] = true;
	}
	int result = dfs(c);
	cout << result;

	return 0;
}