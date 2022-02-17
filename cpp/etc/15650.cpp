/*
15650��: N�� M (2)
https://www.acmicpc.net/problem/15650

�ڿ��� N�� M
1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
�� ������ ���������̾�� �Ѵ�.

��Ʈ��ŷ �ű��ϳ�
https://chanhuiseok.github.io/posts/baek-1/

�� �̰� �ݺ������� Ǯ������� �������� ���� �ȳ���;
���߿� �ݺ������� Ǫ�� ���� �˾ƺ�����;; �ϴ� ��ͷ� Ǭ��.
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