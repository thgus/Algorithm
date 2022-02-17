/*
[BOJ]1012��: ����� ����
https://www.acmicpc.net/problem/1012
*/

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

bool field[50][50] = { false, };
bool visited[50][50] = { false, };
int bug;

int t;	//testcase
//m: ����/ n:����
int n, m, k;
int x, y;

void bfs() {	
	for (int i = 0; i < n; i++) {	//����
		for (int j = 0; j < m; j++) {	//����
			
			//�湮�� ���̶�� �ٽ� �湮�� �ʿ� ����
			if (visited[i][j])
				continue;

			//���߰� �ִٸ�
			if (field[i][j]) {
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				//���� �߰�
				bug++;

				while (!q.empty()) {
					pair<int, int> xy = q.front();
					q.pop();

					//�湮�ߴٸ� �ٽ� �湮�� �ʿ� ����
					if (visited[xy.first][xy.second])
						continue;

					//Ž��
					// 0 < ����(xy.first)  < n 
					// 0 < ����(xy.second) < m
					if (xy.first - 1 >= 0) {
						if (field[xy.first - 1][xy.second] && !visited[xy.first - 1][xy.second])
							q.push(make_pair(xy.first - 1, xy.second));
					}
					if (xy.first + 1 < n) {		
						if (field[xy.first + 1][xy.second] && !visited[xy.first + 1][xy.second])
							q.push(make_pair(xy.first + 1, xy.second));
					}
					if (xy.second - 1 >= 0) {
						if (field[xy.first][xy.second - 1] && !visited[xy.first][xy.second - 1])
							q.push(make_pair(xy.first, xy.second - 1));
					}
					if (xy.second + 1 < m) {
						if (field[xy.first][xy.second + 1] && !visited[xy.first][xy.second + 1])
							q.push(make_pair(xy.first, xy.second + 1));
					}

				}
			}
		}
	}

}

int main() {
	cin >> t;

	while (t > 0) {
		bug = 0;
		cin >> m >> n >> k;

		//�ʱ�ȭ
		for (int i = 0; i < 50; i++) {
			memset(field[i], false, sizeof(bool) * 50);
			memset(visited[i], false, sizeof(bool) * 50);
		}

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			field[y][x] = true;
		}

		bfs();

		t--;

		cout << bug << "\n";
	}

	return 0;
}