/*
1753��: �ִܰ��
https://www.acmicpc.net/problem/1753

���ͽ�Ʈ��(Dijkstra) �˰���
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
	//�����ּҴ� ���� �Ÿ��� 0
	dist[k] = 0;

	//first=cost, second=node
	//����� �������� �켱���� ���� �ϹǷ� que���� ���ļ����� ������ first�� cost�� ����
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> que;
	vector<bool> isVisited(20001, false);
	que.push(make_pair(0, k));

	while (!que.empty()) {
		int node = que.top().second;
		int cost = que.top().first;
		que.pop();

		for (auto i = vec[node].begin(); i != vec[node].end(); i++) {
			//vector�� ���� ���� ���� ���ϸ鼭 Ǯ�� �ð��ʰ� -> queue�� �ð� ����

			//dist�� �ʱⰪ�� MAX������ �Ǿ������Ƿ� �������� ����Ǿ� �ִٸ� �ѹ� ���� ���� ������ ���� ��.
			//�׻� ���� ����� �ּҰ��� �������� Ȯ���ϰ� �ֱ� ������ �ش� ��忡 ���� ������ ����� ���� ���� ���.
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