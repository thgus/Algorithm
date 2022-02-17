/*
16934번: 게임 닉네임
https://www.acmicpc.net/problem/16934
*/

#include <iostream>
#include <vector>
#include <string>

#define len 26
#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n;

struct TRIE
{
	int cnt=0;
	vector<TRIE*> next;
};

TRIE* root = new TRIE;

string check_str(string str)
{
	TRIE* cur = root;

	bool flag = false;
	string result = "";

	for (char c : str)
	{
		int index = c - 'a';
		
		if (!flag)	
			result += c;

		if (cur->next[index] == NULL)
		{
			// 분기 추가
			cur->next[index] = new TRIE;

			vector<TRIE*> temp(len, NULL);
			cur->next[index]->next = temp;

			flag = true;
		}

		cur = cur->next[index];
	}

	cur->cnt++;
	if (!flag && cur->cnt>1 )
	{
		result += to_string(cur->cnt);
	}

	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);

	sync_off;

	cin >> n;
	vector<TRIE*> temp(len, NULL);
	root->next = temp;

	string str;
	while (n--)
	{
		cin >> str;
		cout << check_str(str) << "\n";
	}

	return 0;
}