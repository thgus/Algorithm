/*
1967��: Ʈ���� ����
https://www.acmicpc.net/problem/1967
*/

#include<iostream>
#include<algorithm>
#include<vector>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector <vector<pair<short, short>>> vec(10001, vector<pair<short, short>>(0));
vector<vector<short>> rad(10001,vector<short>(0));
int m = 0;

int dfs(int _s) {
	if (vec[_s].size() == 0) {	//������ ���� ��
		return 0;
	}
	else if (vec[_s].size() == 1) {	//������ �ϳ��� ��
		return dfs(vec[_s][0].first) + vec[_s][0].second;
	}
	else {
		for (int i = 0; i < vec[_s].size(); i++) { //������ �ΰ� �̻� => �������� ����� ���� �� �� ����.
			rad[_s].push_back(dfs(vec[_s][i].first) + vec[_s][i].second);
		}
		sort(rad[_s].begin(), rad[_s].end(),greater<int>());
		
		//cout << _s << " " << rad[_s][0] << " " << rad[_s][1] << "\n";

		int temp = (int)rad[_s][0] + (int)rad[_s][1];
		if (m < temp) {
			m = temp;
		}

		return rad[_s][0];
	}
}

int main() {
	sync_off;
	int n;
	cin >> n;

	int s, e, d;
	for (int i = 1; i < n; i++) {
		cin >> s >> e >> d;
		vec[s].push_back({ e,d });
	}

	int temp = dfs(1);

	//���� dfs�� �ڽ��� 2���� ��쿡�� m���� �������ִµ�
	//��������� �ڽ��� 1���� ��쿣 �������� ���õ� ������ ����ġ�� ������ ���� �����Ƿ�
	//�ѹ� ������.
	if (temp > m) {
		m = temp;
	}
	cout << m;

	return 0;
}