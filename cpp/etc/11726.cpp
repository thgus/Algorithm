/*
11726��: 2xn Ÿ�ϸ�
https://www.acmicpc.net/problem/11279

d[n] = d[n-2] + d[n-1]
d[n-2] : �����ʿ� ������ ���簢�� 2�� �߰�
		������ ���簢�� ����� ���� d[n-1]���� ä����
d[n-1] : �����ʿ� ������ ���簢�� 1�� �߰�

����� d[n]�� 10,007�� ���� ������ ���
	������ ����� �ϴٺ��� ������ ������ �Ѿ�� ������
		����� �� �� ���� 10,007���� �����ش� => �̷��� �ص� ��� ����
*/
#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<long long> vec(1001, 0);
	int n;
	cin >> n;
	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 2;
	for (int i = 3; i <= n; i++) {
		vec[i] = (vec[i - 1] + vec[i - 2]) % 10007;
	}
	cout << vec[n];
	return 0;
}