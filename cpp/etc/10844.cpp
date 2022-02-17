#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	vector<long long> vec1;
	vector<long long> vec2;
	long long num;

	cin >> n;

	num = 0;

	//�� ó���� 0�� ������ ����� ���� 0�̰� �� ���� 1~9�� ������ ����� ���� 1
	vec1.push_back(0);
	vec2.push_back(0);
	for (int i = 1; i < 10; i++) {
		vec1.push_back(1);
		vec2.push_back(1);
	}

	//n�� ���̸�ŭ ���
	for (int i = 1; i < n; i++) {
		// 1~9�� �����ϴ� ���� ���� �� �ִ� ����� �� ���ϱ�
		for (int j = 0; j <= 9; j++) {
			// ����(0)�̸� �������� ���� �� �ִ� ���� �ϳ� ū ��(1)�ۿ� ������ �ʱ� ������
			// ��(0)�� �������� �� �ϳ� ū ��(1)�� ����� �� ��ŭ ����
			if (j == 0) {
				vec2[j] = vec1[j + 1];
			}
			// ����(9)�̸� ���� ���� ������ ����� ���� ������ ���� �ٷ� �ϳ� ���� ��(8)�ۿ� ������ ����
			else if (j == 9) {
				vec2[j] = vec1[j - 1];
			}
			// �� �ܿ��� �հ� �� ������ ����� ���� ���� ��ŭ ����
			else {
				vec2[j] = (vec1[j + 1] + vec1[j - 1]) % 1000000000;
			}
		}
		for (int j = 0; j < vec2.size(); j++)
			vec1[j] = vec2[j];
	}

	for (int i = 0; i < vec2.size(); i++) {
		num += vec2[i];
		num = num % 1000000000;
		
		//num += vec2[i] % 1000000000;
	}

	cout << num;

	return 0;
}