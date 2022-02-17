/*
15654��: N�� M (5)
https://www.acmicpc.net/problem/15654
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
bool visited[9] = { false };
vector<int> vec;
vector<int> seq;

void dfs(int c) {	//c�� ���� ����
	if (c == m) {	//m���� ���� ���� ����
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		seq.push_back(vec[i]);
		dfs(c + 1);
		visited[i] = false;
		seq.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vec.push_back(-1);
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}

	//���������� ����ϱ� ���� ����
	sort(vec.begin(), vec.end());

	dfs(0);

	return 0;
}