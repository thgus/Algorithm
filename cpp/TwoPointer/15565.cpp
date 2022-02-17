/*
15565번: 귀여운 라이언
https://www.acmicpc.net/problem/15565
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int main()
{
	sync_off;
	int k, n;
	cin >> n >> k;

	vector<bool> vec(n);
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec[i] = (temp == 1) ? true : false;
	}

	int lion = (vec[0]) ? 1 : 0;
	int len = 1000001;
	int left, right;
	left = right = 0;

	while (1) {
		int cur_len = right - left + 1;
		if (lion >= k) {
			len = min(len, cur_len);
		}

		if (left == n - 1 && right == n - 1) {
			break;
		}

		if (right == n-1) {
			lion -= (vec[left]) ? 1 : 0;
			left++;
		}
		else if (right == left) {
			right++;
			lion += (vec[right]) ? 1 : 0;
		}
		else if (lion >= k) {
			lion -= (vec[left]) ? 1 : 0;
			left++;
		}
		else {
			right++;
			lion += (vec[right]) ? 1 : 0;
		}
	}

	if (len == 1000001) {
		cout << "-1";
	}
	else {
		cout << len;
	}

	return 0;
}