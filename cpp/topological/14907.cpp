/*
14907번: 프로젝트 스케줄링
https://www.acmicpc.net/problem/14907
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

#define MAX 26
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<int> time(MAX, 0);
vector<int> topology(MAX, -1);
vector<vector<int>> next_flow(MAX);

void initialize()
{
	char c;
	while (1) {
		cin >> c;
		if (cin.eof())	break;

		string str;
		getline(cin, str);

		istringstream ss(str);
		string stringBuffer;
		vector<string> x;
		x.clear();

		while (getline(ss, stringBuffer, ' ')) {
			x.push_back(stringBuffer);
		}

		int cur_num = c - 'A';

		int n = atoi(x[1].c_str());
		time[cur_num] = n;

		if (x.size() == 3) {
			string pre = x[2];
			topology[cur_num] = pre.size();

			for (int i = 0; i < pre.size(); i++) {
				int next_num = pre[i] - 'A';
				next_flow[next_num].push_back(cur_num);
			}
		}
		else {
			topology[cur_num] = 0;
		}

	}
}

void solve()
{
	queue<int> que;
	vector<int> spend_time(MAX, 0);

	for (int i = 0; i < MAX; i++) {
		if (topology[i] == 0) {
			topology[i] = -1;
			spend_time[i] = time[i];
			que.push({i});
		}
	}

	int  result = 0;

	while (!que.empty()) {
		int cur_num = que.front();
		que.pop();

		if (next_flow[cur_num].size() == 0) {
			result = max(result, spend_time[cur_num]);
		}

		for (int i = 0; i < next_flow[cur_num].size(); i++) {
			int next_num = next_flow[cur_num][i];
			spend_time[next_num] = max(spend_time[next_num], spend_time[cur_num] + time[next_num]);

			if (--topology[next_num] == 0) {
				que.push(next_num);
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