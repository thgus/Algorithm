/*
1167번: 트리의 지름
https://www.acmicpc.net/problem/1167
*/

#include<iostream>
#include<algorithm>
#include<vector>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int v;
//앍 정점의 개수 2≤V≤100,000인데 거리의 최대랑 헷갈려서 런타임 에러 남;;
vector<vector<pair<int,int>>> tree(100001, vector<pair<int,int>>(0));

void initializer() {
	cin >> v;
	int from, to, d;
	for (int i = 1; i <= v; i++) {
		cin >> from;
		while (1) {
			cin >> to;
			if (to == -1) {
				break;
			}
			cin >> d;
			tree[from].push_back({ to,d });
		}
	}
}

//시작점은 상관 없는거 같지?
vector<bool> visited(100001, false);
int mr = -1;

int dfs(int from) {
	vector<int> md;

	int to;
	if (tree[from].empty()) {
		return 0;
	}

	for (int i = 0; i < tree[from].size(); i++) {
		to = tree[from][i].first;

		if (visited[to]) {
			continue;
		}
		visited[to] = true;
		int d = dfs(to) + tree[from][i].second;
		md.push_back(d);
		
	}

	if (md.empty()) {
		return 0;
	}
	else if (md.size() == 1) {
		if (md[0] > mr) {
			mr = md[0];
		}
		return md[0];
	}

	sort(md.begin(), md.end(), greater<int>());
	if (mr < md[0] + md[1]) {
		mr = md[0] + md[1];
	}
	return md[0];

}

void solution() {
	int start = 1;
	visited[start] = true;
	dfs(start);
	cout << mr;
}

int main() {
	sync_off;
	initializer();
	solution();

	return 0;
}