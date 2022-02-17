/*
16639번: 괄호 추가하기 3
https://www.acmicpc.net/problem/16639
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int len;
string str;

void initialize()
{
	cin >> len >> str;
}

long long back_tracking(vector<long long>& num, vector<char>& operator_index, vector<bool>& used, vector<int>& seq) {
	if (seq.size() == operator_index.size()) {
		vector<long long> temp = num;
		for (int i = 0; i < seq.size(); i++) {
			char cur_char = operator_index[seq[i]];
			int index1 = seq[i], index2 = index1 + 1;

			while (temp[index2] == LLONG_MIN)	index2++;

			switch (cur_char) {
			case '+':
				temp[index2] = temp[index1] + temp[index2];
				break;
			case '*':
				temp[index2] = temp[index1] * temp[index2];
				break;
			case '-':
				temp[index2] = temp[index1] - temp[index2];
				break;
			}
			temp[index1] = LLONG_MIN;
		}
		return temp[operator_index.size()];
	}

	long long result = LLONG_MIN;
	for (int i = 0; i < operator_index.size(); i++) {
		if (used[i]) continue;

		used[i] = true;
		seq.push_back(i);
		result = max(result, back_tracking(num, operator_index, used, seq));
		seq.pop_back();
		used[i] = false;
	}
	return result;
}

void solve()
{
	vector<long long> num;
	int last_num = 0;
	vector<char> operator_index;
	for (int i = 1; i < len - 1; i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
			num.push_back((long long)stoi(str.substr(last_num, i - last_num)));
			operator_index.push_back(str[i]);
			last_num = i + 1;
		}
	}
	num.push_back(stoi(str.substr(last_num, len - last_num)));

	vector<int> seq;
	vector<bool> used(operator_index.size(), false);
	cout << back_tracking(num, operator_index, used, seq);
}

int main()
{
	sync_off;

	initialize();
	solve();

	return 0;
}