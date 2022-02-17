/*
2325번: 개코전쟁
https://www.acmicpc.net/problem/2325

최단경로가 여러개있어도 한개의 최단경로만 파악해 놓아도 된다.
어떤 정점까지 가는 최단경로가 여러개 있다면 그 중 한개의 간선을 제거한다 해도 변하지 않거나 
한 개의 최단 경로만 파악해 놓고 삭제한 결과랑 같기 때문이다.

https://lyzqm.blogspot.com/2017/06/dijkstra-5719.html
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> vec;

void initialize()
{
	int m;
	cin >> n >> m;
	vec.resize(n + 1, vector<int>(n + 1, -1));

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		vec[a][b] = vec[b][a] = c;
	}
}

void clear_queue(priority_queue<pair<int, int>>& pq) {
	priority_queue<pair<int, int>> empty;
	swap(pq, empty);
}

void clear_visit(vector<bool>& vec) {
	vector<bool> empty(n + 1, false);
	swap(vec, empty);
}
void solve()
{
	vector<int> visited(n + 1, 1e9);
	vector<int> route(n + 1);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	visited[1] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cur == n) {
			break;
		}

		if (visited[cur] < cost)   continue;

		for (int next = 1; next <= n; next++) {
			if (vec[cur][next] == -1)  continue;

			int ncost = cost + vec[cur][next];
			if (visited[next] > ncost) {
				visited[next] = ncost;
				route[next]=cur;
				pq.push({ -ncost,next });
			}
		}
	}

	vector<pair<int, int>> shortest_path;
	queue<pair<int, int>> que;
	que.push({ -1,n });
	while (!que.empty()) {
		int pre = que.front().first;
		int cur = que.front().second;
		que.pop();

		if (cur == 1)  continue;

		int next = route[cur];
		shortest_path.push_back({ cur,next });
		que.push({ cur,next });
	}

	vector<bool> visit;
	int result = -1;
	for (pair<int, int> p : shortest_path) {
		clear_visit(visit);
		clear_queue(pq);
		pq.push({ 0,1 });

		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (cur == n) {
				result = max(result, cost);
				break;
			}

			if (visit[cur])	continue;
			visit[cur] = true;

			for (int next = 1; next <= n; next++) {
				if (vec[cur][next] == -1)	continue;
				if (cur == p.first && next == p.second)	continue;
				if (cur == p.second && next == p.first)	continue;
				if (visit[next])	continue;
				pq.push({ -(cost + vec[cur][next]),next });
			}
		}
	}
	cout << result;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}