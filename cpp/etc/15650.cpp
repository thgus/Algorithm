/*
15650번: N과 M (2)
https://www.acmicpc.net/problem/15650

자연수 N과 M
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.

백트래킹 신기하네
https://chanhuiseok.github.io/posts/baek-1/

아 이거 반복문으로 풀고싶은데 어케할지 감이 안나네;
나중에 반복문으로 푸는 법도 알아봐야지;; 일단 재귀로 푼다.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> vec;

void dfs(int p, int c) {
	if (c == m) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = p; i <= n - m + c + 1; i++) {
		vec.push_back(i);
		dfs(i + 1, c + 1);
		vec.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;

	dfs(1, 0);

	return 0;
}