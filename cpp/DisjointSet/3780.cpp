/*
3780번: 네트워크 연결
https://www.acmicpc.net/problem/3780
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int findParent(vector<int>& parent, vector<int>& len, int i) {
	if (parent[i] == i)	return i;
	else {
		int next = findParent(parent, len, parent[i]);
		len[i] += len[parent[i]];
		return parent[i] = next;
	}
}

void solve(vector<int>& parent) {
	vector<int> len(parent.size(), 0);
	while (1) {
		char c;
		cin >> c;
		switch (c) {
		case 'E':
			int i;
			cin >> i;
			findParent(parent, len, i);
			cout << len[i] << "\n";
			break;
		case 'I':
			int a, b;
			cin >> a >> b;
			len[a] = abs(a - b) % 1000;
			//여기에 findParent로 찾은 부모 노드를 넣어주게 되면
			//1->2, 3->1의 과정에서 3->2로 가는 비용이 제대로 저장되지 않게 됨.
			//그렇기에 여기에서는 일단 직속 부모 노드만 저장하고 이후 비용을 계산하는 것은 'E'에서 수행
			parent[a] = b;
			break;
		case 'O':
			return;
		}
	}
}

void initialize()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> parent(n+1);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		solve(parent);
	}
}


int main()
{
	sync_off;
	initialize();

	return 0;
}