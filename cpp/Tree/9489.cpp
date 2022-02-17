/*
9489번: 사촌
https://www.acmicpc.net/problem/9489
*/

#include <iostream>
#include <vector>
#include <map>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Node {
	int num;
	int parent;
	vector<int> child;
};

int main()
{
	sync_off;

	int n, k;
	vector<Node> vec;
	while (1) {
		cin >> n >> k;
		if (n == 0 && k == 0)  break;

		vec.clear();

		int cur;
		int cur_parent = -1;
		int pre;
		vector<int> child;

		cin >> cur;
		vec.push_back({ cur,-1,child });
		pre = cur;

		int k_index = 0;
		for (int i = 1; i < n; i++) {
			cin >> cur;

			if (pre + 1 != cur)  cur_parent++;
			vec.push_back({ cur,cur_parent,child });
			vec[cur_parent].child.push_back({ i });

			if (cur == k)    k_index = i;

			pre = cur;
		}

		int parent = vec[k_index].parent;
		if (parent == -1) {
			cout << "0\n";
			continue;
		}
		int pparent = vec[parent].parent;
		if (pparent == -1) {
			cout << "0\n";
			continue;
		}

		int sum = -1 * (vec[parent].child.size());
		for (int cur : vec[pparent].child) {
			sum += vec[cur].child.size();
		}
		cout << sum << "\n";
	}

	return 0;
}