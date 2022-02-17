/*
1967번: 트리의 지름
https://www.acmicpc.net/problem/1967
*/

#include<iostream>
#include<algorithm>
#include<vector>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector <vector<pair<short, short>>> vec(10001, vector<pair<short, short>>(0));
vector<vector<short>> rad(10001,vector<short>(0));
int m = 0;

int dfs(int _s) {
	if (vec[_s].size() == 0) {	//간선이 없을 때
		return 0;
	}
	else if (vec[_s].size() == 1) {	//간선이 하나일 때
		return dfs(vec[_s][0].first) + vec[_s][0].second;
	}
	else {
		for (int i = 0; i < vec[_s].size(); i++) { //간선이 두개 이상 => 반지름의 경우의 수가 될 수 있음.
			rad[_s].push_back(dfs(vec[_s][i].first) + vec[_s][i].second);
		}
		sort(rad[_s].begin(), rad[_s].end(),greater<int>());
		
		//cout << _s << " " << rad[_s][0] << " " << rad[_s][1] << "\n";

		int temp = (int)rad[_s][0] + (int)rad[_s][1];
		if (m < temp) {
			m = temp;
		}

		return rad[_s][0];
	}
}

int main() {
	sync_off;
	int n;
	cin >> n;

	int s, e, d;
	for (int i = 1; i < n; i++) {
		cin >> s >> e >> d;
		vec[s].push_back({ e,d });
	}

	int temp = dfs(1);

	//위의 dfs는 자식이 2개일 경우에만 m값을 갱신해주는데
	//리프노드의 자식이 1개일 경우엔 리프노드와 관련된 간선의 가중치는 적용이 되지 않으므로
	//한번 비교해줌.
	if (temp > m) {
		m = temp;
	}
	cout << m;

	return 0;
}