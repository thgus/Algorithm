/*
4195번: 친구 네트워크
https://www.acmicpc.net/problem/4195
*/

#include <iostream>
#include <vector>
#include <map>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int findParent(vector<int>& p, int i) {
	if (p[i] == i) {
		return i;
	}
	else {
		return p[i] = findParent(p, p[i]);
	}
}

void printFrendNum(vector<int> frendNum) {
	for (int i = 0; i < frendNum.size(); i++) {
		cout << frendNum[i] << " ";
	}
	cout << "\n";
}

void solve()
{
	int t;
	cin >> t;

	int a, b;
	while (t--) {
		int n;
		cin >> n;

		if (n == 0)    continue;

		map<string, int> m;
		vector<int> frendNum;
		vector<int> parent;
		string str[2];
		int num[2];

		int peopleNum = 0;
		
		for (int i = 0; i < n; i++) {
			cin >> str[0] >> str[1];

			for (int i = 0; i < 2; i++) {
				auto it = m.find(str[i]);
				if (it == m.end()) {
					parent.push_back(peopleNum);
					frendNum.push_back(1);
					m.insert({ str[i],peopleNum });
					num[i] = peopleNum;
					
					peopleNum++;
				}
				else {
					num[i] = it->second;
				}
			}

			int ap = findParent(parent, num[0]);
			int bp = findParent(parent, num[1]);

			if (ap > bp) {
				int temp = ap;
				ap = bp;
				bp = temp;
			}

			if (ap != bp) {
				frendNum[ap] += frendNum[bp];
				parent[bp] = ap;
			}

			cout << frendNum[ap] << "\n";
		}
	}
}

int main()
{
	sync_off;
	solve();

	return 0;
}