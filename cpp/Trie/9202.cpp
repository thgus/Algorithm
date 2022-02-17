/*
9202번: Boggle
https://www.acmicpc.net/problem/9202
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<string> vec;

struct TRIE {
	TRIE* node[26];
	TRIE() {
		for (int i = 0; i < 26; i++) {
			node[i] = NULL;
		}
	}
	~TRIE() {
		for (int i = 0; i < 26; i++) {
			if (node[i] != NULL) {
				delete this->node[i];
			}
		}
	}
};

void dfs(vector<vector<char>>& map, vector<vector<bool>>& isVisited, TRIE* curTrie, int y, int x, int len) {
	if (len >= 8) {
		return;
	}
	int d[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1} };

	for (int i = 0; i < 8; i++) {
		int nexty = y + d[i][0];
		int nextx = x + d[i][1];
		if (nexty >= 0 && nextx >= 0 && nexty < 4 && nextx < 4 && !isVisited[nexty][nextx]) {
			int nextChar = map[nexty][nextx] - 'A';
			if (curTrie->node[nextChar] == NULL) {
				curTrie->node[nextChar] = new TRIE;
			}
			TRIE* next = curTrie->node[nextChar];

			isVisited[nexty][nextx] = true;
			dfs(map, isVisited, next, nexty, nextx, len + 1);
			isVisited[nexty][nextx] = false;
		}
	}
}

TRIE* root;
tuple<int, string, int> solve(vector<vector<char>> & map)
{
	int totalScore = 0;
	string rstr = "";
	int findStr = 0;

	root = new TRIE;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			vector<vector<bool>> isVisited(4, vector<bool>(4, false));
			isVisited[i][j] = true;
			int curIndex = map[i][j] - 'A';
			if (root->node[curIndex] == NULL) {
				root->node[curIndex] = new TRIE;
			}
			dfs(map, isVisited, root->node[curIndex], i, j, 1);
		}
	}

	int score[9] = { 0,0,0,1,1,2,3,5,11 };
	for (int i = 0; i < vec.size(); i++) {
		string curstr = vec[i];
		TRIE* cur = root;

		bool isExist = true;
		for (int j = 0; j < curstr.size(); j++) {
			int curIndex = curstr[j] - 'A';
			if (cur->node[curIndex] != NULL) {
				cur = cur->node[curIndex];
			}
			else {
				isExist = false;
				break;
			}
		}

		if (isExist) {
			totalScore += score[curstr.size()];
			rstr = curstr;
			findStr++;
		}
	}
	delete root;
	return { totalScore,rstr,findStr };
}

bool comp(string s1, string s2) {
	if (s1.size() == s2.size()) {
		return s1 > s2;
	}
	return s1.size() < s2.size();
}

void initialize()
{
	int w;
	cin >> w;
	string str;
	while (w--) {
		cin >> str;
		vec.push_back(str);
	}

	sort(vec.begin(), vec.end(), comp);

	int b;
	cin >> b;
	while (b--) {
		vector<vector<char>> map(4, vector<char>(4));
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}
		tuple<int, string, int> t = solve(map);
		cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
	}

}

int main()
{
	sync_off;
	initialize();

	return 0;
}