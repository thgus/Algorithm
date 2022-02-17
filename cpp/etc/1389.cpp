/*
1389번: 케빈 베이컨의 6단계 법칙
https://www.acmicpc.net/problem/1389

유저의 수 N (2 ≤ N ≤ 100)과 친구 관계의 수 M (1 ≤ M ≤ 5,000)
친구 관계는 A와 B로 이루어져 있으며, A와 B가 친구라는 뜻
BOJ의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람
*/

#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int bfs(int me, int n, bool user[][101]) {
	int kb = 0;
	bool visit[101] = { false };

	queue<pair<int,int>> que;
	//first=index, second=stage
	que.push(make_pair(me,0));
	while (!que.empty()) {
		pair<int,int> p = que.front();
		que.pop();
		if (visit[p.first]) {
			continue;
		}
		visit[p.first] = true;
		kb += p.second;

		for (int i = 1; i <= n; i++) {
			if (user[p.first][i]) {
				que.push(make_pair(i, p.second + 1));
			}
		}
	}
	return kb;
}

int findMinKB(int n, bool user[][101]){
	//first = Kevin Bacon , second = id
	pair<int, int> minPerson = make_pair(101, 101);
	int kb;
	
	for (int i = 1; i <= n; i++) {
		kb = bfs(i, n, user);
		minPerson = (minPerson < make_pair(kb, i)) ? minPerson : make_pair(kb, i);	
	}	
	return minPerson.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;
	bool user[101][101] = { false };
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		cin >> b;
		user[a][b] = true;
		user[b][a] = true;
	}

	cout << findMinKB(n, user);
	return 0;
}