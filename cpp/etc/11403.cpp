/*
[BOJ]11403번: 경로찾기
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
	
	//k번째 줄 탐사
	q.push(k);

	//k번째 줄 탐사가 끝날 때 까지(모두 방문하거나, 길이 없거나)
	while (!q.empty()){
		//x번 째 줄 탐사
		int x = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			//방문했다면
			if (visit[i])
				continue;

			//x->i로 가는 방향이 있다면
			if (arr[x][i] == 1) {
				visit[i] = true;	//방문 표시
				arr[k][i] = 1;		//방향 표시
				q.push(i);			//i번째 줄 탐사를 위해 q에 저장
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

	//n개의 줄 탐사
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