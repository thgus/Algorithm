/*
21776번: 가희와 읽기 쓰기 놀이
https://www.acmicpc.net/problem/21776
*/

#include <iostream>
#include <vector>
#include <set>
#include <string>

#define sync_off                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

int n, c;
set<string> result;

vector<vector<int>> own;
vector<string> card;

vector<int> order;

string go(string source, int cnum)
{
	string str = card[cnum];
	str += ',';

	int index = 0;
	while (1)
	{
		int nindex = str.find(',', index);
		if (nindex == -1)  break;

		string cur = str.substr(index, nindex - index);

		int cindex = cur.find(" ") + 1;
		string c = cur.substr(cindex, nindex - cindex);
		if (cur.find("ADD", 0) == 0)
		{
			source += c;
		}
		else if (cur.find("DEL", 0) == 0)
		{
			int cindex = stoi(c);
			if (source.size() <= cindex)  return "ERROR";

			string a = source.substr(0, cindex);
			string b = source.substr(cindex + 1, source.size() - cindex);

			if (cindex == 0)   source = b;
			else if (cindex == source.size() - 1)    source = a;
			else    source = a + b;
		}

		index = nindex + 1;
	}

	return source;
}

void dfs(string str, int cnt)
{
	if (cnt == c)
	{
		if (str == "") str = "EMPTY";

		result.insert(str);
		return;
	}

	for (int i = 0; i < own.size(); i++)
	{
		if (order[i] == own[i].size()) continue;

		string r = go(str, own[i][order[i]]);
		if (r == "ERROR")
		{
			result.insert(r);
			continue;
		}

		order[i]++;
		dfs(r, cnt + 1);
		order[i]--;
	}
}

void solve()
{
	dfs("", 0);

	for (auto it = result.begin(); it != result.end(); it++)
	{
		cout << (*it) << "\n";
	}
}

int main()
{
	sync_off;

	cin >> n >> c;

	own.resize(n);
	order.resize(n, 0);

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		while (a--)
		{
			cin >> b;
			own[i].push_back(b-1);
		}
	}

	string str;
	getline(cin, str);

	for (int i = 0; i < c; i++)
	{
		getline(cin, str);
		card.push_back(str);
	}

	solve();

	return 0;
}