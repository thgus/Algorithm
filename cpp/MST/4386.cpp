/*
4386번: 별자리 만들기
https://www.acmicpc.net/problem/4386
*/

#include<iostream>
#include<vector>
#include <queue>
#include <cmath>

#define MAX 100
#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
vector<pair<double, double>> vec(MAX);

void initialize() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}
}

vector<int> parent(MAX);
int findParent(int i) {
	if (parent[i] == i) {
		return i;
	}
	else {
		return parent[i] = findParent(parent[i]);
	}
}

void solve() {
	double x1, y1;
	double x2, y2;
	priority_queue<pair<double, pair<int, int>>,vector<pair<double, pair<int, int>>>,greater<pair<double, pair<int, int>>>> que;

	for (int i = 0; i < n; i++) {
		x1 = vec[i].first;
		y1 = vec[i].second;
		for (int j = 0; j < n; j++)
		{
			if (i == j) {
				continue;
			}
			x2 = vec[j].first;
			y2 = vec[j].second;
			que.push({ sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)),{i,j} });
		}
	}

	int line = 0;
	double totalDistance = 0;

	double distance;
	int index1, index2;

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	while (line < n - 1) {
		distance = que.top().first;
		index1 = que.top().second.first;
		index2 = que.top().second.second;
		que.pop();

		if (findParent(index1) != findParent(index2)) {
			totalDistance += distance;
			line++;
			parent[findParent(index1)] = findParent(index2);
		}
	}

	cout << totalDistance;

}

int main() {
	//sync_off;
	initialize();
	solve();

	return 0;
}