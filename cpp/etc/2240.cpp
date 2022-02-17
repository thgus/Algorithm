/*
2240��: �ڵγ���
https://www.acmicpc.net/problem/2240

���̳��� ���α׷���

�ʿ��� ��� : ���� �� �ִ� ��(��ġ), �ڵΰ� �������� �ð�, �̵�Ƚ�� => �� �ڵθ� � �Ծ��°�
	plum[��ġ][�ð�][�̵�Ƚ��]= ���� �ڵ� ����
1. �ڵΰ� 1���� ������ ��
	���� 1�� ������. => ������, �ȿ����� (+1)
	���� 2�� ������. => ������ (+1), �ȿ�����
2. �ڵΰ� 2���� ������ ��
	���� 1�� ������. => ������ (+1), �ȿ����� 
	���� 2�� ������. => ������, �ȿ����� (+1)

*/
#include<iostream>
#include<algorithm> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int plum[3][1001][31] = { 0 };
	int treeList[1001] = { 0 };

	int t, w;	//t:�ð�, w: ������ Ƚ��
	cin >> t;
	cin >> w;

	for (int i = 1; i <= t; i++) {
		cin >> treeList[i];
	}

	
	//�ʱ� ����
	if (treeList[1] == 1) {
		plum[1][1][0] = 1;
	}
	else if(treeList[1] == 2) {
		plum[2][1][1] = 1;	//1<=w<=30�̹Ƿ� w-1�� �׻� ����
	}

	for (int i = 2; i <= t; i++) {	// �ð�
		for (int j = 0; j <= w; j++) {	//������ Ƚ��
			if (treeList[i] == 1) {
				if (j == 0) {	// ���ݱ��� �������� �ʾҴٸ� �� �ڸ����� ���� �ڵ� ������ ��
					plum[1][i][j] = plum[1][i - 1][j] + 1;
					plum[2][i][j] = plum[2][i - 1][j];
				}
				else if(j > 0)
				{
					plum[1][i][j] = max(plum[1][i - 1][j] + 1, plum[2][i - 1][j - 1] + 1);
					plum[2][i][j] = max(plum[1][i - 1][j - 1], plum[2][i - 1][j]);
				}
			}
			else if (treeList[i] == 2) {
				if (j == 0) {
					plum[1][i][j] = plum[1][i - 1][j];
					plum[2][i][j] = plum[2][i - 1][j] + 1;
				}
				else if (j > 0) {
					plum[1][i][j] = max(plum[1][i - 1][j], plum[2][i - 1][j - 1]);
					plum[2][i][j] = max(plum[1][i - 1][j - 1] + 1, plum[2][i - 1][j] + 1);
				}
			}
			//cout << "plum[1][" << i << "][" << j << "]=" << plum[1][i][j] << "\n";
			//cout << "plum[2][" << i << "][" << j << "]=" << plum[2][i][j] << "\n";
		}
	}

	int m = -1;
	for (int i = 0; i <= w; i++) {
		m = max(m, max(plum[1][t][i], plum[2][t][i]));
	}
	cout << m;

	return 0;
}