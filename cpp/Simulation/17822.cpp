/*
17822번: 원판 돌리기
https://www.acmicpc.net/problem/17822
*/

#include <iostream>
#include <vector>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m, t;
vector<vector<int>> vec;

void printVector() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
}

void turnDisc(int x, int d, int k) {
	if (d == 1)    k = m - k;

	int cury = x;
	while (cury <= n) {
		vector<int> temp(m);
		for (int i = 0; i < m; i++) {
			temp[(i + k) % m] = vec[cury - 1][i];
		}

		vec[cury - 1] = temp;

		cury += x;
	}
}

void eraseDisc() {
	vector<vector<bool>> temp(n, vector<bool>(m, false));
	int d[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

	float min = 0;
	int num = 0;
	bool isNear = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec[i][j] != 0) {
				min += vec[i][j];
				num++;
			}

			for (int k = 0; k < 4; k++) {
				int nexty = d[k][0] + i;
				int nextx = (d[k][1] + j) % m;
				if (nextx < 0)	nextx = m - 1;

				if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < m) {

					if (vec[i][j] != 0 && vec[i][j] == vec[nexty][nextx]) {
						isNear = true;
						temp[i][j] = true;
						break;
					}
				}
			}

		}
	}

	if (isNear) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j]) vec[i][j] = 0;
			}
		}
	}
	else {
		min /= num;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vec[i][j] == 0)    continue;

				if (vec[i][j] < min)   vec[i][j] += 1;
				else if (vec[i][j] > min)  vec[i][j] -= 1;
			}
		}
	}
}

void initialize()
{
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		vector<int> temp(m);
		for (int j = 0; j < m; j++) {
			cin >> temp[j];
		}
		vec.push_back(temp);
	}

	int x, d, k;
	while (t--) {
		cin >> x >> d >> k;
		turnDisc(x, d, k);
		eraseDisc();
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result += vec[i][j];
		}
	}
	cout << result;
}

int main()
{
	sync_off;
	initialize();

	return 0;
}