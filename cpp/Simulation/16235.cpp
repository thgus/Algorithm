/*
16235번: 나무 재테크
https://www.acmicpc.net/problem/16235
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define NMAX 10
#define AGEMAX 1000
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

//n: 배열 크기
//m: 나무 수
//k: k년이 지난 후 남은 나무 수 출력
int n, m, k;

deque<pair<int, pair<int, int>>> tree;
int map[11][11];
int food[11][11];
int cnt[11][11][AGEMAX+1];

void initialize()
{
	for (int i = 1; i <= NMAX; i++) {
		for (int j = 1; j <= NMAX; j++) {
			for (int k = 1; k <= AGEMAX; k++) {
				cnt[i][j][k] = 0;
			}
		}
	}

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> food[i][j];
			map[i][j] = 5;
		}
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		tree.push_back({ c,{a,b} });
		cnt[a][b][c]++;
	}
}


void solve()
{
	int d[8][2] = { {-1,-1},{-1,0},{1,0},{0,-1},{0,1},{1,-1},{1,1},{-1,1} };
	sort(tree.begin(), tree.end());
	vector<vector<int>> dieTree(NMAX + 1, vector<int>(NMAX + 1, 0));

	while (k--) {
		deque<pair<int, pair<int, int>>> que;

		int tcnt[11][11][AGEMAX+1];
		for (int i = 0; i <= NMAX; i++) {
			for (int j = 0; j <= NMAX; j++) {
				for (int k = 0; k <= AGEMAX; k++) {
					tcnt[i][j][k] = 0;
				}
			}
		}

		while (!tree.empty()) {
			int age = tree.front().first;
			int r = tree.front().second.first;
			int c = tree.front().second.second;
			tree.pop_front();

			int savetree = 0;
			while (savetree < cnt[r][c][age] && (savetree + 1) * age <= map[r][c]) {
				savetree++;
			}
			map[r][c] -= savetree * age;
			dieTree[r][c] += (age / 2) * (cnt[r][c][age] - savetree);
			tcnt[r][c][++age] = savetree;

			if (savetree > 0) {
				que.push_back({ age,{r,c} });

				if (age % 5 == 0)
				{
					for (int i = 0; i < 8; i++)
					{
						int dr = r + d[i][0];
						int dc = c + d[i][1];
						if (dr >= 1 && dr <= n && dc >= 1 && dc <= n)
						{
							if (tcnt[dr][dc][1] == 0)
							{
								que.push_front({ 1, {dr, dc} });
							}
							tcnt[dr][dc][1] += savetree;
						}
					}
				}
			}

		}

		for (int i = 1; i <= NMAX; i++) {
			for (int j = 1; j <= NMAX; j++) {
				for (int k = 1; k <= AGEMAX; k++) {
					cnt[i][j][k] = tcnt[i][j][k];
				}
			}
		}
		tree = que;

		//양분을 추가
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] += food[i][j] + dieTree[i][j];
				dieTree[i][j] = 0;
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= NMAX; i++) {
		for (int j = 1; j <= NMAX; j++) {
			for (int k = 1; k <= AGEMAX; k++) {
				result += cnt[i][j][k];
			}
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