#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

struct Node
{
	int remove = 0;
	int required = 0;
	int isEnd = 0;

	map<char,Node> next;
};
Node root;

int cnt;
void dfs(string str, Node cur)
{
	if (cur.required == 0)
	{
		if(cur.remove>0)	cnt++;
		return;
	}

	if (cur.isEnd != 0)
	{
		cnt++;
	}

	for (auto it = cur.next.begin(); it != cur.next.end(); it++)
	{
		dfs(str+it->first, it->second);
	}
}

void solve()
{
	int n1, n2;
	cin >> n1;

	string str;
	while (n1--)
	{
		cin >> str;

		Node *cur = &root;
		cur->remove++;

		for (char c : str)
		{
			auto it = cur->next.find(c);
			if (it == cur->next.end())
			{
				Node temp;
				cur->next.insert({ c,temp });
				cur = &cur->next[c];
			}
			else
			{
				cur = &it->second;
			}
			cur->remove++;
		}
		cur->isEnd++;
	}

	cin >> n2;
	while (n2--)
	{
		cin >> str;

		Node *cur = &root;
		cur->required++;
		for (char c : str)
		{
			auto it = cur->next.find(c);
			if (it == cur->next.end())
			{
				Node temp;
				cur->next.insert({ c,temp });
				cur = &cur->next[c];
			}
			else
			{
				cur = &it->second;
			}
			cur->required++;
		}
	}

	cnt = 0;
	dfs("",root);
	cout << cnt << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		root.remove = 0;
		root.required = 0;
		root.next.clear();

		solve();
		
	}

	return 0;
}

