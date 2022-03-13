
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>

using namespace std;

struct Node
{
	bool isEnd = false;
	map<char,Node> next_alphabet;
};

void solve(int n, vector<string> vec)
{
	Node root;
	Node temp;

	for (string str : vec)
	{
		Node *cur = &root;

		for (char c : str)
		{
			auto ret= cur->next_alphabet.insert({ c,temp });
			cur = &cur->next_alphabet[c];
		}
		cur->isEnd=true;
	}


	long long result = 0;
	for (string str : vec)
	{	
		int cnt = (root.next_alphabet.size() == 1) ? 1 : 0;
		Node *cur = &root;

		for (int i=0;i<str.length();i++)
		{
			char c = str[i];

			if (cur->next_alphabet.size() > 1 || cur->isEnd ) 
			{
				cnt++;
			}

			cur = &cur->next_alphabet[c];
		}

		result += cnt;
	}

	printf("%.2f\n", (double)result / n);
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int n;

	while (cin>>n)
	{
		vector<string> vec(n);

		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
		}

		solve(n,vec);
	}

	return 0;
}

