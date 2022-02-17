/*
1933번: 스카이라인
https://www.acmicpc.net/problem/1933
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;

struct Building {
	int x, h;
	bool operator<(Building n) {
		if (x == n.x) {
			return h > n.h;
		}
		return x < n.x;
	}
};

vector<Building> vec;
void initialize()
{
	cin >> n;
	int l, h, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> h >> r;
		vec.push_back({ l,h});
		vec.push_back({ r,-h});
	}
}

void solve()
{
	sort(vec.begin(), vec.end());

	multiset<int> m;

	for (int i = 0; i < vec.size(); i++) {
		int curx = vec[i].x;
		int curh = vec[i].h;
		
		//시작
		if (curh > 0) {
			if (m.empty() || *m.rbegin() < curh) {
				cout << curx << " " << curh << " ";
			}
			m.insert(curh);
		}
		else {	//끝
			int maxh = *m.rbegin();
			auto it = m.find(-curh);
			m.erase(it);

			if (m.empty()) {
				cout << curx << " " << 0 << " ";
			}
			else if (maxh != *m.rbegin()) {
				cout << curx << " " << *m.rbegin() << " ";
			}

		}

	}

}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}