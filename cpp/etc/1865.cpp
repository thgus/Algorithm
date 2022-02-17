/*
1865번: 웜홀
https ://www.acmicpc.net/problem/1865

벨만 포드 알고리즘
= > 플로이드 와샬은 O(N ^ 3)이므로 시간초과
= > 다익스트라와 다르게 음수로도 할 수 있음.

반복시 시작점이 같아도 괜찮음 = > 왜 나 que 썼지;;
메모리 초과 났다;;
탐색을 que로 풀었는데 que로 할 이유가 없었네;; 어차피 간선 다 가봐야하니까;;

https://www.acmicpc.net/board/view/50494
따라서 만약 단순 그래프에서의 사이클 유무만 파악할 때는 dist[]초기화를 어떤 값으로 해주어도 상관이 없어요.
왜냐면 거리를 구하는 게 아니라 마지막에서 음의 사이클이 존재할 때, 변화만 파악하는 것이니깐요.

https://steady-coding.tistory.com/91

2번 정점까지 가는 최단거리는 0->1->2를 거쳐서 12+(-7)=5여야 합니다.
그러나 다익스트라 알고리즘은 1, 2번 정점 중에서 dist[1]=12 > dist[2]=8이라 해서 2번 정점을 방문
따라서 벨만 포드 알고리즘은 2중 for문을 통해 철저하게 가능한 모든 경우를 다 체크하기로 합니다.
https://m.blog.naver.com/kks227/220796963742

여기가 이해하기 쉬운 블로그 사이트
https://victorydntmd.tistory.com/104
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX 987654321
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main() {
	sync_off;

	int tc;
	cin >> tc;
	while (tc > 0) {
		tc--;

		//간선 비용
		vector<vector<int>> road(501, vector<int>(501, MAX));

		int n, m, w;
		cin >> n >> m >> w;
		int s, e, t;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			if (road[s][e] > t) {
				road[s][e] = t;
				road[e][s] = t;
			}
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			road[s][e] = -t;
		}

		vector<int> d(501, MAX);	// 정점 값
		bool cycle = false;

		//시작점, value
		int st, v;
		d[1] = 0;

		//V(정점)*E(간선)번 반복후 종료
		//한 정점에서 모든 정점을 방문할 수 있으려면 적어도 V-1번 방문해야 함
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					//자신에게 돌아오는 간선도 있나?
					//if (road[j][k] == MAX || j == k) {
					//	continue;
					//}

					//간선의 길이 만큼 돌렸는데도 더 갱신할 수 있는 값이 있다.
					//	=> 음수사이클. 돌릴수록 값이 낮아짐
					//이를 확인하기 위해 음의 사이클이 없다면 V-1번만 방문해도 모든 정점의 최단 거리를 알 수 있지만
					// V번째 방문을 해서 값이 낮아진다면 음의 사이클이 있다고 판단.
					if (d[k] > d[j] + road[j][k]) {
						if (i == n) {
							cycle = true;
							break;
						}
						d[k] = d[j] + road[j][k];
					}
				
				}
			}
		}
		if (cycle) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}

	return 0;
}