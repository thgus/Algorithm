/*
1753번: 최단경로
https://www.acmicpc.net/problem/1753

다익스트라(Dijkstra) 알고리즘
https://mattlee.tistory.com/50
http://melonicedlatte.com/algorithm/2018/03/04/061153.html
https://chanhuiseok.github.io/posts/algo-47/
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 987654321

using namespace std;

int main() {
	sync_off;
	int a, e;
	cin >> a >> e;
	int k;
	cin >> k;

	vector <vector<pair<int,int>>> vec(20001, vector<pair<int,int>>(0));

	int u, v, w;
	for (int i = 0; i < e; i++) {
		cin >> u >> v >> w;
		vec[u].push_back(make_pair(v, w));
	}

	vector<int> dist(20001, MAX);
	//시작주소는 도착 거리가 0
	dist[k] = 0;

	//first=cost, second=node
	//비용이 작은것을 우선으로 가야 하므로 que에서 정렬순서를 생각해 first를 cost로 지정
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> que;
	vector<bool> isVisited(20001, false);
	que.push(make_pair(0, k));

	while (!que.empty()) {
		int node = que.top().second;
		int cost = que.top().first;
		que.pop();

		for (auto i = vec[node].begin(); i != vec[node].end(); i++) {
			//vector로 제일 작은 값을 비교하면서 풀면 시간초과 -> queue로 시간 절약

			//dist에 초기값이 MAX값으로 되어있으므로 시작점과 연결되어 있다면 한번 값이 들어가서 간선을 살펴 봄.
			//항상 간선 비용의 최소값을 기준으로 확장하고 있기 때문에 해당 노드에 먼저 도착한 비용이 가장 적은 비용.
			if (dist[i->first] > cost + i->second) {
				dist[i->first] = cost + i->second;
				que.push(make_pair(dist[i->first], i->first));
			}
			
		}

	}
	
	for (int i = 1; i <= a; i++) {
		if (dist[i] == MAX) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
	
	return 0;
}