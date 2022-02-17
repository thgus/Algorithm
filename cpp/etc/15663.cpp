/*
15663��: N�� M(9)
https://www.acmicpc.net/problem/15663

�ٸ� Ǯ�� ���
�� ��(n��° ��)���� ����ߴ� ���ڴ� ������� ����
 => 9 7 9 1�� �ְ� �� �� 3���� ���ٸ� 1 7 9
	�� ���� 1,10,100�� �ڸ� ���� �� �� �ִ� ����� ��

	1. �� �ڸ����� �ѹ� ����ߴٸ� �� ���Ĵ� ������� �ʾƾ� �ߺ��� ���� ������ ����.
			������ �� ���Ŀ� ����Ѵٸ� ������ ���� ������ ���� �ߺ��� �������� �ƴ��� �� �� ����.
	2. ������ ���� 1�� �ڸ����� 1�� ���ٸ� ���Ӵ� 10, 100�� �ڸ������� 1�� ���� �ȵǱ� ������
		�̷��� ���������� �߰��ϱ� ���� ���� �迭�� �߰�

	1��(�� �ڸ������� �ߺ��� ���� ����Ͽ��°�)�� 2��(�ٸ� �ڸ����� ����� ���� ����Ͽ��°�)�� ������
		���� ���� �� ����.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int n, m;
//vector<vector<int>> result;
set<vector<int>> result;
vector<int> seq;
vector<int> vec;
bool isVisited[9] = { false };

void dfs(int p, int c) {
	if (c == m) {
		//�� ������ ������ ���ٸ�
		if (result.find(seq) == result.end()) {
			for (int i = 0; i < m; i++) {
				cout << seq[i] << " ";
			}
			result.insert(seq);
			cout << "\n";
		}
		//result.push_back(seq);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isVisited[i]) {
			continue;
		}
		seq.push_back(vec[i]);
		isVisited[i] = true;
		dfs(i + 1, c + 1);
		seq.pop_back();
		isVisited[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());

	dfs(0, 0);
	
	/*
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	return 0;
}