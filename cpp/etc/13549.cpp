/*
13549��: ���ٲ��� 3
https://www.acmicpc.net/problem/13549

���ͽ�Ʈ��δ� ��� Ǯ��?
���� �� ����� ���ͽ�Ʈ�󿴳�? ���� �ڷᱸ���� �Ѳ����� ���ٺ��ϱ� �򰥸���
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX 100000
#define MIN 0

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int bfs(int _n, int _k) {
	//time, x
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	vector<bool> visited(100001, false);

	que.push({ 0, _n });
	visited[_n] = true;

	int x, time;
	while (!que.empty()) {
		x = que.top().second;
		time = que.top().first;
		que.pop();

		//cout << x << " " << time << "\n";

		if (x == _k) {
			cout << time;
			return time;
		}

		if (x * 2 <= MAX && !visited[x*2] ) {
			que.push({ time,x * 2 });
			visited[x * 2] = true;
		}
		if (x - 1 >= MIN && !visited[x-1] ) {
			que.push({ time + 1,x - 1 });
			visited[x - 1] = true;
		}
		if (x + 1 <= MAX && !visited[x+1] ) {
			que.push({ time + 1, x + 1 });
			visited[x + 1] = true;
		}
	}

}

int main() {
	sync_off;
	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);

	return 0;
}