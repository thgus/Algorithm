/*
17472번: 다리 만들기 2
https://www.acmicpc.net/problem/17472
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int r, c;
vector<vector<int>> world;

void initialize()
{
	cin >> r >> c;
	world.resize(r, vector<int>(c));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> world[i][j];
		}
	}
}

int findParent(vector<int>& parent, int n) {
	if (parent[n] == n) {
		return n;
	}
	else {
		return parent[n] = findParent(parent, parent[n]);
	}
}

void solve()
{
	vector<vector<bool>> isVisited(r, vector<bool>(c, false));
	queue<pair<int, int>> que;
	map<pair<int, int>, int> m;
	int d[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

	//섬 식별
	int index = -1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (isVisited[i][j] || world[i][j] == 0) {
				continue;
			}

			index++;
			que.push({ i,j });
			while (!que.empty()) {
				int cury = que.front().first;
				int curx = que.front().second;
				que.pop();

				if (isVisited[cury][curx])   continue;
				isVisited[cury][curx] = true;
				m.insert({ {cury,curx},index });

				for (int i = 0; i < 4; i++) {
					int nexty = cury + d[i][0];
					int nextx = curx + d[i][1];

					if (nexty >= 0 && nexty < r && nextx >= 0 && nextx < c && !isVisited[nexty][nextx]) {
						if (!isVisited[nexty][nextx] && world[nexty][nextx] == 1)
							que.push({ nexty,nextx });
					}
				}

			}
		}
	}

	//섬들간 거리 계산
	vector<vector<int>> distance(index + 1, vector<int>(index + 1, 1e9));
	for (int i = 0; i < index + 1; i++) {
		distance[i][i] = 0;
	}

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (world[y][x] == 0)  continue;

			int startIndex = m.find({ y,x })->second;

			for (int i = 0; i < 4; i++) {
				int cury = y;    int curx = x;
				int curDistance = -1;

				while (1) {
					cury += d[i][0];
					curx += d[i][1];
					curDistance++;

					if (!(cury >= 0 && cury < r && curx >= 0 && curx < c)) {
						break;
					}

					if (world[cury][curx] == 1) {
						int endIndex = m.find({ cury,curx })->second;
						if (startIndex != endIndex && curDistance > 1) {
							distance[startIndex][endIndex] = min(distance[startIndex][endIndex], curDistance);
							distance[endIndex][startIndex] = distance[startIndex][endIndex];
						}
						break;
					}
				}

			}
		}
	}

	//최단 다리 놓기
	priority_queue<pair<int, pair<int, int>>> pq;
	vector<int> parent(index + 1);

	for (int i = 0; i <= index; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || distance[i][j] == 1e9)	continue;
			pq.push({ -distance[i][j],{i,j} });
		}
		parent[i] = i;
	}

	int totalDistance = 0;
	int totalBridge = 0;
	while (!pq.empty()) {
		int curDistance = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();

		int ap = findParent(parent,a);
		int bp = findParent(parent,b);
		if (ap == bp)	continue;

		parent[ap] = bp;
		totalBridge++;
		totalDistance += curDistance;

		if (totalBridge == index)	break;
	}

	if (totalBridge != index) {
		cout << "-1";
	}
	else {
		cout << totalDistance;
	}
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}