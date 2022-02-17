/*
11725��: Ʈ���� �θ� ã��
https://www.acmicpc.net/problem/11725

bfs�� �迭�� �θ� ���� �� �����ϱ�
�ð��ʰ�;; �� ���ϰ� �ϴ°� �����ΰ�
��������Ʈ�� ����
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
vector<vector<int>> vec(100001,vector<int>(0));
int n;

vector<int> bfs() {
	vector<bool> visit(100001, false);
	vector<int> parent(100001, -1);
	parent[1] = 0;
	
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int p = que.front();
		que.pop();

		int child;
		for (int i = 0; i < vec[p].size(); i++) {
			child = vec[p][i];
			if (visit[child]) {
				continue;
			}
			parent[child] = p;
			que.push(child);
			visit[child] = true;
		}
	}
	return parent;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	
	vector<int> result = bfs();
	for (int i = 2; i <= n; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}