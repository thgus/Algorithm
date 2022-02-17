/*
3197번: 백조의 호수
https://www.acmicpc.net/problem/3197
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

#define MAX 1500
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r, c;
vector<vector<char>> lake(MAX, vector<char>(MAX));
vector<pair<int, int>> swan;
queue<pair<int, pair<int, int>>> que;
vector<vector<int>> spendTime(MAX, vector<int>(MAX, 0));

void initialize()
{
	cin >> r >> c;

	int wx, wy;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> lake[i][j];

			if (lake[i][j] == 'X') {
				spendTime[i][j] = -1;
			}
			else {
				que.push({ 0,{i,j} });
				if (lake[i][j] == 'L') {
					swan.push_back({ i,j });
					lake[i][j] = '.';
				}
				wx = i;	wy = j;
			}
		}
	}
}

int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1}};
int maxTime = 0;
void lakebfs() {
	while (!que.empty()) {
		int cost = que.front().first;
		int cury = que.front().second.first;
		int curx = que.front().second.second;
		que.pop();

		int nextcost = cost + 1;
		for (int i = 0; i < 4; i++) {
			int nexty = cury + d[i][0];
			int nextx = curx + d[i][1];

			if (nexty >= 0 && nexty < r && nextx >= 0 && nextx < c && spendTime[nexty][nextx]==-1) {
				spendTime[nexty][nextx] = nextcost;
				que.push({ nextcost,{nexty,nextx} });

				maxTime = max(maxTime,nextcost);
			}
		}
	}
}

bool isMeet(int time) {
	queue<pair<int, int>> swanque;
	vector<vector<bool>> isVisited(r, vector<bool>(c, false));
	swanque.push(swan[0]);

	while (!swanque.empty()) {
		int cury = swanque.front().first;
		int curx = swanque.front().second;
		swanque.pop();

		if (make_pair(cury,curx) == swan[1]) {
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nexty = cury + d[i][0];
			int nextx = curx + d[i][1];
			if (nexty >= 0 && nexty < r && nextx >= 0 && nextx < c && !isVisited[nexty][nextx]) {
				isVisited[nexty][nextx] = true;
				if (spendTime[nexty][nextx] <= time) {
					swanque.push({ nexty,nextx });
				}
			}
		}
	}
	return false;
}

int lowerBound(int s, int e) {
	int left = s; int right = e;
	while (left < right) {
		int middle = (left + right) / 2;
		if (!isMeet(middle)) {
			left = middle + 1;
		}
		else {
			right = middle;
		}
	}
	return right;
}

void solve()
{
	lakebfs();
	cout << lowerBound(0, maxTime);
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}