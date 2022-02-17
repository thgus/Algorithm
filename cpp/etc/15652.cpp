/*
15652¹ø: N°ú M(4)
https://www.acmicpc.net/problem/15652
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> vec;
vector<int> seq;

void bfs(int p, int c) {
	if (c == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = p; i <= n; i++) {
		seq.push_back(i);
		bfs(i, c + 1);
		seq.pop_back();
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	bfs(1, 0);

	return 0;
}