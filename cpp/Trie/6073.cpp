#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;

struct Node
{
	int cnt = 0;
	int accumulate = 0;
	vector<Node> next;
};

Node trie;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;

		Node *cur = &trie;
		int num;
		while (k--)
		{
			cin >> num;
			
			if (cur->next.size()==0)
			{
				cur->next.resize(2);
			}
			cur = &cur->next[num];
			cur->accumulate++;
		}
		cur->cnt++;
	}

	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;

		int result = 0;
		int num;
		Node *cur = &trie;

		while (k--)
		{
			cin >> num;

			if (cur->next.size() == 0)
			{
				break;
			}
			cur = &cur->next[num];
			result += cur->cnt;
		}
		while (k-->0)	cin >> num;
		
		result -= cur->cnt;
		result += cur->accumulate;

		cout << result << "\n";
	}

	return 0;
}