// https://velog.io/@dl-00-e8/BOJ-24552.-%EC%98%AC%EB%B0%94%EB%A5%B8-%EA%B4%84%ED%98%B8
// 와 이런 생각은 또 안해봤네

#include<iostream>
#include<vector>
#include<string>

using namespace std;

string str;

void solve()
{
	int cnt = 0;

	for (int i=0;i<str.size();i++)
	{
		cnt = (str[i] == '(') ? cnt + 1 : cnt - 1;
	}

	int result = 0;
	if (cnt > 0)
	{
		cnt = 0;
		for (int i = 0; i < str.size(); i++)
		{
			cnt = (str[i] == '(') ? cnt + 1 : cnt - 1;
			if (str[i] == '(')	result++;

			if (cnt == 0)	result = 0;
		}
	}
	else
	{
		cnt = 0;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			cnt = (str[i] == '(') ? cnt + 1 : cnt - 1;
			if (str[i] == ')')	result++;

			if (cnt == 0)	result = 0;
		}
	}
	
	cout << result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;

	int strLen = str.size();
	solve();

	return 0;
}

