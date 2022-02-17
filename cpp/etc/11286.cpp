/*
11286��: ���밪 ��
https://www.acmicpc.net/problem/11286

priority_queue ¯����
priority_queue<T, Container, Compare>
*/

#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// first: ���밪 second: ������
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> que;

	int n;
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;

		if (x == 0) {
			if (que.size() > 0) {
				cout << que.top().second << "\n";
				que.pop();
			}
			else {
				cout << "0\n";
			}
		}
		else {
			que.push(make_pair(abs(x), x));
		}
	}

	return 0;
}