/*
18870��: ��ǥ ����
https://www.acmicpc.net/problem/18870
unique => �ߺ� ���Ҹ� �ڷ� �̵�
	���ӵ� �ߺ� ���ҿ� �ش�ǹǷ� ������ ����� ��.
erase=> �ߺ� ����

�� ������ ���� �ٸ� ��ǥ�� ������ ���ƾ� �ؼ� �����ϱ� ���
���� ���� ��ǥ�� ������ ���ƾ� �ϸ� ��� �����ؾ� ���� �ǹ�
 ex) 0 5 7 7 9 �� 0 1 2 2 3�� �ƴ϶� 0 1 2 2 4 �̷������� ���;� �Ѵٸ�?

 find(vec.begin(), vec.end(), f) - vec.begin()
 distance�� ����ϴ� ����� ����.
	=> �ð��ʰ�
 ������ ������ Ž�� �˰����� �� ����ؾ� �� �� ����.
 ����Ž�� ���

 set�� �����ߴµ� set�� �迭 ������ ��� ���ڰ� �󸶳� ū ������ �� �� ������ ��� ����.

*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long> input;
	vector<long> vec;

	int n;
	cin >> n;

	long x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
		input.push_back(x);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < input.size(); i++) {
		long v = input[i];
		cout << lower_bound(vec.begin(), vec.end(), v) - vec.begin() << " ";
	}
	

	return 0;
}