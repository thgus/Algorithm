#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<bool> visited(100000, false);

//dfs
//넓이우선탐색을 사용하기 때문에 방문 횟수를 비교하지 않아도
//가장 빨리 방문한게 방문 횟수가 적은 것이므로
//가장 빨리 방문횟수가 같아지는 때가 최소 방문 횟수이다.
int dfs(int A, int B, int n, int m) {

	//first=위치, second=방문 횟수
	queue<pair<int, int>> q;

	//진규의 위치부터 시작
	q.push(make_pair(n, 0));

	while (!q.empty()) {
		int loc = q.front().first;
		int num = q.front().second;
		q.pop();

		//주미의 위치와 같다면 도착~!
		if (loc == m) {
			return num;
		}

		//+1
		//배열 크기를 넘어가지 않고, 이전에 방문하지 않았다면 방문하지 않았다면
		if (loc + 1 < m && !visited[loc + 1]) {
			//다음에 탐색하도록 q에 넣음
			q.push(make_pair(loc + 1, num + 1));
			//방문 표시
			visited[loc + 1] = true;	
		}
		//-1
		if (loc - 1 >= 0 && !visited[loc - 1]) {
			q.push(make_pair(loc - 1, num + 1));
			visited[loc - 1] = true;
		}
		//+A
		if (loc + A <= m && !visited[loc + A]) {
			q.push(make_pair(loc + A, num + 1));
			visited[loc + A] = true;
		}
		//+B
		if (loc + B <= m && !visited[loc + B]) {
			q.push(make_pair(loc + B, num + 1));
			visited[loc + B] = true;
		}
		//-A
		if (loc - A >= 0 && !visited[loc - A]) {
			q.push(make_pair(loc - A, num + 1));
			visited[loc - A] = true;
		}
		//-B
		if (loc - B >= 0 && !visited[loc - B]) {
			q.push(make_pair(loc - B, num + 1));
			visited[loc - B] = true;
		}
		//loc*A
		if (loc * A <= m && !visited[loc * A]) {
			q.push(make_pair(loc * A, num + 1));
			visited[loc * A] = true;
		}
		//loc*B
		if (loc * B <= m && !visited[loc * B]) {
			q.push(make_pair(loc * B, num + 1));
			visited[loc * B] = true;
		}
	}
}


int main() {
	//스카이콩콩 힘
	int a, b;
	cin >> a >> b;
	
	//n=진규의 위치, m=주미의 위치
	int n, m;
	cin >> n >> m;

	cout << dfs(a, b, n, m);

	return 0;
}