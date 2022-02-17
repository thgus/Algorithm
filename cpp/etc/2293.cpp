/*
[BOJ]2293��: ����1
https://www.acmicpc.net/problem/2293
*/

#include<iostream>
#include<vector>


using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> coin(10001, 0);
	vector<int> mem(10001, 0);

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	//0�� ���� ���� �ϳ��� ����Ѵٴ� ���̱� ������ ����� �� 1
	mem[0] = 1;

	//1,2,5 ������ ������ 1�� ��� + 2�߰� + 5�߰�
	for (int i = 1; i <= n; i++) {
		//�߰��ϴ� ���� ũ����� �����ؼ� ���ϴ� �׼�����
		for (int j = coin[i]; j <= k; j++) {
			//����Ǽ� ���ϱ� 
			//ex) ���� ũ�� 5, ���ϴ� �׼� 7 => 5=5+0, 6=5+1, 7=5+2
			// 7 = 5�� ����Ǽ� + 2�� ����Ǽ�
			mem[j] += mem[j - coin[i]];
		}
	}

	cout << mem[k];

	return 0;
}