/*
9465��: ��ƼĿ
https://www.acmicpc.net/problem/9465

��ƼĿ�� ����� ���� �����¿��� ��ƼĿ�� ������� ���ϰ� �ȴ�.

score[1][1]=sticker[1][1]
score[2][1]=sticker[2][1]

socre[1][2]=sticker[2][1]+sticker[1][2]
score[2][2]=sticker[1][1]+sticker[2][2]

score�� ������ �� �� �ִ� ���
ex) n=3
=========================
| 1	3	| 2		| 1	4	| 
|		|		|		|
=========================
| 2	4	| 1		| 2	3	|
|		|		|		|
=========================
ex) n=4
=================================
| 1	3 5	| 2	6	| 1	4	| 2	3 5	|
|		|		|		|		|
=================================
| 2	4 6	| 1	5	| 2	3	| 1	4 6	|
|		|		|		|		|
=================================
	1. �ڽ��� �ٷ� ���� �밢�� [n-1]
	2. �ڽ��� �ٷ� ���� �밢�� ���� �ڸ� [n-2]

mScore=max(score[0][n],score[1][n])
score[0][n]=max(score[1][n-1]+sticker[0][n],score[1][n-2]+sticker[0][n])
score[1][n]=max(score[0][n-1]+sticker[1][n],score[0][n-2]+sticker[1][n])
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�迭�� ũ�� �����ϸ� ������ ���� �ʹ� ������.
	//int sticker[3][50001];
	//int score[3][50001];

	vector<vector<int>> sticker(3, vector<int>(100001, 0));
	vector<vector<int>> score(3, vector<int>(100001, 0));

	int t, n;
	cin >> t;

	while (t > 0) {
		cin >> n;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> sticker[i][j];
			}
		}

		score[1][1] = sticker[1][1];
		score[2][1] = sticker[2][1];
		score[1][2] = sticker[2][1] + sticker[1][2];
		score[2][2] = sticker[1][1] + sticker[2][2];

		for (int i = 3; i <= n; i++) {
			score[1][i] = max(score[2][i - 1] + sticker[1][i], score[2][i - 2] + sticker[1][i]);
			score[2][i] = max(score[1][i - 1] + sticker[2][i], score[1][i - 2] + sticker[2][i]);
		}
		cout << max(score[1][n], score[2][n]) << "\n";

		t--;
	}

	return 0;
}