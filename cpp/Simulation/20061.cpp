/*
20061번: 모노미노도미노 2
https://www.acmicpc.net/problem/20061
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<bool> temp(4, false);

int cal_vec(vector<vector<bool>>& m) {
	int result = 0;

	//cout << "\n";
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			//cout << m[i][j];

			if (m[i][j]) result++;
		}
		//cout << "\n";
	}

	return result;
}

void erase_1(vector<vector<bool>>& m, int y) {
	for (int i = y; i > 0; i--) {
		m[i] = m[i - 1];
	}
	m[0] = temp;
}

void erase_2(vector<vector<bool>>& m, int y) {
	for (int i = y; i > 1; i--) {
		m[i] = m[i - 2];
	}
	m[1] = temp;
	m[0] = temp;
}

int fill_1(vector<vector<bool>>& m, int x) {
	int score = 1;

	for (int y = 2; y < 7; y++) {
		if (y == 6) {}
		else if (!m[y][x]) continue;
		y--;

		m[y][x] = true;
		bool isFull = true;
		for (int i = 0; i < 4; i++) {
			if (!m[y][i]) {
				score--;
				isFull = false;
				break;
			}
		}

		if (isFull) {
			erase_1(m, y);
		}
		else if (y < 2) {
			erase_1(m, 5);
		}

		return score;
	}

	return 0;
}

int fill_2(vector<vector<bool>>& m, int x) {
	int score = 2;
	for (int y = 1; y < 6; y++) {
		if (y == 5) {}
		else if (!m[y][x] && !m[y + 1][x]) continue;
		y--;

		m[y][x] = true;
		m[y + 1][x] = true;

		bool isFull1, isFull2;
		isFull1 = isFull2 = true;
		for (int i = 0; i < 4; i++) {
			if (!m[y][i]) {
				score--;
				isFull1 = false;
				break;
			}
		}

		for (int i = 0; i < 4; i++) {
			if (!m[y + 1][i]) {
				score--;
				isFull2 = false;
				break;
			}
		}

		if (isFull1 && isFull2) {
			erase_2(m, y+1);
		}
		else if (isFull1) {
			erase_1(m, y);
		}
		else if (isFull2) {
			erase_1(m, y + 1);
		}
		else if (y == 1) {
			erase_1(m, 5);
		}
		else if (y == 0) {
			erase_2(m, 5);
		}

		return score;
	}

	return 0;
}

int fill_3(vector<vector<bool>> & m, int x) {
	int score = 1;
	for (int y = 2; y < 7; y++) {
		if (y == 6) {}
		else if (!m[y][x] && !m[y][x + 1]) continue;
		y--;

		m[y][x] = true;
		m[y][x + 1] = true;

		bool isFull = true;
		for (int i = 0; i < 4; i++) {
			if (!m[y][i]) {
				score--;
				isFull = false;
				break;
			}
		}

		if (isFull) {
			erase_1(m, y);
		}
		else if (y < 2) {
			erase_1(m, 5);
		}

		return score;
	}

	return 0;
}

void initialize()
{
	int t, n, x, y;
	cin >> t;

	vector<vector<bool>> r(6, vector<bool>(4, false));
	vector<vector<bool>> c(6, vector<bool>(4, false));
	int result = 0;
	while (t--) {
		cin >> n >> y >> x;
		switch (n)
		{
		case 1:
			result += fill_1(r, x);
			result += fill_1(c, 3 - y);
			break;
		case 2:
			result += fill_3(r, x);
			result += fill_2(c, 3 - y);
			break;
		case 3:
			result += fill_2(r, x);
			result += fill_3(c, 3 - (y + 1));
			break;
		}

		cal_vec(r);
	}

	cout << result << "\n";
	cout << cal_vec(r) + cal_vec(c);

}

int main()
{
	sync_off;
	initialize();

	return 0;
}