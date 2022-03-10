#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int n;
vector<int> vec;

void initialize()
{
	cin >> n;

	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
}

struct Node
{
	bool isUsed = false;
	vector<Node> next;
};

Node root;
vector<string> result;

string dfs(int goal_len, int cur_len, string str, Node &cur)
{
	if (cur.isUsed)	return "-1";

	if (goal_len == cur_len)
	{
		cur.isUsed = true;
		return str;
	}

	if (cur.next.size() == 0)	cur.next.resize(2);


	string result1 = dfs(goal_len, cur_len + 1, str + "0", cur.next[0]);
	if (result1 != "-1")	return result1;

	string result2 = dfs(goal_len, cur_len + 1, str + "1", cur.next[1]);
	return result2;
}

void solve()
{
	result.resize(n);
	bool isClear = true;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	for (int i = 0; i < n; i++)
	{
		pq.push({ vec[i],i });
	}

	while (!pq.empty())
	{
		int len = pq.top().first;
		int index = pq.top().second;
		pq.pop();

		string output = dfs(len, 0, "", root);
		if (output == "-1")
		{
			isClear = false;
			break;
		}

		result[index]=output;
	}

	if (isClear)
	{
		cout << "1\n";
		for (string str : result)	cout << str << "\n";
	}
	else
	{
		cout << "-1";
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