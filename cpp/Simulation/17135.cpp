/*
17135번: 캐슬 디펜스
https://www.acmicpc.net/problem/17135
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, m, d;
vector<vector<bool>> map;
int start_remain_enemy = 0;

void initialize()
{
	cin >> n >> m >> d;
	map.resize(n, vector<bool>(m, false));

	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp) {
				start_remain_enemy++;
				map[i][j] = true;
			}
			else {
				map[i][j] = false;
			}
		}
	}
}

// 좌표가 유효하고, 그 좌표에 적이 있는지 확인
bool check_enemy(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m) {
		if (map[y][x]) {
			return true;
		}
	}
	return false;
}

// 1에서 d까지 왼쪽->오른쪽 방향으로 탐색하면서 쏠 수 있는 적 찾기
pair<int, int> find_enemy(int archer) {
	int my = n, mx = m;
	int y;

	for (int len = 1; len <= d; len++) {

		//궁수 기준으로 왼쪽
		y = n - 1;
		for (int left = len - 1; left >= 1; left--) {
			if (check_enemy(y, archer - left)) {
				my = y, mx = archer - left;
				goto b;
			}
			y--;
		}

		//궁수의 x좌표
		if (check_enemy(n - len, archer)) {
			my = n - len, mx = archer;
			goto b;
		}

		// 궁수 기준으로 오른쪽
		y++;
		for (int right = 1; right <= len - 1; right++) {
			if (check_enemy(y, archer + right)) {
				my = y, mx = archer + right;
				goto b;
			}
			y++;
		}
	}

b:
	return { my,mx };
}

void solve()
{
	int max_remove = -1;

	//백트래킹으로 찾아도 될거같긴 한데, 궁수가 3명으로 정해져 있으니까 걍 반복문 써서 품.
	for (int archer1 = 0; archer1 < m - 2; archer1++) {
		for (int archer2 = archer1 + 1; archer2 < m - 1; archer2++) {
			for (int archer3 = archer2 + 1; archer3 < m; archer3++) {
				vector<vector<bool>> save = map;

				int cur_remove = 0;
				int cur_remaind_enemy = start_remain_enemy;

				while (1)
				{
					//적이 없으면 break
					if (cur_remaind_enemy == 0) {
						break;
					}

					// 궁수가 가장 가까운 적을 찾는다.
					queue<pair<int, int>> que;
					que.push(find_enemy(archer1));
					que.push(find_enemy(archer2));
					que.push(find_enemy(archer3));

					// 궁수가 가장 가까운 적을 쏜다.
					while (!que.empty())
					{
						int y = que.front().first;
						int x = que.front().second;
						que.pop();

						// 쏠 수 있는 적이 없는 경우
						if (y == n || x == m)    continue;

						// 여러 궁수가 같은 적을 노렸을 수도 있으므로, 이미 다른 궁수가 쏜 적이면 넘긴다.
						if (map[y][x])
						{
							map[y][x] = false;
							cur_remove++;
							cur_remaind_enemy--;
						}
					}

					//적들이 전진한다.
					//전진 후 성에 도착한 적은 사라진다.
					for (int j = 0; j < m; j++)
					{
						if (map[n - 1][j])
							cur_remaind_enemy--;
					}
					for (int i = n - 2; i >= 0; i--)
					{
						for (int j = 0; j < m; j++)
						{
							map[i + 1][j] = map[i][j];
						}
					}

					//뭔가 여기 코드 맨 처음 말고는 괜히 시간만 더 걸리게 하는 것 같다. 그래도 최대 15번밖에 안돌아가니까 걍 씀
					for (int j = 0; j < m; j++)
					{
						map[0][j] = false;
					}
				}

				if (max_remove < cur_remove)   max_remove = cur_remove;
				map = save;
			}
		}
	}

	cout << max_remove;
}

int main()
{
	sync_off;

	initialize();
	solve();

	return 0;
}