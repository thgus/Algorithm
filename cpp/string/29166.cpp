/*
29166번: 문자열 지옥에 빠진 호석
https://www.acmicpc.net/problem/29166
*/

#include <iostream>
#include <vector>
#include <map>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m, k;
vector<vector<char>> vec;

map<int, string> index;
map<string, int> hs;

void initialize()
{
	cin >> n >> m >> k;
	vec.resize(n, vector<char>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}

	string str;
	for (int i = 0; i < k; i++) {
		cin >> str;
		index.insert({ i,str });
		hs.insert({ str,0 });
	}
}

int d[8][2] = { {-1,0},{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
void dfs(int y, int x, int len, string str) {
	auto it = hs.find(str);
	if (it != hs.end()) {
		it->second++;
	}
	
	if (len >= 5)  return;

	for (int i = 0; i < 8; i++) {
		int ny = y + d[i][0];
		int nx = x + d[i][1];

		if (ny != -1) {
			ny %= n;
		}
		if (nx != -1) {
			nx %= m;
		}

		if (ny == -1 && nx == -1) {
			dfs(n - 1, m - 1, len + 1, str + vec[n - 1][m - 1]);
		}
		else if (ny == -1) {
			dfs(n - 1, nx, len + 1, str + vec[n - 1][nx]);
		}
		else if (nx == -1) {
			dfs(ny, m - 1, len + 1, str + vec[ny][m - 1]);
		}
		else {
			dfs(ny, nx, len + 1, str + vec[ny][nx]);
		}
	}
}

void solve()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			string cur = "";
			cur += vec[i][j];
			dfs(i, j, 1, cur);
		}
	}
}

void print_result() {
	for (auto it = index.begin(); it != index.end();it++) {
		cout << hs.find(it->second)->second << "\n";
	}
}

int main()
{
	sync_off;
	initialize();
	solve();
	print_result();

	return 0;
}