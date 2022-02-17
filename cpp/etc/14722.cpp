//https://www.acmicpc.net/problem/14722

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int** milkCity;	//����
	int*** mem;		//���� Ƚ��
	
	int n;
	cin >> n;

	//�����Ҵ�(���� ũ�Ⱑ �ִ� 1000*1000)
	milkCity = new int*[n];
	mem = new int** [n];
	for (int i = 0; i < n; i++) {
		milkCity[i] = new int[n];
		mem[i] = new int*[n];
		for (int j = 0; j < n; j++) {
			mem[i][j] = new int[3];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> milkCity[i][j];
			//������� ���Կ����� ���� ���ñ� ���� ����
			mem[i][j][0] = (milkCity[i][j] == 0) ? 1 : 0;
			mem[i][j][1] = 0;
			mem[i][j][2] = 0;
		}
	}

	//0: �������, 1: ���ڿ���, 2: �ٳ�������
	//���� ���� ù���� �������θ� �����̱� ������ ũ��� �ʿ� X
	//���� ù��
	for (int i = 1; i < n; i++) {
		if (milkCity[0][i] == 0) { //������� �����϶�
			if (mem[0][i - 1][2] != 0) //�ٳ��������� ���� ���¿� ���� ������
				mem[0][i][0] = mem[0][i - 1][2] + 1; //����������� ���� ���� = �ٳ������� Ƚ��+1 
			//else => mem[0][i-1][2]=0�̸� 0���� �ʱ�ȭ �� ���̱� ������ ���� ������ �ʿ� ����
			mem[0][i][1] = mem[0][i - 1][1];
			mem[0][i][2] = mem[0][i - 1][2]; 
		}
		else if (milkCity[0][i] == 1) {
			if (mem[0][i - 1][0] != 0)
				mem[0][i][1] = mem[0][i - 1][0] + 1;
			mem[0][i][0] = mem[0][i - 1][0];
			mem[0][i][2] = mem[0][i - 1][2];
		}
		else if (milkCity[0][i] == 2) {
			if (mem[0][i - 1][1] != 0)
				mem[0][i][2] = mem[0][i - 1][1] + 1;
			mem[0][i][0] = mem[0][i - 1][0];
			mem[0][i][1] = mem[0][i - 1][1];
		}
	}
	//���� ù��
	for (int i = 1; i < n; i++) {
		if (milkCity[i][0] == 0) { 
			if (mem[i - 1][0][2] != 0) 
				mem[i][0][0] = mem[i-1][0][2] + 1; 
			mem[i][0][1] = mem[i - 1][0][1];
			mem[i][0][2] = mem[i - 1][0][2];
		}
		else if (milkCity[i][0] == 1) {
			if (mem[i - 1][0][0] != 0)
				mem[i][0][1] = mem[i - 1][0][0] + 1;
			mem[i][0][0] = mem[i - 1][0][0];
			mem[i][0][2] = mem[i - 1][0][2];
		}
		else if (milkCity[i][0] == 2) {
			if (mem[i - 1][0][1] != 0)
				mem[i][0][2] = mem[i - 1][0][1] + 1;
			mem[i][0][0] = mem[i - 1][0][0];
			mem[i][0][1] = mem[i - 1][0][1];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (milkCity[i][j] == 0) {
				//��, ���� ��
				if (mem[i - 1][j][2] != 0)
					mem[i][j][0] = mem[i - 1][j][2] + 1;
				if (mem[i][j - 1][2] != 0)
					mem[i][j][0] = max(mem[i][j][0], mem[i][j - 1][2] + 1);
				mem[i][j][1] = max(mem[i - 1][j][1], mem[i][j - 1][1]);
				mem[i][j][2] = max(mem[i - 1][j][2], mem[i][j - 1][2]);
			}
			else if (milkCity[i][j] == 1) {
				if (mem[i - 1][j][0] != 0)
					mem[i][j][1] = mem[i - 1][j][0] + 1;
				if (mem[i][j - 1][0] != 0)
					mem[i][j][1] = max(mem[i][j][1], mem[i][j - 1][0] + 1);
				mem[i][j][0] = max(mem[i - 1][j][0], mem[i][j - 1][0]);
				mem[i][j][2] = max(mem[i - 1][j][2], mem[i][j - 1][2]);
			}
			else if (milkCity[i][j] == 2) {
				if (mem[i - 1][j][1] != 0)
					mem[i][j][2] = mem[i - 1][j][1] + 1;
				if (mem[i][j - 1][1] != 0)
					mem[i][j][2] = max(mem[i][j][2], mem[i][j - 1][1] + 1);
				mem[i][j][1] = max(mem[i - 1][j][1], mem[i][j - 1][1]);
				mem[i][j][0] = max(mem[i - 1][j][0], mem[i][j - 1][0]);
			}
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << mem[i][j][0] << " ";
	//	}
	//	cout << "\n";
	//}

	cout << max(mem[n - 1][n - 1][0],max(mem[n - 1][n - 1][1], mem[n - 1][n - 1][2]));

	return 0;
}