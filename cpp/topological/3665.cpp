/*
3665번: 최종 순위
https://www.acmicpc.net/problem/3665
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

void initialize()
{
	int t;
	cin >> t;

	int n, m;
	while (t--) {
		cin >> n;
		vector<pair<int,int>> rank(n + 1);

		int temp;
		for (int i = 1; i <= n; i++) {
			cin >> temp;
			rank[temp] = { i,i };
		}

		cin >> m;
		int a, b;
		while (m--) {
			cin >> a >> b;
			if (rank[a].first > rank[b].first) {
				temp = a;
				a = b;
				b = temp;
			}

			rank[b].second--;
			rank[a].second++;
		}

		vector<int> isVisited(n + 1, 0);
		bool impossible = false;
		for (int i = 1; i <= n; i++) {
			int cur = rank[i].second;
			if (isVisited[cur]) {
				impossible = true;
				break;
			}
			isVisited[cur] = i;
		}

		if (impossible) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			for (int i = 1; i <= n; i++) {
				cout << isVisited[i] << " ";
			}
			cout << "\n";
		}
	}
}

int main()
{
	sync_off;
	initialize();

	return 0;
}