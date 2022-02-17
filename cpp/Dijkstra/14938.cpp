/*
14938번: 서강그라운드
https://www.acmicpc.net/problem/14938
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

/*
	n: 지역의 개수
	m: 수색범위
	r: 길의 개수
*/
int n, m, r;

//지역(index)에 따른 아이템 개수
vector<int> items(MAX + 1);
vector<vector<pair<int, int>>> route(MAX + 1, vector<pair<int, int>>(0));

void initialize()
{
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> items[i];
	}
	int a, b, l;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		route[a].push_back({ b,l });
		route[b].push_back({ a,l });
	}
}

void solve()
{
	int maxItemSum = 0;

	//반복문으로 모든 지점에서 시작하여 아이템을 얼마나 얻을 수 있는지 확인
	for (int i = 1; i <= n; i++) {
		//first: 거리, second: 지점
		priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> que;
		que.push({ 0,i });

		vector<bool> isVisited(MAX + 1, false);
		int itemSum = 0;        

		while (!que.empty()) {
			//거리
			int dist = que.top().first;
			//지점
			int s = que.top().second;
			que.pop();

			//만약 한번 방문한 지점이면 재방문 X
			if (isVisited[s]) {
				continue;
			}
			isVisited[s] = true;

			//현재 지점의 거리가 수색범위 내라면 아이템 수 저장
            if(dist<=m){
                itemSum+=items[s];
            }

			//현재 지점과 연결되어 있는 지점 탐색
			for (int j = 0;j<route[s].size(); j++) {
				//방문한 적 있는 지점이면 스킵
				if (isVisited[route[s][j].first]) {
					continue;
				}
				//방문할 지점을 que에 넣기
				que.push({ dist + route[s][j].second,route[s][j].first });
			}
		}

		//현재 지점에서 모은 아이템 수가 이전 지점에서 모은 아이템 수 보다 많으면 저장
		if (itemSum > maxItemSum) {
			maxItemSum = itemSum;
		}
	}

	//출력
	cout << maxItemSum;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}