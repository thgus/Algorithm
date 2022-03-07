#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int solve(string str, int k)
{
	if (str.size() == k)	return 0;

	string case1, case2;
	case1 = str.substr(0, k);
	case2 = str.substr(str.length() - k, k);

	int offset = str.length() - k;
	int cnt = 0;
	
	vector<bool> visited(k, false);
	//for (int i = 0; i < offset; i++)
	for (int i = 0; i < k; i++)
	{
		if (visited[i])	continue;

		int index = i;
		vector<int> alphabet('z' - 'a' + 1, 0);
		
		alphabet[case1[i]-'a']++;
		while (1)
		{
			if (index >= k)	break;
			
			visited[index] = true;			
			alphabet[case2[index] - 'a']++;

			index += offset;
		}

		int total_cnt = 0;
		int max_cnt = 0;
		for (int j = 0; j < alphabet.size(); j++)
		{
			total_cnt += alphabet[j];
			max_cnt=max(max_cnt, alphabet[j]);
		}

		cnt += total_cnt - max_cnt;
	}

	return cnt;
}

int main()
{
	string str;
	cin >> str;

	int k;
	cin >> k;

	cout<<solve(str, k);

	return 0;
}