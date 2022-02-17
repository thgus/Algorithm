/*
16571번: 알파 틱택토
https://www.acmicpc.net/problem/16571
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<vector<int>> vec(3, vector<int>(3));

int x_result = 3;
int o_result = 3;

int x_turn();
int o_turn();

void print_vec() {
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << vec[i][j];
		}
		cout << "\n";
	}
}

// 0: x가 이김, 1: o가 이김, 2: 비김, 3: 아직 승부 안남
int check_ttt() {
	int result = 3;
	int x1, o1, x2, o2;

    bool isDraw = true;
	for (int i = 0; i < 3; i++) {
		x1 = o1 = 0;
		x2 = o2 = 0;
		for (int j = 0; j < 3; j++) {
			if (vec[i][j] == 0)    isDraw = false;

			if (vec[i][j] == 1)    x1++;
			else if (vec[i][j] == 2)    o1++;

			if (vec[j][i] == 1)    x2++;
			else if (vec[j][i] == 2)    o2++;
		}
		result = (x1 == 3 || x2 == 3) ? 0 : result;
		result = (o1 == 3 || o2 == 3) ? 1 : result;
	}

	x1 = o1 = x2 = o2 = 0;
	for (int i = 0; i < 3; i++) {
		if (vec[i][i] == 1)	x1++;
		else if (vec[i][i] == 2)	o1++;

		if (vec[2 - i][i] == 1)	x2++;
		else if (vec[2 - i][i] == 2)	o2++;
	}
	result = (x1 == 3 || x2 == 3) ? 0 : result;
	result = (o1 == 3 || o2 == 3) ? 1 : result;

	result = (isDraw && result == 3) ? 2 : result;

	return result;
}

void initialize()
{
	int x, o;
	x = o = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> vec[i][j];

			if (vec[i][j] == 1)    x++;
			else if (vec[i][j] == 2)   o++;
		}
	}

	if (x <= o) {
		int result = x_turn();
		if (result == 1) {
			cout << "W";
		}
		else if (result == 0) {
			cout << "D";
		}
		else if(result==-1) {
			cout << "L";
		}
	}
	else {
		int result = o_turn();
		if (result == -1) {
			cout << "W";
		}
		else if (result == 0) {
			cout << "D";
		}
		else if (result == 1) {
			cout << "L";
		}
	}

	
}

int main()
{
	sync_off;
	initialize();

	return 0;
}

int x_turn() {
	int cur = check_ttt();
	if (cur == 0) {
		return 1;
	}
	else if (cur == 1) {
		return -1;
	}
	else if (cur == 2) {
		return 0;
	}

	bool isWin, isDraw, isLose;
	isWin = isDraw = isLose = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (vec[i][j] != 0)    continue;
			vec[i][j] = 1;
			int result = o_turn();
			if (result == 0)	isDraw = true;
			if (result == 1)	isWin = true;
			if (result == -1)	isLose = true;
			vec[i][j] = 0;
		}
	}

	if (isWin) {
		return 1;
	}
	else if (isDraw) {
		return 0;
	}
	else if (isLose) {
		return -1;
	}
}

int o_turn() {
	int cur = check_ttt();

	if (cur == 0) {
		return 1;
	}
	else if (cur == 1) {
		return -1;
	}
	else if (cur == 2) {
		return 0;
	}

	bool isWin, isDraw, isLose;
	isWin = isDraw = isLose = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (vec[i][j] != 0)    continue;
			vec[i][j] = 2;
			int result = x_turn();
			if (result == 0)	isDraw = true;
			if (result == -1)	isWin = true;
			if (result == 1)	isLose = true;
			vec[i][j] = 0;
		}
	}

	if (isWin) {
		return -1;
	}
	else if (isDraw) {
		return 0;
	}
	else if (isLose) {
		return 1;
	}
}