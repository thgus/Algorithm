#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//ȸ�ǽ� ��� ������ �ð� ��
const bool compareE(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) //������ �ð��� ������
		return a.first < b.first;	//���۽ð� ���� ��������
	else
		return a.second < b.second;
}

// �׸��� �賶
int main() {
	int n;
	cin >> n;

	//ȸ�� ����,�� �ð� ����
	vector<pair<int,int>> lis;
	int start, end;

	//ȸ�� �ð� �Է�
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		lis.push_back(pair<int,int>(start, end));
	}
	
	int count = 0;	//ȸ�� Ƚ��
	end = -1;	//������ ȸ�ǰ� ���� �ð�

	//ȸ�ǽ� ��� ������ �ð��� �������� �������� ����
	sort(lis.begin(), lis.end(), compareE);

	for (int i = 0; i < lis.size(); i++) {
		//ȸ�ǽ� ��� ���۽ð��� ������ ȸ�ǰ� ���� �ð����� ���ĸ�
		if (end <= lis[i].first) {
			//ȸ��Ƚ�� ����
			count++;
			//ȸ�ǽ� ��� �� �ð��� ���� ȸ�ǽ� ��� �� �ð����� ����
			end = lis[i].second;
		}
	}

	cout << count;

	return 0;
}