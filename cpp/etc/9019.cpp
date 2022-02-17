/*
9019번: DSLR
https://www.acmicpc.net/problem/9019

bfs로 푸는 문제래 뭔가 dp스럽기도 했는데
어떤식으로 접근해야할지 생각해내는 거 정말 어렵다..
bfs로 풀어도 시간초과 안나는구나...
6초니까 그러려니 하는거 같다. 오..

*/

#include<iostream>
#include<algorithm>
#include<queue>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

void bfs(int a, int b) {
	bool visited[10001] = { false };
	queue<pair<int,string>> q;
	q.push(make_pair(a, ""));
	visited[a] = true;

	pair<int, string> p;
	int temp;
	while (!q.empty())
	{
		p = q.front();
		q.pop();

		//시간초과
		//que에 원소를 넣을 때 visited 체크 하기
		//if (visited[p.first])
		//	continue;
		//visited[p.first] = true;
		
		if (p.first == b) {
			cout << p.second << "\n";
			return;
		}

		//D
		temp = ((p.first) * 2) % 10000;
		if (!visited[temp]) {
			visited[temp] = true;
			q.push(make_pair(temp, p.second + 'D'));
		}

		//S
		if (p.first <= 0) {
			temp = 9999;
		}
		else {
			temp = p.first - 1;
		}
		if (!visited[temp]) {
			visited[temp] = true;
			q.push(make_pair(temp, p.second + 'S'));
		}

		//L
		temp = ((p.first % 1000)*10) + (p.first / 1000);
		if (!visited[temp]) {
			visited[temp] = true;
			q.push(make_pair(temp, p.second + 'L'));
		}

		//R
		temp = (p.first / 10) + ((p.first % 10) * 1000);
		if (!visited[temp]) {
			visited[temp] = true;
			q.push(make_pair(temp, p.second + 'R'));
		}
	}
}

int main() {
	sync_off;
	
	int t;
	cin >> t;
	int a, b;
	while (t-- > 0) {
		cin >> a >> b;
		bfs(a, b);
	}

	return 0;
}