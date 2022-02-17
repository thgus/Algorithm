/*
20549번: 인덕이의 고민
https://www.acmicpc.net/problem/20549
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 50
#define MMAX 4
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
int knight, bishop, rook;
int startx, starty;
int m;
vector<vector<int>> feed(MAX, vector<int>(MAX, -1));

void initialize()
{
	cin >> n;
	cin >> knight >> bishop >> rook;
	cin >> startx >> starty;
	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		feed[a][b] = i;
	}

}

struct Node {
	int y, x, visit, cost;
	bool operator < (const Node& n) const {
		return cost > n.cost;
	}
};

int kd[8][2] = { {-1,-2},{-1,2},{-2,-1},{-2,1},{1,2},{1,-2},{2,1},{2,-1} };
int bd[4][2] = { {-1,-1},{-1,1},{1,-1},{1,1} };
int rd[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
void solve()
{
	vector<vector<vector<int>>> map((1 << MMAX), vector<vector<int>>(MAX, vector<int>(MAX, 2e9)));
	priority_queue<Node> que;
	int result;
	que.push({ starty,startx,0,0});
	map[0][starty][startx] = 0;

	while (1) {
		auto a = que.top();
		int cury = a.y;   int curx = a.x;   int curvisit = a.visit;   int curcost = a.cost;
		que.pop();

		if (curvisit == (1 << m) - 1) {
			cout << curcost;
			break;
		}

		if (map[curvisit][cury][curx] < curcost) {
			continue;
		}

		//나이트
		for (int i = 0; i < 8; i++) {
			int nexty = cury + kd[i][0];
			int nextx = curx + kd[i][1];

			int nextvisit = curvisit;
			int nextcost = curcost + knight;
			if (nexty >= 0 && nextx >= 0 && nexty < n && nextx < n) {
				if (feed[nexty][nextx] >= 0) {
					nextvisit |= (1 << feed[nexty][nextx]);
				}
				if (map[nextvisit][nexty][nextx] > nextcost) {
					map[nextvisit][nexty][nextx] = nextcost;
					que.push({ nexty,nextx,nextvisit,nextcost});
				}
			}
		}

		//비숍
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < n; j++) {
				int nexty = cury + bd[i][0] * j;
				int nextx = curx + bd[i][1] * j;

				int nextvisit = curvisit;
				int nextcost = curcost + bishop;

				if (nexty >= 0 && nextx >= 0 && nexty < n && nextx < n) {
					if (feed[nexty][nextx] >= 0) {
						nextvisit |= (1 << feed[nexty][nextx]);
					}

					if (map[nextvisit][nexty][nextx] > nextcost) {
						map[nextvisit][nexty][nextx] = nextcost;
						que.push({ nexty,nextx,nextvisit,nextcost});
					}
				}
			}
		}

		//룩
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < n; j++) {
				int nexty = cury + rd[i][0] * j;
				int nextx = curx + rd[i][1] * j;

				int nextvisit = curvisit;
				int nextcost = curcost + rook;

				if (nexty >= 0 && nextx >= 0 && nexty < n && nextx < n) {
					if (feed[nexty][nextx] >= 0) {
						nextvisit |= (1 << feed[nexty][nextx]);
					}

					if (map[nextvisit][nexty][nextx] > nextcost) {
						map[nextvisit][nexty][nextx] = nextcost;
						que.push({ nexty,nextx,nextvisit,nextcost});
					}
				}
			}
		}

	}
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}