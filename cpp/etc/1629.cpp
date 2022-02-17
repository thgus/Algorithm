/*
1629��: ����
https://www.acmicpc.net/problem/1629
��������

Ǯ�� 1
�ð��ʰ� O(n) => ���� ������ ��� ��
�׷��� ���� ������ ��� ���� �ʵ��� ������ �����ѱ� �ߴµ� ã�ƺ��� �� ���� Ǯ�̰� �־ ��� ���

Ǯ�� 2
buttom up���
2*2=4 4*4=8 ....
10�� 11�� ���ؾ� �Ѵٸ� �ϴ� 11�� 2�� ������
10^11=10^5*10^5*10 => �� ��� 10^5�� ���ϸ� 10^11�� ���� �� �� ����
10^5=10^2*10^2*10 => �� ��� 10^2�� ���ϸ� 10^5�� ���� �� �� ����
10^2=10^1*10^1
�̸� �Ʒ����� ���� �������� �����ϸ� �ߺ��� ���� ���� ���� ���� �� ����
O(nlongn)
*/

#include<iostream>
#include<algorithm>
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

//Ǯ�� 1
/* 
long long dc(int _a, int _b, int _c) {
	if (_b == 1) {
		return _a % _c;
	}
	return (dc(_a, (_b / 2), _c) * dc(_a, _b - (_b / 2), _c)) % _c;
}
*/

//Ǯ�� 2
long long dc(int _a, int _b, int _c) {
	if (_b == 1) {
		//�ݷ�) 4 1 2
		//return _a;
		return _a % _c;
	}
	long long mul = dc(_a, _b / 2, _c);
	mul = (mul * mul) % _c;
	// Ȧ���� ���� �ѹ� �� ������� ��
	if (_b % 2 == 1) {
		mul = (mul*_a) % _c;
	}

	return mul;
}


int main() {
	sync_off;
	int a, b, c;
	cin >> a >> b >> c;

	cout << dc(a, b, c);

	return 0;
}