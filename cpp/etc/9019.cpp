/*
9019��: DSLR
https://www.acmicpc.net/problem/9019

bfs�� Ǫ�� ������ ���� dp�����⵵ �ߴµ�
������� �����ؾ����� �����س��� �� ���� ��ƴ�..
bfs�� Ǯ� �ð��ʰ� �ȳ��±���...
6�ʴϱ� �׷����� �ϴ°� ����. ��..

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

		//�ð��ʰ�
		//que�� ���Ҹ� ���� �� visited üũ �ϱ�
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