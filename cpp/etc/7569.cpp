/*
7569��: �丶��
https://www.acmicpc.net/problem/7569

�丶����� ��� �ʹ��� �� �ּ� �ϼ�
�ϳ��� �丶�信 ������ ���� ��, �Ʒ�, ����, ������, ��, �� ���� ���⿡ �ִ� �丶��
*/

#include<iostream>
#include<tuple>
#include<vector>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//������ ũ�⸦ ��Ÿ���� �� ���� M,N�� �׾ƿ÷����� ������ ���� ��Ÿ���� H
	int m, n, h; //2 �� M �� 100, 2 �� N �� 100, 1 �� H �� 100
	//int arr[101][101][101];
	vector<vector<vector<int>>> vec(101,vector<vector<int>>(101,vector<int>(101)));

	
	cin >> m;
	cin >> n;
	cin >> h;
	
	int temp;
	//���� 1�� ���� �丶��, ���� 0 �� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				//cin >> arr[i][j][k];
				cin >> vec[k][j][i];
			}
		}
	}
	
	queue<tuple<int,int,int,int>> que;
	vector<vector<vector<bool>>> visit(101, vector<vector<bool>>(101, vector<bool>(101, false)));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {	
				if (vec[k][j][i] == 1) {
					que.push({ k,j,i,0 });
					//cout << k << " " << j << " " << i << "\n";
				}
			}
		}
	}
	
	int day = 0;
	tuple<int, int, int, int> t;
	while(!que.empty()){
		t = que.front();
		que.pop();

		//�湮�ߴٸ� ��湮 X. 
		//������ ���� ó���� �湮���� ���� day�� �����״�
		if (visit[get<0>(t)][get<1>(t)][get<2>(t)]) {
			continue;
		}

		visit[get<0>(t)][get<1>(t)][get<2>(t)] = true;
		//�丶�� ����
		vec[get<0>(t)][get<1>(t)][get<2>(t)] = 1;

		//que�� fifo�̹Ƿ� que�� day�� ���������� Ŀ���Ƿ� 
		// ���� ������ que���� ���°� ������ day
		day = get<3>(t);

		if (get<2>(t) > 0) {
			if (vec[get<0>(t)][get<1>(t)][get<2>(t) - 1] == 0) {
				//cout << "�� ";
				que.push({ get<0>(t),get<1>(t),get<2>(t) - 1,get<3>(t) + 1 });
			}
		}
		if (get<2>(t) < h - 1) {
			if (vec[get<0>(t)][get<1>(t)][get<2>(t) + 1] == 0) {
				//cout << "�Ʒ� ";
				que.push({ get<0>(t),get<1>(t),get<2>(t) + 1,get<3>(t) + 1 });
			}
		}
		if (get<0>(t) > 0) {
			if (vec[get<0>(t) - 1][get<1>(t)][get<2>(t)] == 0) {
				//cout << "�� ";
				que.push({ get<0>(t) - 1,get<1>(t),get<2>(t),get<3>(t) + 1 });
			}
		}
		if (get<0>(t) < m - 1) {
			if (vec[get<0>(t) + 1][get<1>(t)][get<2>(t)] == 0) {
				//cout << "�� ";
				que.push({ get<0>(t) + 1,get<1>(t) ,get<2>(t),get<3>(t) + 1 });
			}
		}
		if (get<1>(t) > 0) {
			if (vec[get<0>(t)][get<1>(t) - 1][get<2>(t)] == 0) {
				//cout << "�� ";
				que.push({ get<0>(t),get<1>(t) - 1,get<2>(t),get<3>(t) + 1 });
			}
		}
		if (get<1>(t) < n - 1) {
			if (vec[get<0>(t)][get<1>(t) + 1][get<2>(t)] == 0) {
				//cout << "�� ";
				que.push({ get<0>(t),get<1>(t) + 1,get<2>(t),get<3>(t) + 1 });
			}
		}
		//cout << "\n";
	}
	
	// ���� ���� �丶�䰡 �ִٸ� flag=false
	bool flag = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (vec[k][j][i] == 0) {
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			break;
		}
	}

	if (flag) {
		cout << "-1";
	}
	else {
		cout << day;
	}

	return 0;
}