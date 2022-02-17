/*
1197번: 최소 스패닝 트리
https://www.acmicpc.net/problem/1197

크루스칼 알고리즘
https://www.crocus.co.kr/733
union-find
https://chanhuiseok.github.io/posts/algo-33/

프림알고리즘은 나중에
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//first:가중치. second:정점 
vector<pair<int, pair<int, int>>> vec;
int v, e;

vector<int> parent(10001);

int findParent(int n) {
	if (n == parent[n]) return n;
	else {
		return parent[n] = findParent(parent[n]);
	}
}

void unionNodes(int a, int b) {
	//a의 부모의 부모가 b의 부모로 가리키게 함으로써 a와 b가 같은 집합임을 연결
	parent[findParent(a)] = findParent(b);
}

int main() {
	cin >> v >> e;

	//a,b 정점
	int a, b, c;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		vec.push_back({ c,{a,b} });
	}
	sort(vec.begin(), vec.end());

	int t = 0;
	long long weight = 0;
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	
	int node1, node2;
	int parent1, parent2;
	for (int i = 0; i < e; i++) {
		node1 = vec[i].second.first;
		node2 = vec[i].second.second;

		//같은 부모를 가지고 있을때 간선을 이으면 순환하게됨
		if (findParent(node1) == findParent(node2)) {
			continue;
		}
		unionNodes(node1, node2);
		weight += vec[i].first;
	}
	cout << weight;

	return 0;
}