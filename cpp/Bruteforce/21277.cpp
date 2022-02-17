/*
21277번: 짠돌이 호석
https://www.acmicpc.net/problem/21277
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 50
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n1, m1;
int n2, m2;

vector<vector<bool>> puz1;
vector<vector<bool>> puz2;

void initialize()
{
	char temp;

	cin >> n1 >> m1;
	puz1.resize(n1, vector<bool>(m1));
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			cin >> temp;
			puz1[i][j] = (temp == '1') ? true : false;
		}
	}

	cin >> n2 >> m2;
	puz2.resize(n2, vector<bool>(m2));
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m2; j++) {
			cin >> temp;
			puz2[i][j] = (temp == '1') ? true : false;
		}
	}
}

void print_vector(vector<vector<bool>> & vec) {
	cout << "\n";
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j];
		}
		cout << "\n";
	}
}

int merge_puz(const vector<vector<bool>> & puz1, vector<vector<bool>> puz2, int y, int x) {
	for (int k = 0; k < MAX; k++) {
		for (int l = 0; l < MAX; l++) {
			bool p1_b = puz1[k][l];
			bool p2_b = puz2[y + k][x + l];

			if (p1_b && p2_b) {
				return 1e9;
			}

			if (p1_b) {
				puz2[y + k][x + l] = true;
			}
		}
	}

	int max_y = 0;
	int max_x = 0;
	for (int i = 0; i < MAX*2; i++) {
		for (int j = 0; j < MAX*2; j++) {
			if (puz2[i][j]) {
				max_y = max(max_y, i);
				max_x = max(max_x, j);
			}
		}
	}

	return (max_y + 1) * (max_x + 1);
}

int cal_size(vector<vector<bool>> & p1, vector<vector<bool>> & p2) {
	int sum = 1e9;

	for (int i = 0; i < MAX + 1; i++) {
		for (int j = 0; j < MAX + 1; j++) {
			int cur_merge_result = merge_puz(p1, p2, i, j);
			if (cur_merge_result == 1e9)   continue;

			sum = min(sum, cur_merge_result);
			break;
		}
	}
	return sum;
}

vector<vector<vector<bool>>> turn_puz(vector<vector<bool>> puz, int n, int m) {
	vector<vector<vector<bool>>> p(4, vector<vector<bool>>(MAX * 2, vector<bool>(MAX * 2)));
	for (int l = 0; l < 4; l++) {
		for (int p_y = 0; p_y < n; p_y++) {
			for (int p_x = 0; p_x < m; p_x++) {

				switch (l)
				{
				case 0:
					p[l][p_y][p_x] = puz[p_y][p_x];
					break;
				case 1:
					p[l][(m - 1) - p_x][p_y] = puz[p_y][p_x];
					break;
				case 2:
					p[l][(n - 1) - p_y][(m - 1) - p_x] = puz[p_y][p_x];
					break;
				case 3:
					p[l][p_x][(n - 1) - p_y] = puz[p_y][p_x];
					break;
				}
			}
		}
	}
	return p;
}

void solve()
{
	int result = 1e9;
	vector<vector<vector<bool>>> p1 = turn_puz(puz1, n1, m1);
	vector<vector<vector<bool>>> p2 = turn_puz(puz2, n2, m2);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result = min(result, cal_size(p1[i], p2[j]));
			result = min(result, cal_size(p2[j], p1[i]));
		}
	}
	cout << result;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}