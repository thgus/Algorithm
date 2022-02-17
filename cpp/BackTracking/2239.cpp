/*
2239번: 스도쿠
https://www.acmicpc.net/problem/2239

결국 무식하게 한번씩 다 비교해주는 코드로 했다
너무 오래 생각했네;;
*/

#include<iostream>
#include<vector>
#include<queue>

#define PSIZE 9
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<vector<int>> sudoku(PSIZE + 1, vector<int>(PSIZE + 1));
vector<vector<bool>> isVisited(PSIZE + 1, vector<bool>(PSIZE + 1, false));

void initialize();
bool solve(int row, int leftBlank);

vector<vector<int>> notExistPoint(PSIZE + 1);
vector<vector<int>> notExistNum(PSIZE + 1);

int main() {
	sync_off;
	initialize();
	solve(1, notExistPoint[1].size());

	return 0;
}

void initialize() {
	char c;
	for (int i = 1; i <= PSIZE; i++) {
		for (int j = 1; j <= PSIZE; j++) {
			cin >> c;
			sudoku[i][j] = c - '0';
			
			if (c != '0') {
				isVisited[i][c - '0'] = true;
			}
			else {
				notExistPoint[i].push_back(j);
			}
		}
		for (int j = 1; j <= PSIZE; j++) {
			if (!isVisited[i][j]) {
				notExistNum[i].push_back(j);
			}
		}
	}
}

void printResult() {
	for (int i = 1; i <= PSIZE; i++) {
		for (int j = 1; j <= PSIZE; j++) {
			cout << sudoku[i][j];
		}
		cout << "\n";
	}
}

bool solve(int row, int leftBlank) {

	if (leftBlank == 0) {
		if (row == PSIZE) {
			printResult();
			return true;
		}
		return solve(row + 1, notExistPoint[row + 1].size());
	}
	else {
		bool isContinue;
		int px = notExistPoint[row][notExistPoint[row].size() - leftBlank];

		for (int i = 1; i <= PSIZE; i++) {
			isContinue = false;
			//가로 중복 제거
			for (int x = 1; x <= PSIZE; x++) {
				if (sudoku[row][x] == i) {
					isContinue = true;
					break;
				}
			}
			if (isContinue) {
				continue;
			}
			//세로 중복 제거
			for (int y = 1; y <= PSIZE; y++) {
				if (sudoku[y][px] == i) {
					isContinue = true;
					break;
				}
			}
			if (isContinue) {
				continue;
			}
			//3X3 중복 제거
			int xStart = ((px - 1) / 3) * 3 + 1;
			int yStart = ((row - 1) / 3) * 3 + 1;
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					if (sudoku[yStart+y][xStart+x] == i) {
						isContinue = true;
						break;
					}
				}
				if (isContinue) {
					break;
				}
			}
			if (isContinue) {
				continue;
			}

			isVisited[row][i] = true;
			sudoku[row][px] = i;
			if (!solve(row, leftBlank-1)) {
				isVisited[row][i] = false;
				sudoku[row][px] = 0;
			}
			else {
				return true;
			}
		}
		return false;
	}
}
