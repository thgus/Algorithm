/*
1102번: 발전소
https://www.acmicpc.net/problem/1102
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> cost;
string power_plant;
int p;

void initialize()
{
	cin >> n;
	cost.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	cin >> power_plant;
	cin >> p;
}

void solve()
{
	vector<int> dp(1 << n, 1e8);

	int key = 0;
	for (int i = 0; i < power_plant.size(); i++) {
		if (power_plant[i] == 'Y') {
			key |= (1 << i);
		}
	}
    dp[key]=0;

	priority_queue<pair<int, int>> que;
	que.push({ 0,key });

	int result=1e9;
	while (!que.empty()) {
		int cur_cost = -que.top().first;
		int cur_key = que.top().second;
		que.pop();

		if (dp[cur_key] != cur_cost)	continue;

		vector<int> get_key;
		vector<int> n_get_key;
		for (int i = 0; i < n; i++) {
			if (~cur_key & (1 << i)) {
				n_get_key.push_back(i);
			}
			else {
				get_key.push_back(i);
			}
		}

		if (get_key.size() >= p) {
			result=cur_cost;
			break;
		}

		for (int i = 0; i < get_key.size(); i++) {
			for (int j = 0; j < n_get_key.size(); j++) {
				int get_key_index = get_key[i];
				int n_get_key_index = n_get_key[j];

				int next_cost = cur_cost + cost[get_key_index][n_get_key_index];
				int next_key = cur_key|(1 << n_get_key_index);
				if (dp[next_key] > next_cost) {
					dp[next_key] = next_cost;
					que.push({ -next_cost,next_key });
				}
			}
		}
	}

	if(result==1e9){
		cout << "-1";
	}
	else{
		cout<<result;
	}
}


int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}