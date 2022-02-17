/*
19240번: 장난감 동맹군
https://www.acmicpc.net/problem/19240
*/

#include <iostream>
#include <vector>
#include <ctime>

#define MAX 300010
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int t;      //testcase
int n, m;    //n: 장난감 개수, m: 동맹이 될 수 없는 장난감 쌍

bool dfs(vector<int> *route, vector<int>& group, int num) {
	int nctn = group[num] + 1;

	for (int i = 0; i < route[num].size(); i++) {
		int next = route[num][i];

		if (group[next] == -1) {
			group[next] = nctn;
			if (!dfs(route, group, next)) {
				return false;
			}
		}
		else if (group[next] % 2 != nctn % 2) {
			return false;
		}
	}

	return true;
}

void solve()
{
	
	cin >> t;
	while (t--) {
		cin >> n >> m;

		
		vector<int> group(n, -1);
		vector<int> route[MAX];
		int x, y;

		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			route[x-1].push_back(y-1);
			route[y-1].push_back(x-1);
		}

		bool isYes = true;
		for (int i = 0; i < n; i++) {
			if (group[i] == -1) {
				group[i] = 0;
				if (!dfs(route, group, i)) {
					isYes = false;
					break;
				}
			}
		}

		if (isYes) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

}

int main()
{
	sync_off;
	solve();

	return 0;
}