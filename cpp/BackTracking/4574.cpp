/*
4574번: 스도미노쿠
https://www.acmicpc.net/problem/4574
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int try_num = 0;

void check_overlap(vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<vector<bool>>>& square, int y, int x, int num) {
	row[y][num] = true;
	col[x][num] = true;
	square[y / 3][x / 3][num] = true;
}

void release_overlap(vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<vector<bool>>>& square, int y, int x, int num) {
	row[y][num] = false;
	col[x][num] = false;
	square[y / 3][x / 3][num] = false;
}

void print_sudoku(vector<vector<int>>& sudoku) {
	cout << "Puzzle " << ++try_num << "\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j];
		}
		cout << "\n";
	}
}

void print_bool(vector<vector<bool>>& sudoku) {
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << sudoku[i][j];
		}
		cout << "\n";
	}
}

bool check_can_insert(vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<vector<bool>>>& square, int y, int x, int num) {
	int sy = y / 3;
	int sx = x / 3;

	if (!row[y][num] && !col[x][num] && !square[sy][sx][num]) {
		return true;
	}
	else {
		return false;
	}
}

bool check_is_boundary(int y, int x) {
	if (y >= 0 && y < 9 && x >= 0 && x < 9) {
		return true;
	}
	else {
		return false;
	}
}

void insert_number(vector<vector<int>>& sudoku, vector<vector<bool>>& domino, int y1, int x1, int y2, int x2, int num1, int num2) {
	sudoku[y1][x1] = num1;
	sudoku[y2][x2] = num2;
	domino[num1][num2] = domino[num2][num1] = false;
}

void delete_number(vector<vector<int>>& sudoku, vector<vector<bool>>& domino, int y1, int x1, int y2, int x2, int num1, int num2) {
	sudoku[y1][x1] = sudoku[y2][x2] = 0;
	domino[num1][num2] = domino[num2][num1] = true;
}

bool dfs(vector<vector<int>>& sudoku, vector<vector<bool>>& domino, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<vector<bool>>>& square, int y, int x) {	
	if (!check_is_boundary(y, x)) {
		return true;
	}
	
	int next_y = y + ((x + 1) / 9);
	int next_x = (x + 1) % 9;
	int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	if (sudoku[y][x]) {
		if (dfs(sudoku, domino, row, col, square, next_y, next_x)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		for (int i = 1; i < 10; i++) {
			if (!check_can_insert(row, col, square, y, x, i)) continue;
			for (int k = 0; k < 4; k++) {
				int pair_y = y + d[k][0];
				int pair_x = x + d[k][1];
				if (!check_is_boundary(pair_y, pair_x))   continue;
				if (sudoku[pair_y][pair_x])  continue;

				for (int j = 1; j < 10; j++) {
					if (i == j)    continue;
					if (!domino[i][j])   continue;
					if (!check_can_insert(row, col, square, pair_y, pair_x, j))   continue;

					insert_number(sudoku, domino, y, x, pair_y, pair_x, i, j);
					check_overlap(row, col, square, y, x, i);
					check_overlap(row, col, square, pair_y, pair_x, j);
					if (dfs(sudoku, domino, row, col, square, next_y, next_x)) {
						return true;
					}
					delete_number(sudoku, domino, y, x, pair_y, pair_x, i, j);
					release_overlap(row, col, square, y, x, i);
					release_overlap(row, col, square, pair_y, pair_x, j);
				}
			}
		}

		return false;
	}
}

void solve()
{
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;

		vector<vector<int>> sudoku(9, vector<int>(9, 0));
		vector<vector<bool>> domino(10, vector<bool>(10, true));

		vector<vector<bool>> row(9, vector<bool>(10, false));
		vector<vector<bool>> col(9, vector<bool>(10, false));
		vector<vector<vector<bool>>> square(3, vector<vector<bool>>(3, vector<bool>(10, false)));

		int d1, d2;
		string s1, s2;
		while (n--) {
			cin >> d1 >> s1 >> d2 >> s2;
			int y1 = s1[0] - 'A', y2 = s2[0] - 'A';
			int x1 = s1[1] - '1', x2 = s2[1] - '1';

			sudoku[y1][x1] = d1;
			sudoku[y2][x2] = d2;
			domino[d1][d2] = domino[d2][d1] = false;

			check_overlap(row, col, square, y1, x1, d1);
			check_overlap(row, col, square, y2, x2, d2);
		}

		for (int i = 1; i < 10; i++) {
			cin >> s1;
			int y = s1[0] - 'A', x = s1[1] - '1';
			sudoku[y][x] = i;

			check_overlap(row, col, square, y, x, i);
		}

		dfs(sudoku, domino, row, col, square, 0, 0);

		print_sudoku(sudoku);

	}
}

int main()
{
	sync_off;
	solve();

	return 0;
}