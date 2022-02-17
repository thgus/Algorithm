/*
12015번: 가장 긴 증가하는 부분 수열 2
https://www.acmicpc.net/problem/12015
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;
vector<int> vec;

void initialize()
{
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
}

void solve()
{
	vector<int> seq;
	vector<int> index;
	vector<int> route(n);

	seq.push_back(vec[0]);
	index.push_back(0);
	route[0] = -1;
	for (int i = 1; i < n; i++) {
		if (seq.back() < vec[i]) {
			seq.push_back(vec[i]);
			route[i] = index.back();
			index.push_back(i);
		}
		else {
			int cur = lower_bound(seq.begin(), seq.end(), vec[i]) - seq.begin();
			seq[cur] = vec[i];
			index[cur] = i;

			if (cur == 0) {
				route[i] = -1;
			}
			else {
				route[i] = index[cur - 1];
			}
		}
	}

	cout << seq.size();

	/*
	stack<int> result;
	int cur = index[index.size() - 1];
	while (1) {
		result.push(vec[cur]);
		cur = route[cur];
		if (cur == -1) break;
	}

	cout << result.size() << "\n";
	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
	*/
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}