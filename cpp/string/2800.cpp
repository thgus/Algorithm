/*
2800번: 괄호 제거
https://www.acmicpc.net/problem/2800
*/

#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

string str;

void initialize()
{
	cin >> str;
}

set<string> result;
vector<pair<int, int>> pair_bracket;
vector<bool> isExist;

void make_str() {
	string temp = "";
	for (int i = 0; i < str.size(); i++) {
		if (isExist[i])	temp += str[i];
	}
	result.insert(temp);
}

void get_str(int index) {
	for (int i = index; i < pair_bracket.size(); i++) {
		int start = pair_bracket[i].first;
		int end = pair_bracket[i].second;
		isExist[start] = false;
		isExist[end] = false;
		make_str();
		get_str(i + 1);
		isExist[start] = true;
		isExist[end] = true;
	}
}

void solve()
{
	stack<int> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else if (str[i] == ')') {
			pair_bracket.push_back({ s.top(),i });
			s.pop();
		}
	}

	isExist.resize(str.size(), true);
	get_str(0);

	for (auto it = result.begin(); it != result.end(); it++) {
		cout << *it << "\n";
	}
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}