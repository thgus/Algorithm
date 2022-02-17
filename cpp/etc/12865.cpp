/*
12865��: ����� �賶
https://www.acmicpc.net/problem/12865

https://gsmesie692.tistory.com/113
*/

#include<iostream>
#include<algorithm>
#include<vector>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

//��ġ ����
//vector<vector<int>> vec(100001, vector<int>(101, 0));
vector<int> vec(100001);

int main() {
	sync_off;
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> object(101);
	int w, v;

	//object.push_back({ 0,0 });
	for (int i = 1; i <= n; i++) {
		cin >> w >> v;
		object[i] = make_pair( w,v );
	}
	
	int rw;	//���� �賶 ����
	//j ����, i ����
	/*
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= k; i++) {
			if (i >= object[j].first) {
				rw = i - object[j].first;
				vec[i][j] = max(object[j].second + vec[rw][j - 1], vec[i][j - 1]);
			}
			else {
				vec[i][j] = vec[i][j - 1];
			}
		}
		cout << "\n";
	}
	*/

	//1���� �迭�� Ǯ�� 
	//2�����迭���� ���� ������ ���� ���� �����޴µ� ���� ������ ������ �� �ְ� ��.
	for (int j = 1; j <= n; j++) {
		//�賶�� ���� ���Ը�ŭ ���� �迭���� ���� �������µ�
		//���� �迭�� ���� ���ŵ��� �ʵ��� ���Դ� �۾������� �ݺ�
		for (int i = k; i > 0; i--) {
			if (i >= object[j].first) {
				rw = i - object[j].first;
				vec[i] = max(vec[i], object[j].second + vec[rw]);
			}
		}
	}

	cout << vec[k];

	return 0;
}