#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int bfs(int x) {
	vector<bool> visit(1000001, false);

	//first=숫자, second=연산 횟수
	queue<pair<int, int>> q;
	q.push(make_pair(x, 0));
	
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (num == 1) {
			return cnt;
		}

		if (num % 3 == 0 && !visit[num / 3]) {
			visit[num / 3] = true;
			q.push(make_pair(num / 3, cnt + 1));
		}
		if (num % 2 == 0 && !visit[num / 2]) {
			visit[num / 2] = true;
			q.push(make_pair(num / 2, cnt + 1));
		}
		if (num - 1 >= 1 && !visit[num - 1]) {
			visit[num - 1] = true;
			q.push(make_pair(num - 1, cnt + 1));
		}

	}
}

int dp(int x) {
	vector<int> vec(1000001, 0);
	vec[0] = 0;
	vec[1] = 0;
	vec[2] = 1;
	vec[3] = 1;

	vector<int> temp(3, 1000001);

	for (int i = 4; i <= x; i++) {
		if (i % 3 == 0) {
			temp[0] = vec[i / 3] + 1;
		}
		else {
			temp[0] = 1000001;
		}
		if (i % 2 == 0) {
			temp[1] = vec[i / 2] + 1;
		}
		else {
			temp[1] = 1000001;
		}
		temp[2] = vec[i - 1] + 1;

		sort(temp.begin(), temp.end());

		vec[i] = temp[2];
	}
	return vec[x];
}

int main() {
	int x;
	cin >> x;

	//방법 1: bfs
	cout << bfs(x);

	//방법 2: dp
	cout << bfs(x);


	return 0;
}