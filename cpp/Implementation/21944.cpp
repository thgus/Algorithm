/*
21944번: 문제 추천 시스템 Version 2
https://www.acmicpc.net/problem/21944
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct Node {
	int p, l;

	bool operator<(const Node n) const {
		if (l == n.l) {
			return p < n.p;
		}
		return l < n.l;
	}
};

map<int, set<Node>> list;
set<Node> all_list;
map<int, pair<int,int>> q_num;

void add(int p, int l, int g) {
	all_list.insert({ p,l });
	q_num.insert({ p,{l,g} });
	auto it = list.find(g);
	if (it == list.end()) {
		set<Node> temp;
		temp.insert({ p,l });
		list.insert({ g,temp });
	}
	else {
		it->second.insert({ p,l });
	}
}

void recommend1(int g, int x) {
	set<Node>& cur = list.find(g)->second;
	if (x == 1) {
		cout << cur.rbegin()->p << "\n";
	}
	else if (x == -1) {
		cout << cur.begin()->p << "\n";
	}
}

void recommend2(int x) {
	if (x == 1) {
		cout << all_list.rbegin()->p << "\n";
	}
	else if (x == -1) {
		cout << all_list.begin()->p << "\n";
	}
}

void recommend3(int x, int l) {
	if (all_list.size() == 0) {
		cout << "-1";
		return;
	}

	auto it = all_list.lower_bound({ 0,l });
	if (x == 1) {
		if (it == all_list.end()) {
			cout << "-1\n";
		}
		else {
			cout << it->p << "\n";
		}
	}
	else if (x == -1) {
		if (it == all_list.begin()) {
			cout << "-1\n";
		}
		else {
			it--;
			cout << it->p << "\n";
		}

	}
}

void solved(int p) {
	auto it = q_num.find(p);
	int tl = it->second.first;
	int tg = it->second.second;

	all_list.erase({ p,tl });
	
	auto it2 = list.find(tg);
	it2->second.erase({ p,tl });

	q_num.erase(p);
}

int main()
{
	sync_off;
	int n;
	cin >> n;

	int p, l, g;
	while (n--) {
		cin >> p >> l >> g;
		add(p, l, g);
	}
	cin >> n;

	int x;
	string str;
	while (n--) {
		cin >> str;
		if (str == "recommend") {
			cin >> g >> x;
			recommend1(g, x);
		}
		else if (str == "recommend2") {
			cin >> x;
			recommend2(x);
		}
		else if (str == "recommend3") {
			cin >> x >> l;
			recommend3(x, l);
		}
		else if (str == "add") {
			cin >> p >> l >> g;
			add(p, l, g);
		}
		else if (str == "solved") {
			cin >> p;
			solved(p);
		}
	}

	return 0;
}