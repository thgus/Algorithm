/*
1700번: 멀티탭 스케줄링
https://www.acmicpc.net/problem/1700
*/

#include <iostream>
#include <vector>
#include <queue>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, k;
vector<queue<int>> i_seq;
vector<int> seq;

void initialize()
{
	cin >> n >> k;
	i_seq.resize(k);

	int cur;
	for (int i = 0; i < k; i++) {
		cin >> cur;
		seq.push_back(cur - 1);
		i_seq[cur - 1].push(i);
	}
}

void solve()
{
	vector<bool> isPlugged(k, false);
	int plug_num = 0;

	int cur;
	int remove = 0;
	for (int i = 0; i < k; i++) {
		cur = seq[i];
		i_seq[cur].pop();
		if (isPlugged[cur])  continue;

		if (plug_num == n) {
			int next_seq = -1;
			int next;
			for (int j = 0; j < k; j++) {
				if (!isPlugged[j])   continue;
				if (i_seq[j].empty()) {
					next_seq = k;
					next = j;
				}
				else if (next_seq < i_seq[j].front()) {
					next_seq = i_seq[j].front();
					next = j;
				}
			}
			isPlugged[next] = false;
			remove++;
		}
		else {
			plug_num++;
		}

		isPlugged[cur] = true;
	}

	cout << remove;
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}