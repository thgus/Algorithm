/*
3584번: 가장 가까운 공통 조상
https://www.acmicpc.net/problem/3584
*/

#include <iostream>
#include <vector>
#include <stack>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;


int main()
{
	sync_off;
    
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> parent(n, -1);
		int a, b;
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			parent[b - 1] = a - 1;
		}

		cin >> a >> b;

		stack<int> seq1;
		int cur = a - 1;
		while (cur != -1) {
			seq1.push(cur);
			cur = parent[cur];
		}

		stack<int> seq2;
		cur = b - 1;
		while (cur != -1) {
			seq2.push(cur);
			cur = parent[cur];
		}

		int num = seq1.top();
		while (seq1.top() == seq2.top()) {
			num = seq1.top();
			seq1.pop();
			seq2.pop();

			if (seq1.empty())	break;
			if (seq2.empty())	break;
		}

		cout << num + 1 << "\n";
	}

	return 0;
}