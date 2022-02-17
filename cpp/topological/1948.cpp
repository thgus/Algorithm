/*
1948번: 임계경로
https://www.acmicpc.net/problem/1948
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
int m;
vector<vector<pair<int, int>>> vec;
vector<int> topology;

int start_station, end_station;

void initialize()
{
	cin >> n;
	cin >> m;

	vec.resize(n);
	topology.resize(n, 0);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		vec[a-1].push_back({ b-1,c });
		topology[b-1]++;
	}
	
	cin >> start_station >> end_station;
}

void solve()
{
	queue<int> que;
	vector<int> spend_time(n, 0);
	vector<vector<int>> slowest_road(n);

	que.push(start_station-1);

	while (!que.empty()) {
		int cur_num = que.front();
		int cur_spend_time = spend_time[cur_num];
		que.pop();

		for (pair<int, int> next : vec[cur_num]) {
			int next_num = next.first;
			int cost = next.second;

			int next_spend_time = spend_time[next_num];
			if (spend_time[next_num]<spend_time[cur_num]+cost) {
				spend_time[next_num] = spend_time[cur_num] + cost;
				slowest_road[next_num].clear();
				slowest_road[next_num].push_back(cur_num);
			}
			else if (spend_time[next_num] == spend_time[cur_num] + cost) {
				slowest_road[next_num].push_back(cur_num);
			}

			if (--topology[next_num] == 0) {
				que.push(next_num);
			}
		}
	}

	int road_num = 0;

	que.push(end_station-1);
	vector<bool> isVisited(m, false);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (isVisited[cur])	continue;
		isVisited[cur] = true;

		for (int next: slowest_road[cur]) {
			road_num++;
			que.push(next);
		}
	}

	cout << spend_time[end_station-1] << "\n" << road_num;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}