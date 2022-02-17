/*
1697��: ���ٲ���
https://www.acmicpc.net/problem/1697
1. ��ĭ ����
2. ��ĭ ����
3. 2�� �����ŭ �̵�
*/

#include<iostream>
#include<queue>

using namespace std;

int bfs(int s_p, int b_p) {
	// �ð��� �ٿ��ֱ� ���ؼ� �湮�� ���� üũ
	bool visit[100001] = { false };
	queue<pair<int,int>> que;
	// first:��ġ second: time
	que.push(make_pair(s_p,0));
	int move = -1;
	pair<int,int> p;

	while (1) {
		p = que.front();
		que.pop();

		if (p.first == b_p) {
			// time�� que�� �տ� ���� ���� ª���Ƿ� 
			//���� ó���� ã���� ���� ����.
			return p.second;
		}

		if (visit[p.first])
			continue;
		visit[p.first] = true;

		if (p.first + 1 <= 100000) {	// ������ �� ĭ �̵�
			que.push(make_pair(p.first + 1, p.second + 1));
		}
		if (p.first - 1 >= 0) {	// �ڷ� �� ĭ �̵�
			que.push(make_pair(p.first - 1, p.second + 1));
		}
		if ((p.first * 2) <= 100000) {	//2�� �̵�
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