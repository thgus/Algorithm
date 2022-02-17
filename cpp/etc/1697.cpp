/*
1697번: 숨바꼭질
https://www.acmicpc.net/problem/1697
1. 한칸 전진
2. 한칸 후진
3. 2의 배수만큼 이동
*/

#include<iostream>
#include<queue>

using namespace std;

int bfs(int s_p, int b_p) {
	// 시간을 줄여주기 위해서 방문한 곳은 체크
	bool visit[100001] = { false };
	queue<pair<int,int>> que;
	// first:위치 second: time
	que.push(make_pair(s_p,0));
	int move = -1;
	pair<int,int> p;

	while (1) {
		p = que.front();
		que.pop();

		if (p.first == b_p) {
			// time은 que의 앞에 있을 수록 짧으므로 
			//가장 처음에 찾은게 가장 빠름.
			return p.second;
		}

		if (visit[p.first])
			continue;
		visit[p.first] = true;

		if (p.first + 1 <= 100000) {	// 앞으로 한 칸 이동
			que.push(make_pair(p.first + 1, p.second + 1));
		}
		if (p.first - 1 >= 0) {	// 뒤로 한 칸 이동
			que.push(make_pair(p.first - 1, p.second + 1));
		}
		if ((p.first * 2) <= 100000) {	//2배 이동
			que.push(make_pair(p.first * 2, p.second + 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s_p, b_p;
	cin >> s_p;
	cin >> b_p;

	cout << bfs(s_p, b_p);

	return 0;
}