//https://www.acmicpc.net/problem/14722

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int** milkCity;	//도시
	int*** mem;		//먹은 횟수
	
	int n;
	cin >> n;

	//동적할당(도시 크기가 최대 1000*1000)
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
			//딸기우유 가게에서는 우유 마시기 시작 가능
			mem[i][j][0] = (milkCity[i][j] == 0) ? 1 : 0;
			mem[i][j][1] = 0;
			mem[i][j][2] = 0;
		}
	}

	//0: 딸기우유, 1: 초코우유, 2: 바나나우유
	//가로 세로 첫줄은 한쪽으로만 움직이기 때문에 크기비교 필요 X
	//가로 첫줄
	for (int i = 1; i < n; i++) {
		if (milkCity[0][i] == 0) { //딸기우유 가게일때
			if (mem[0][i - 1][2] != 0) //바나나우유를 먹은 상태에 값이 있으면
				mem[0][i][0] = mem[0][i - 1][2] + 1; //딸기우유까지 먹은 상태 = 바나나우유 횟수+1 
			//else => mem[0][i-1][2]=0이면 0으로 초기화 할 것이기 때문에 값을 대입할 필요 없음
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
	//세로 첫줄
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
				//위, 왼쪽 비교
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