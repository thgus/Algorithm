/*
1197번: 최소 스패닝 트리
https://www.acmicpc.net/problem/1197

크루스칼 알고리즘
https://www.crocus.co.kr/733
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int v, e;
vector<vector<int>> stree(10001, vector<int>(0));

bool isCycle(int f) {
	vector<bool> isVisited(10001, false);
	queue<int> que;
	que.push(f);
	isVisited[f] = true;
	int lastIndex = f;

	int temp;
	while (!que.empty()) {
		temp = que.front();
		que.pop();
		//cout<<"last: "<<lastIndex<<"\n";
		for (int i = 0; i < stree[temp].size(); i++) {
			if (stree[temp][i] != lastIndex) {
				//cout<<stree[temp][i]<<" ";
				if (isVisited[stree[temp][i]]) {
					return false;
				}
				que.push(stree[temp][i]);
				isVisited[stree[temp][i]] = true;
			}
		}
		lastIndex = temp;
		//cout<<"\n";
	}

	return true;
}

int main() {
	cin >> v >> e;

	//first:가중치. second:정점 
	vector<pair<int, pair<int, int>>> vec;
	//a,b 정점
	int a, b, c;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		vec.push_back({ c,{a,b} });
	}
	sort(vec.begin(), vec.end());

	int t = 0;
	long long weight = 0;

	//int temp;
	for (int i = 0; i < e; i++) {
		stree[vec[i].second.second].push_back(vec[i].second.first);
		stree[vec[i].second.first].push_back(vec[i].second.second);

		cout << vec[i].second.first << " " << vec[i].second.second << "\n";

		if (!isCycle(vec[i].second.second)) {
			stree[vec[i].second.second].pop_back();
			stree[vec[i].second.first].pop_back();
			continue;
		}
		cout << vec[i].first << "\n";
		weight += vec[i].first;
		t++;

		if (t == v - 1) {
			break;
		}
	}
	cout << weight;

	return 0;
}