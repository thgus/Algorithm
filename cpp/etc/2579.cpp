/*
2579��: ��� ������
https://www.acmicpc.net/problem/2579

Ž�� �������پ˾Ҵɳ� dp��������;; dp �� ��ƴ�.
Ž������ �ϸ� �ð� �ʹ� ���� �ɷ�;
����� ������ 2���� ���
1. ����� 1ĭ �ö� (�̴� 3ĭ �̻� ���ӵ� ��� �̿� X)
2. ����� 2ĭ �ö�
	��Ʈ�� �����س���
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> stairs;
	stairs.push_back(0);
	int n, score;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score;
		stairs.push_back(score);
	}

	vector<int> dp;
	dp.push_back(stairs[0]);
	dp.push_back(stairs[1]);		 //1
	if (n >= 2) {
		dp.push_back(stairs[1] + stairs[2]); //2
	}
	if (n >= 3) {
		dp.push_back(max(stairs[1] + stairs[3], stairs[2] + stairs[3])); //3
	}
	for (int i = 4; i <= n; i++) {
		dp.push_back(max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]));
	}
	cout << dp[n];

	return 0;
}