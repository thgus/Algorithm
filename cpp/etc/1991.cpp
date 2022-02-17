/*
1991번: 트리 순회
https://www.acmicpc.net/problem/1991
*/

#include<iostream>

#include<algorithm>
#include<vector>

#define sync_off ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<pair<char, pair<char, char>>> vec(26);

void preorder(char p) {
	char c1, c2;
	for (auto it = vec.begin(); it != vec.end(); it++) {
		if (it->first == p) {
			c1 = it->second.first;
			c2 = it->second.second;
			cout << p;
			if (c1 != '.') {
				preorder(c1);
			}
			if (c2 != '.') {
				preorder(c2);
			}
		}
	}
}

void inorder(char p) {
	char c1, c2;
	for (auto it = vec.begin(); it != vec.end(); it++) {
		if (it->first == p) {
			c1 = it->second.first;
			c2 = it->second.second;
			if (c1 != '.') {
				inorder(c1);
			}
			cout << p;
			if (c2 != '.') {
				inorder(c2);
			}
		}
	}
}

void postorder(char p) {
	char c1, c2;
	for (auto it = vec.begin(); it != vec.end(); it++) {
		if (it->first == p) {
			c1 = it->second.first;
			c2 = it->second.second;
			if (c1 != '.') {
				postorder(c1);
			}
			if (c2 != '.') {
				postorder(c2);
			}
			cout << p;
		}
	}
}

int main() {
	sync_off;

	int n;
	cin >> n;
	char p, c1, c2;
	for (int i = 0; i < n; i++) {
		cin >> p >> c1 >> c2;
		vec[i] = make_pair(p, make_pair(c1, c2));
	}
	preorder(vec[0].first);
	cout << "\n";
	inorder(vec[0].first);
	cout << "\n";
	postorder(vec[0].first);

	return 0;
}