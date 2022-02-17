#include<iostream>

using namespace std;

int arr[100][100];
long long mem[100][100];

/* 이 코드는 시간초과 때문에 안씀
long long visite(int n, int x,int y) {
	if (x >= n || y >= n) //배열을 벗어남
		return 0;
	else if (x == (n - 1) && y == (n - 1)) //0에 도착
		return 1;

	int step = arr[x][y];	//가야하는 칸의 갯수
	
	return visite(n, x + step, y) + visite(n, x, y + step);
}
*/

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//long long visit;
	//visit = visite(n, 0, 0);

	int step;
	mem[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			step = arr[i][j]; //걸음 수
			if (step == 0)	//걸음수가 0이면 건너뛰기
				continue;
			if (i + step < n) {//오른쪽 이동
				mem[i + step][j] += mem[i][j];
			}
			if (j + arr[i][j] < n) { //아래 이동
				mem[i][j + step] += mem[i][j];
			}

		}
	}
	
	cout << mem[n - 1][n - 1];


	return 0;
}