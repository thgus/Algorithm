#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<string.h>

using namespace std;

struct Color
{
	bool isEnd = false;
	map<char,Color> next;
};

struct Name
{
	bool isEnd = false;
	map<char,Name> next;
};

Color color;
Name name;

void initialize()
{
	int n, m;
	cin >> n >> m;

	Color ctemp;
	string str;
	while (n--)
	{
		cin >> str;
		Color *cur = &color;
		for (char c : str)
		{
			auto it = cur->next.find(c);

			if (it == cur->next.end())
			{
				cur->next.insert({ c,ctemp });
			}
			cur = &cur->next[c];
		}
		cur->isEnd = true;
	}

	Name ntemp;
	while (m--)
	{
		cin >> str;
		Name *cur = &name;
		for (int i=str.length()-1;i>=0;i--)
		{
			char c = str[i];

			auto it = cur->next.find(c);
			if (it == cur->next.end())
			{
				cur->next.insert({ c,ntemp });
			}
			cur = &cur->next[c];
		}
		cur->isEnd = true;
	}
}

void solve()
{
	int n;
	cin >> n;

	bool arr[2005];
	string str;
	while (n--)
	{
		cin >> str;

		memset(arr, false, sizeof(bool) * 2005);

		bool isYes = false;
		Color *color_cur = &color;
		for (int i = 0; i < str.length(); i++)
		{
			char c = str[i];

			auto it = color_cur->next.find(c);
			if (it == color_cur->next.end())	break;

			color_cur = &it->second;

			if (color_cur->isEnd)
			{
				arr[i] = true;
			}
		}

		Name *name_cur = &name;
		for (int i = str.length()-1; i > 0; i--)
		{
			char c = str[i];

			auto it = name_cur->next.find(c);
			if (it == name_cur->next.end())	break;

			name_cur = &it->second;

			if (name_cur->isEnd && arr[i - 1])
			{
				isYes = true;
				break;
			}
		}

		if (isYes)	cout << "Yes\n";
		else cout << "No\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();
	solve();

	return 0;
}

