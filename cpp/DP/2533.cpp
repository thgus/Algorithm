/*
2533번: 사회망 서비스(SNS)
https://www.acmicpc.net/problem/

노드 i의 친구가 모두 얼리아답터여야지 노드 i도 새로운 아이디어를 받아들인다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define NMAX 1000000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> vec(NMAX + 1);

void initialize()
{
	int u, v;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		vec[v].push_back(u);
		vec[u].push_back(v);
	}
}

vector<vector<int>> dp(NMAX + 1, vector<int>(2, 0));
vector<bool> isVisited(NMAX + 1, false);

pair<int,int> dfs(int cur, int pre) {

	//1: 현재 노드가 얼리아답터가 아닌 경우, 2: 현재 노드가 얼리아답터인 경우
	int r1 = 0, r2 = 1;
	for (int i = 0; i < vec[cur].size(); i++) {
		int next = vec[cur][i];
		if (isVisited[next]) {
			continue;
		}
		isVisited[next] = true;

		pair<int, int> p = dfs(next, cur);
		r2 += min(p.first, p.second);
		r1 += p.second;
	}

	return { r1,r2 };

}

void solve()
{
	isVisited[1] = true;
	pair<int, int> p = dfs(1, 0);
	int result = min(p.first, p.second);
	cout << result;
}

int main()
{
	//sync_off;
	initialize();
	solve();

	return 0;
}