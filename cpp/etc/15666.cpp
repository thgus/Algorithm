/*
15666��: N�� M(12)
https://www.acmicpc.net/problem/15666

 �� �ڸ����� �ѹ� ����ߴٸ� �� ���Ĵ� ������� �ʾƾ� �ߺ��� ���� ������ ����.
	������ �� ���Ŀ� ����Ѵٸ� ������ ���� ������ ���� �ߺ��� �������� �ƴ��� �� �� ����.
		=> lastValue
*/

#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 8
#define MAXVALUE 10000
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

//vector<int> _vec : ������ �� �� �ִ� ���ڵ��� �ִ� �迭
//int _seq[] : vec���� �� ���ڰ� ����Ǿ� �ִ� ����
//int _p : �񳻸����� ������ �����ϱ� ���� �������� ���� ū ���� ����
//int _c : ���� ��� ���� ������� Ȯ��. ( _c <= _m )
//int _n : ������ �� �ִ� �ڿ����� ����. vec�� ������
//int _m : �ڿ��� _n�� �� �� �� �ִ� ����.
void dfs(vector<int> vec, int seq[], int _p, int _c, int _n, int _m) {
	if (_c == _m) {
		for (int i = 0; i < _m; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}
	int lastValue = -1;
	for (int i = _p; i < _n; i++) {
		if (lastValue == vec[i]) {
			continue;
		}
		lastValue = vec[i];
		seq[_c] = vec[i];
		dfs(vec, seq, i, _c + 1, _n, _m);
	}
}

int main() {
	sync_off

	int n, m;
	cin >> n >> m;
	vector<int> vec(MAX, MAXVALUE);
	int seq[MAX];
	
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	
	dfs(vec, seq, 0, 0, n, m);

	return 0;
}