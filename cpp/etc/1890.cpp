#include<iostream>

using namespace std;

int arr[100][100];
long long mem[100][100];

/* �� �ڵ�� �ð��ʰ� ������ �Ⱦ�
long long visite(int n, int x,int y) {
	if (x >= n || y >= n) //�迭�� ���
		return 0;
	else if (x == (n - 1) && y == (n - 1)) //0�� ����
		return 1;

	int step = arr[x][y];	//�����ϴ� ĭ�� ����
	
	return visite(n, x + step, y) + visite(n, x, y + step);
}
*/

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//long long visit;
	//visit = visite(n, 0, 0);

	int step;
	mem[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			step = arr[i][j]; //���� ��
			if (step == 0)	//�������� 0�̸� �ǳʶٱ�
				continue;
			if (i + step < n) {//������ �̵�
				mem[i + step][j] += mem[i][j];
			}
			if (j + arr[i][j] < n) { //�Ʒ� �̵�
				mem[i][j + step] += mem[i][j];
			}

		}
	}
	
	cout << mem[n - 1][n - 1];


	return 0;
}