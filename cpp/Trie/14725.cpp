/*
14725번: 개미굴
https://www.acmicpc.net/problem/14725
*/

#include <iostream>
#include <vector>
#include <map>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct TRIE {
	map<string,TRIE*> m;
};

int n;
TRIE* root = new TRIE;

void insertTRIE(vector<string> &vec){
	TRIE *cur = root;
	for (int i = 0; i < vec.size(); i++) {
		string curstr = vec[i];
		TRIE* next = new TRIE;
		cur->m.insert({ curstr,next });
		auto it = cur->m.find(curstr);
		cur = it->second;
	}
}

void initialize()
{
	cin >> n;
	int k;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> k;
		vector<string> vec;
		while (k--) {
			cin >> str;
			vec.push_back(str);
			insertTRIE(vec);
		}
	}
}

void printStr(TRIE *t, int l) {
	if (t->m.empty()) {
		return;
	}

	for (auto it = t->m.begin(); it!=t->m.end(); it++) {
		for (int j = 0; j < l; j++) {
			cout << "--";
		}
		cout << it->first << "\n";
		printStr(it->second, l + 1);
	}
}

void solve()
{
	printStr(root, 0);
}

int main()
{
	sync_off;
	initialize();
	solve();

	return 0;
}