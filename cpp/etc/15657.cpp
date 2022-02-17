/*
15657��: N�� M(8)
https://www.acmicpc.net/problem/15657
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> seq;
vector<int> vec;

// p�� ������ �� �� �ִ� ���� ���� ���� �ε���.(�񳻸����� ����)
// c�� ���ݱ��� ���� ����
void bfs(int p, int c) {
	// ������ ���̰� m�̶�� ������ �����ϸ� ���
	if (c == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	//���� ������ ���� �� �ִ� ���� p����(�������� ���� ū ��) ���ų� ū ��츸 ����
	for (int i = p; i <= n ; i++) {
		seq.push_back(vec[i]);
		//���� �������� ���� ū �� i.
		//	�ε����� ���� �������� ���� ū ������ ������ �����ϴ� ����ۿ� ���� �ʰ�
		//	vec�� ������������ ���ĵǾ� �����Ƿ� i�� seq���� ���� ū ���̴�.
		//������ �ϳ��� �־����Ƿ� ���� ���� 1 ����
		bfs(i, c + 1);
		//bfs�� �������Դٴ� ���� ������ ���̰� m�̶�� ������ �����ߴٴ� ���̹Ƿ� ���� ���ڸ� �������� pop���ֱ�
		seq.pop_back();
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int temp;

	// ���Ǹ� ���� �迭�� �ε��� 1���� �����ϱ� ���� 0�� ���̰��� �־���
	vec.push_back(-1);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	//���� ������ �����ϴ� ������ ����ϱ� ���� ����
	sort(vec.begin(), vec.end());

	//bfs����
	bfs(1, 0);

	return 0;
}