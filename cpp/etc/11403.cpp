/*
[BOJ]11403��: ���ã��
https://www.acmicpc.net/problem/11403
*/

#include<iostream>
#include<queue>

using namespace std;

int arr[100][100];
int n;

void bfs(int k) {
	queue<int> q;
	bool visit[100] = { false, };
	
	//k��° �� Ž��
	q.push(k);

	//k��° �� Ž�簡 ���� �� ����(��� �湮�ϰų�, ���� ���ų�)
	while (!q.empty()){
		//x�� ° �� Ž��
		int x = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			//�湮�ߴٸ�
			if (visit[i])
				continue;

			//x->i�� ���� ������ �ִٸ�
			if (arr[x][i] == 1) {
				visit[i] = true;	//�湮 ǥ��
				arr[k][i] = 1;		//���� ǥ��
				q.push(i);			//i��° �� Ž�縦 ���� q�� ����
			}

		}
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//n���� �� Ž��
	for (int i = 0; i < n; i++) {
		bfs(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}